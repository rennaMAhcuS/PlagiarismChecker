#include "structures.hpp"
// -----------------------------------------------------------------------------
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

// You are free to add any STL includes above this comment, below the --line--.
// DO NOT add "using namespace std;" or include any other files/libraries.
// Also DO NOT add the include "bits/stdc++.h"

// OPTIONAL: Add your helper functions and classes here

class plagiarism_checker_t {
    // You should NOT modify the public interface of this class.
   public:
    plagiarism_checker_t(void);
    plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>>
                             __submissions);
    ~plagiarism_checker_t(void);
    void add_submission(std::shared_ptr<submission_t> __submission);

   protected:
    // TODO: Add members and function signatures here
    std::queue<std::tuple<int, std::shared_ptr<submission_t>, int>> pipe;        // `{time, submission, number of previous files}`
    std::vector<std::tuple<int, std::shared_ptr<submission_t>, bool>> to_check;  // `{time, submission, flagged?}`
    std::thread processor, processor2;
    std::atomic<bool> stop;
    std::mutex queue_mutex;
    std::condition_variable cv;

    int curr_time_millis();
    // void push_submission(std::shared_ptr<submission_t>, int, int);
    void process_submissions();
    void check_two_submissions(std::pair<int, std::shared_ptr<submission_t>>, std::pair<int, std::shared_ptr<submission_t>>, int, int, int&);

    // End TODO
};
