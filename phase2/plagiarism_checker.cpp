#include "plagiarism_checker.hpp"

/*
 * The core idea here is there are two 'kinds' of threads, named workers and submittor.
 * I've kept one submittor thread, two worker threads and one main thread (by default).
 * Submittor's job is to add submissions to the queue, worker's job is to process the submissions.
 * Worker searches through the previous submissions to find possible plagiarisms the current
 * submission has done.
 */

/**
 * @brief Constructor
 */
plagiarism_checker_t::plagiarism_checker_t() : stop(false), max_threads(2) {
    submission_processor_thread = std::thread(&plagiarism_checker_t::submission_processor, this);
    for (size_t i = 0; i < max_threads; ++i) {
        thread_pool.emplace_back(&plagiarism_checker_t::worker_thread, this);
    }
}

/**
 * @brief Alternate constructor
 * storing tokens of each file in a map, remaining same as prev
 */
plagiarism_checker_t::plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>> __submissions)
    : stop(false), max_threads(2) {
    int64_t curr_time = curr_time_millis();
    for (auto& submission : __submissions) {
        submissions_list.emplace_back(curr_time, submission, false);
        tokens_cache[submission->id] = tokenizer_t(submission->codefile).get_tokens();
    }
    submission_processor_thread = std::thread(&plagiarism_checker_t::submission_processor, this);
    for (size_t i = 0; i < max_threads; ++i) {
        thread_pool.emplace_back(&plagiarism_checker_t::worker_thread, this);
    }
}

/**
 * @brief Destructor
 * notifies all threads to stop waiting for and joining submission and worker threads
 */
plagiarism_checker_t::~plagiarism_checker_t() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
        cv.notify_all();
    }
    if (submission_processor_thread.joinable()) {
        submission_processor_thread.join();
    }
    {
        std::unique_lock<std::mutex> lock(tasks_mutex);
        tasks_cv.notify_all();
    }
    for (auto& thread : thread_pool) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

/**
 * @brief Public interface to add submissions
 * This is part of the main assignment, other are helper functions.
 */
void plagiarism_checker_t::add_submission(std::shared_ptr<submission_t> __submission) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        submission_queue.push(__submission);
    }
    cv.notify_one();
}

/**
 * @brief Submitter's function, processes each submission. Maintains
 * submission queue, submission list, updates token cache regularly
 */
void plagiarism_checker_t::submission_processor() {
    while (true) {
        std::shared_ptr<submission_t> submission;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            cv.wait(lock, [this] { return stop || !submission_queue.empty(); });
            if (stop && submission_queue.empty()) {
                break;
            }
            submission = submission_queue.front();
            submission_queue.pop();
        }

        int64_t curr_time = curr_time_millis();
        std::vector<int> curr_tokens = tokenizer_t(submission->codefile).get_tokens();
        int curr_index;
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            submissions_list.emplace_back(curr_time, submission, false);
            tokens_cache[submission->id] = curr_tokens;
            curr_index = submissions_list.size() - 1;
        }

        {
            std::lock_guard<std::mutex> lock(tasks_mutex);
            tasks_queue.push(curr_index);
        }
        tasks_cv.notify_one();
    }
}

/**
 * @brief Worker's function, compares the current submission with all previous
 * submissions uses `compare_submisssions` function. Maintains tasks queue,
 * assigns task index to each task.
 */
void plagiarism_checker_t::worker_thread() {
    while (true) {
        int task_index;
        {
            std::unique_lock<std::mutex> lock(tasks_mutex);
            tasks_cv.wait(lock, [this] { return stop || !tasks_queue.empty(); });
            if (stop && tasks_queue.empty()) {
                break;
            }
            if (!tasks_queue.empty()) {
                task_index = tasks_queue.front();
                tasks_queue.pop();
            } else {
                continue;
            }
        }
        compare_submissions(task_index);
    }
}

/**
 * @brief Compares the current submission with all previous submissions
 * @param curr_index Index of the current submission in the submissions_list
 */
