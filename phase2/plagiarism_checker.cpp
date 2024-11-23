#include "plagiarism_checker.hpp"
// You should NOT add ANY other includes to this file.
// Do NOT add "using namespace std;".

// TODO: Implement the methods of the plagiarism_checker_t class

plagiarism_checker_t::plagiarism_checker_t() {
    // do nothing???
}

plagiarism_checker_t::plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>> __submissions) {
    for (auto i : __submissions) {
        to_check.push_back({0, i, false});
    }
}

plagiarism_checker_t::~plagiarism_checker_t() {
    // join all the threads
    for (auto& i : threads_list) {
        i.join();
    }
}

// updates the flags if plag has taken place
// returns the number of matches between two submissions
std::pair<int, int> plagiarism_checker_t::check_two_submissions(std::pair<int, std::shared_ptr<submission_t>> curr,
                                                                std::pair<int, std::shared_ptr<submission_t>> prev) {
    std::vector<int> curr_tokens = tokenizer_t(curr.second->codefile).get_tokens();
    std::vector<int> prev_tokens = tokenizer_t(prev.second->codefile).get_tokens();

    int num_matches = 0;
    int max_match_length = 0;

    // TODO: calculate `num_matches` and `max_match_length`
    int curr_size = curr_tokens.size();
    int prev_size = prev_tokens.size();
    std::vector<std::vector<int>> dp(curr_size + 1, std::vector<int>(prev_size + 1, 0));

    for (int i = 1; i <= curr_size; ++i) {
        for (int j = 1; j <= prev_size; ++j) {
            if (curr_tokens[i - 1] == prev_tokens[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] >= 15 && dp[i - 1][j - 1] < 15) num_matches++;
                max_match_length = std::max(max_match_length, dp[i][j]);
            }
        }
    }
    // TODO: END

    return {num_matches, max_match_length};
}

void plagiarism_checker_t::process_submission(std::shared_ptr<submission_t> __submission, int curr_time, int num_to_check) {
    int matches_last_second = 0;  // length of matches in submissions from last 1 second (for patchwork plagiarism)
    for (int i = num_to_check - 1; i >= 0; i--) {
        // compare two submissions
        std::pair<int, int> vals = check_two_submissions(
            {0, __submission}, {std::get<0>(to_check[i]), std::get<1>(to_check[i])});

        // update `matches_last_second`
        if (std::get<0>(to_check[i]) > 0 && std::get<0>(to_check[i]) >= curr_time - 1000)
            matches_last_second += vals.first;

        // flagging
        std::mutex mtx;
        mtx.lock();

        // if it's not in last 1 second and current is already flagged
        if (std::get<2>(to_check[num_to_check]) && std::get<0>(to_check[i]) < curr_time - 1000) break;

        if (vals.first >= 10 || vals.second >= 75) {
            // flagging previous submission
            if (!std::get<2>(to_check[i]) &&
                std::get<0>(to_check[i]) > std::max(0, curr_time - 1000)) {
                std::get<2>(to_check[i]) = true;
                std::clog << "prev flagged" << std::endl;
                std::get<1>(to_check[i])->student->flag_student(std::get<1>(to_check[i]));
                std::get<1>(to_check[i])->professor->flag_professor(std::get<1>(to_check[i]));
            }
            // flagging current submission
            if (!std::get<2>(to_check[num_to_check])) {
                std::get<2>(to_check[num_to_check]) = true;
                std::clog << "curr flagged" << std::endl;
                __submission->student->flag_student(__submission);
                __submission->professor->flag_professor(__submission);
            }
        }
        mtx.unlock();
    }

    // flagging for patchwork plagiarism
    std::mutex mtx;
    mtx.lock();
    if (!std::get<2>(to_check[num_to_check]) && matches_last_second >= 20) {
        std::clog << "flagged for patchwork" << std::endl;
        std::get<2>(to_check[num_to_check]) = true;
        __submission->student->flag_student(__submission);
        __submission->professor->flag_professor(__submission);
    }
    mtx.unlock();
}

/**
 * @brief Adding the submission along with it's metadata and plag-checking it in a seperate thread
 */
void plagiarism_checker_t::add_submission(std::shared_ptr<submission_t> __submission) {
    int curr_time = curr_time_millis();
    int num_to_check = to_check.size();
    to_check.push_back({curr_time, __submission, false});
    threads_list.emplace_back(&plagiarism_checker_t::process_submission,
                              this,
                              __submission,
                              curr_time,
                              num_to_check);
}

int plagiarism_checker_t::curr_time_millis() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto curr_time = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return curr_time;
}

// End TODO
