#include "plagiarism_checker.hpp"

// TODO: Implement the methods of the plagiarism_checker_t class

plagiarism_checker_t::plagiarism_checker_t() : stop(false) {
    submission_processor_thread = std::thread(&plagiarism_checker_t::submission_processor, this);
}

plagiarism_checker_t::plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>> __submissions) : stop(false) {
    int curr_time = curr_time_millis();
    for (auto& submission : __submissions) {
        submissions_list.push_back({curr_time, submission, false});
        tokens_cache[submission->id] = tokenizer_t(submission->codefile).get_tokens();
    }
    submission_processor_thread = std::thread(&plagiarism_checker_t::submission_processor, this);
}

plagiarism_checker_t::~plagiarism_checker_t() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
        cv.notify_all();
    }
    if (submission_processor_thread.joinable()) {
        submission_processor_thread.join();
    }
    for (auto& thread : comparison_threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void plagiarism_checker_t::add_submission(std::shared_ptr<submission_t> __submission) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        submission_queue.push(__submission);
    }
    cv.notify_one();
}

void plagiarism_checker_t::submission_processor() {
    while (true) {
        std::shared_ptr<submission_t> submission;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            cv.wait(lock, [this] { return stop || !submission_queue.empty(); });
            if (stop && submission_queue.empty()) {
                return;
            }
            submission = submission_queue.front();
            submission_queue.pop();
        }

        int curr_time = curr_time_millis();
        std::vector<int> curr_tokens = tokenizer_t(submission->codefile).get_tokens();
        int curr_index;
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            submissions_list.push_back({curr_time, submission, false});
            tokens_cache[submission->id] = curr_tokens;
            curr_index = submissions_list.size() - 1;
        }

        // Limit to 2 comparison threads
        while (true) {
            {
                std::lock_guard<std::mutex> lock(queue_mutex);
                // Remove finished threads
                for (auto it = comparison_threads.begin(); it != comparison_threads.end();) {
                    if (it->joinable()) {
                        it->join();
                        it = comparison_threads.erase(it);
                    } else {
                        ++it;
                    }
                }
                if (comparison_threads.size() < 2) {
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        // Launch comparison in a new thread
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            comparison_threads.emplace_back(&plagiarism_checker_t::compare_submissions, this, curr_index);
        }
    }
}

void plagiarism_checker_t::compare_submissions(int curr_index) {
    auto& [curr_time, curr_submission, curr_flagged] = submissions_list[curr_index];
    auto& curr_tokens = tokens_cache[curr_submission->id];
    int matches_last_second = 0;

    for (int i = 0; i < curr_index; ++i) {
        auto& [prev_time, prev_submission, prev_flagged] = submissions_list[i];
        if (prev_time < curr_time - 1000) {
            continue;
        }
        check_two_submissions(curr_index, i, matches_last_second);
    }

    if (!std::get<2>(submissions_list[curr_index]) && matches_last_second >= 20) {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            std::get<2>(submissions_list[curr_index]) = true;
        }
        curr_submission->student->flag_student(curr_submission);
        curr_submission->professor->flag_professor(curr_submission);
    }
}

void plagiarism_checker_t::check_two_submissions(int curr_index, int prev_index, int& matches_last_second) {
    auto& [curr_time, curr_submission, curr_flagged] = submissions_list[curr_index];
    auto& [prev_time, prev_submission, prev_flagged] = submissions_list[prev_index];

    auto& curr_tokens = tokens_cache[curr_submission->id];
    auto& prev_tokens = tokens_cache[prev_submission->id];

    int num_matches = 0;
    int max_match_length = 0;

    int curr_size = curr_tokens.size();
    int prev_size = prev_tokens.size();

    std::vector<int> prev_row(prev_size + 1, 0), curr_row(prev_size + 1, 0);
    for (int i = 1; i <= curr_size; ++i) {
        for (int j = 1; j <= prev_size; ++j) {
            if (curr_tokens[i - 1] == prev_tokens[j - 1]) {
                curr_row[j] = prev_row[j - 1] + 1;
                if (curr_row[j] == 15) num_matches++;
                max_match_length = std::max(max_match_length, curr_row[j]);
            } else {
                curr_row[j] = 0;
            }
        }
        std::swap(curr_row, prev_row);
    }

    if (num_matches >= 10 || max_match_length >= 75) {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            if (!std::get<2>(submissions_list[prev_index])) {
                std::get<2>(submissions_list[prev_index]) = true;
            }
            if (!std::get<2>(submissions_list[curr_index])) {
                std::get<2>(submissions_list[curr_index]) = true;
            }
        }
        prev_submission->student->flag_student(prev_submission);
        prev_submission->professor->flag_professor(prev_submission);
        curr_submission->student->flag_student(curr_submission);
        curr_submission->professor->flag_professor(curr_submission);
    }

    if (prev_time >= curr_time - 1000) {
        matches_last_second += num_matches;
    }
}

int plagiarism_checker_t::curr_time_millis() {
    auto now = std::chrono::steady_clock::now();
    auto duration = now.time_since_epoch();
    auto curr_time = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return static_cast<int>(curr_time);
}

// End TODO