void plagiarism_checker_t::compare_submissions(int curr_index) {
    std::shared_ptr<submission_t> curr_submission;
    std::vector<int> curr_tokens;

    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        int64_t curr_time = std::get<0>(submissions_list[curr_index]);
        curr_submission = std::get<1>(submissions_list[curr_index]);
        curr_tokens = tokens_cache[curr_submission->id];
    }

    int matches_last_second = 0;

    for (int i = 0; i < curr_index; ++i) {
        check_two_submissions(curr_index, i, matches_last_second);
    }

    bool should_flag = false;
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        should_flag = !std::get<2>(submissions_list[curr_index]);
    }

    if (should_flag && matches_last_second >= 20) {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            std::get<2>(submissions_list[curr_index]) = true;
        }

        if (curr_submission->student) {
            curr_submission->student->flag_student(curr_submission);
        }
        if (curr_submission->professor) {
            curr_submission->professor->flag_professor(curr_submission);
        }
    }
}

/**
 * @brief Returns number of exact matches and longest exact match
 */
std::pair<int, int> size_of_match(std::vector<int>& curr_tokens, std::vector<int>& prev_tokens) {
    int num_matches = 0;
    int max_match_length = 0;
    int curr_size = curr_tokens.size();
    int prev_size = prev_tokens.size();
    if (curr_size == 0 || prev_size == 0) {
        return {num_matches, max_match_length};
    }
    std::vector<int> prev_row(prev_size + 1, 0);
    for (int i = 1; i <= curr_size; ++i) {
        std::vector<int> curr_row(prev_size + 1, 0);
        for (int j = 1; j <= prev_size; ++j) {
            if (curr_tokens[i - 1] == prev_tokens[j - 1]) {
                curr_row[j] = prev_row[j - 1] + 1;
                if (curr_row[j] == 15) {
                    num_matches++;
                }
                max_match_length = std::max(max_match_length, curr_row[j]);
            }
        }
        prev_row.swap(curr_row);
    }
    return {num_matches, max_match_length};
}

/**
 * @brief Checks if two submissions are similar and flags them if necessary
 * @param matches_last_second Number of matches in the last second
 */
void plagiarism_checker_t::check_two_submissions(int curr_index, int prev_index, int& matches_last_second) {
    std::shared_ptr<submission_t> curr_submission;
    std::shared_ptr<submission_t> prev_submission;
    std::vector<int> curr_tokens;
    std::vector<int> prev_tokens;
    int64_t curr_time;
    int64_t prev_time;

    // To get the current and previous submissions and required metadata
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        curr_time = std::get<0>(submissions_list[curr_index]);
        curr_submission = std::get<1>(submissions_list[curr_index]);
        curr_tokens = tokens_cache[curr_submission->id];

        prev_time = std::get<0>(submissions_list[prev_index]);
        prev_submission = std::get<1>(submissions_list[prev_index]);
        prev_tokens = tokens_cache[prev_submission->id];
    }

    auto [num_matches, max_match_length] = size_of_match(curr_tokens, prev_tokens);

    // Match is actually found
    if (num_matches >= 10 || max_match_length >= 75) {
        int64_t time_diff = curr_time - prev_time;
        bool flag_both = (std::abs(time_diff) < 1000);

        bool curr_already_flagged = false;
        bool prev_already_flagged = false;

        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            curr_already_flagged = std::get<2>(submissions_list[curr_index]);
            if (!curr_already_flagged) {
                std::get<2>(submissions_list[curr_index]) = true;
            }
            if (flag_both) {
                prev_already_flagged = std::get<2>(submissions_list[prev_index]);
                if (!prev_already_flagged) {
                    std::get<2>(submissions_list[prev_index]) = true;
                }
            }
        }

        if (!curr_already_flagged) {
            if (curr_submission->student)
                curr_submission->student->flag_student(curr_submission);
            if (curr_submission->professor)
                curr_submission->professor->flag_professor(curr_submission);
        }

        if (flag_both && !prev_already_flagged) {
            if (prev_submission->student)
                prev_submission->student->flag_student(prev_submission);
            if (prev_submission->professor)
                prev_submission->professor->flag_professor(prev_submission);
        }
    }

    // For patchwork plagiarism
    if ((curr_time - prev_time) <= 1000) {
        matches_last_second += num_matches;
    }
}

/**
 * @brief Helper function for using time
 */
int64_t plagiarism_checker_t::curr_time_millis() {
    auto now = std::chrono::steady_clock::now();
    auto duration = now.time_since_epoch();
    auto curr_time = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return curr_time;
}
