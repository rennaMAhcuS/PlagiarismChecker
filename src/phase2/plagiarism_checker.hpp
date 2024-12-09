#include "structures.hpp"
// -----------------------------------------------------------------------------
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>

// You are free to add any STL includes above this comment, below the --line--.
// DO NOT add "using namespace std;" or include any other files/libraries.
// Also DO NOT add the include "bits/stdc++.h"

// OPTIONAL: Add your helper functions and classes here

/**
 * @file plagiarism_checker.hpp
 * @brief Header file for the plagiarism checker class.
 *
 * This file contains the declarations for the class `plagiarism_checker_t`.
 */

class plagiarism_checker_t {
    // You should NOT modify the public interface of this class.
   public:
    plagiarism_checker_t(void);
    plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>>
                             __submissions);
    ~plagiarism_checker_t(void);
    void add_submission(std::shared_ptr<submission_t> __submission);

   protected:
    // Queue holding submissions to be processed.
    std::queue<std::tuple<int, std::shared_ptr<submission_t>, int>> pipe;
    // Vector of submissions pending check with a flag.
    std::vector<std::tuple<int, std::shared_ptr<submission_t>, bool>> to_check;
    // Thread responsible for processing submissions.
    std::thread processor;
    // Atomic flag indicating whether processing should stop.
    std::atomic<bool> stop;
    // Mutex for synchronizing access to the submission queue.
    std::mutex queue_mutex;
    // Condition variable for notifying the processing thread.
    std::condition_variable cv;

    // Member functions - documentation in the `cpp` file.

    int curr_time_millis();
    void process_submissions();
    void check_two_submissions(std::pair<int, std::shared_ptr<submission_t>>,
                               std::pair<int, std::shared_ptr<submission_t>>,
                               int, int, int&);
};
