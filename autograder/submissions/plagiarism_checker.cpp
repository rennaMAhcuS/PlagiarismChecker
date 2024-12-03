#include "plagiarism_checker.hpp"
// You should NOT add ANY other includes to this file.
// Do NOT add "using namespace std;".

// TODO: Implement the methods of the plagiarism_checker_t class

plagiarism_checker_t::plagiarism_checker_t() {
    processor = std::thread(&plagiarism_checker_t::process_submissions, this);
}

plagiarism_checker_t::plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>> __submissions) {
    for (auto i : __submissions) {
        to_check.push_back({0, i, false});
    }
    processor = std::thread(&plagiarism_checker_t::process_submissions, this);
}

plagiarism_checker_t::~plagiarism_checker_t() {
    // join the thread and terminate after processing is done
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    cv.notify_all();
    if (processor.joinable()) processor.join();
}

// updates the flags if plag has taken place
// updates `matches_last_second` if `prev` is within 1 second of `curr`
// args: {curr_time, curr_submission}, {prev_time, prev_submission}, prev_index, curr_index, matches_last_second(to be updated)
void plagiarism_checker_t::check_two_submissions(std::pair<int, std::shared_ptr<submission_t>> curr,
                                                 std::pair<int, std::shared_ptr<submission_t>> prev,
                                                 int prev_index, int curr_index, int& matches_last_second) {
    std::vector<int> curr_tokens = tokenizer_t(curr.second->codefile).get_tokens();
    std::vector<int> prev_tokens = tokenizer_t(prev.second->codefile).get_tokens();

    int num_matches = 0;
    int max_match_length = 0;

    // TODO: calculate `num_matches` and `max_match_length`

    int curr_size = curr_tokens.size();
    int prev_size = prev_tokens.size();
    std::vector<std::vector<int>> dp(curr_size + 1, std::vector<int>(prev_size + 1, 0));

    // uses O(min(n, m)) space
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

    // end TODO

    // flagging
    if (num_matches >= 10 || max_match_length >= 75) {
        // flagging previous submission
        if (!std::get<2>(to_check[prev_index]) &&
            prev.first > std::max(0, curr.first - 1000)) {
            std::get<2>(to_check[prev_index]) = true;
            prev.second->student->flag_student(prev.second);
            prev.second->professor->flag_professor(prev.second);
        }
        // flagging current submission
        if (!std::get<2>(to_check[curr_index])) {
            std::get<2>(to_check[curr_index]) = true;
            curr.second->student->flag_student(curr.second);
            curr.second->professor->flag_professor(curr.second);
        }
    }

    // updating `matches_last_second`
    if (prev.first > 0 && prev.first >= curr.first - 1000) {
        matches_last_second += num_matches;
    }

    return;
}

void plagiarism_checker_t::process_submissions() {
    while (true) {
        std::tuple<int, std::shared_ptr<submission_t>, int> submission;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            cv.wait(lock, [this] { return stop || !pipe.empty(); });
            if (stop && pipe.empty()) return;
            submission = pipe.front();
            pipe.pop();
        }

        // Process the submission outside the lock
        int curr_time = std::get<0>(submission);
        auto __submission = std::get<1>(submission);
        int num_to_check = std::get<2>(submission);

        int matches_last_second = 0;

        // Lock for accessing to_check
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            for (int i = num_to_check - 1; i >= 0; i--) {
                std::pair<int, std::shared_ptr<submission_t>> curr = {curr_time, __submission};
                std::pair<int, std::shared_ptr<submission_t>> prev = {std::get<0>(to_check[i]), std::get<1>(to_check[i])};

                if (prev.first <= std::max(curr.first - 1000, 0) &&
                    std::get<2>(to_check[num_to_check])) break;

                check_two_submissions(curr, prev, i, num_to_check, matches_last_second);
            }
        }

        // Flagging for patchwork plagiarism
        if (!std::get<2>(to_check[num_to_check]) && matches_last_second >= 20) {
            std::lock_guard<std::mutex> lock(queue_mutex);
            std::get<2>(to_check[num_to_check]) = true;
            __submission->student->flag_student(__submission);
            __submission->professor->flag_professor(__submission);
        }
    }
}

void plagiarism_checker_t::add_submission(std::shared_ptr<submission_t> __submission) {
    int curr_time = curr_time_millis();
    int num_to_check;
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        num_to_check = to_check.size();
        to_check.push_back({curr_time, __submission, false});
        pipe.push({curr_time, __submission, num_to_check});
    }
    cv.notify_one();
}

int plagiarism_checker_t::curr_time_millis() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto curr_time = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return curr_time;
}

// End TODO
