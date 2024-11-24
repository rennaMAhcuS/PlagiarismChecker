// plagiarism_checker.hpp

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>

#include "structures.hpp"

// You should NOT modify ANYTHING in this file above this comment.
// You are free to add any STL includes above, below the --line--.
// DO NOT add "using namespace std;" or include any other files/libraries.
// Also DO NOT add the include "bits/stdc++.h"

// OPTIONAL: Add your helper functions and classes here

class plagiarism_checker_t {
   public:
    plagiarism_checker_t();
    plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>> __submissions);
    ~plagiarism_checker_t();
    void add_submission(std::shared_ptr<submission_t> __submission);

   protected:
    std::queue<std::shared_ptr<submission_t>> submission_queue;
    std::vector<std::tuple<int64_t, std::shared_ptr<submission_t>, bool>> submissions_list;
    std::unordered_map<long, std::vector<int>> tokens_cache;

    std::thread submission_processor_thread;
    std::atomic<bool> stop;
    std::mutex queue_mutex;
    std::condition_variable cv;

    void submission_processor();
    void compare_submissions(int curr_index);
    void check_two_submissions(int curr_index, int prev_index, int& matches_last_second);
    int64_t curr_time_millis();

    // Thread pool management
    size_t max_threads;
    std::vector<std::thread> thread_pool;
    std::queue<int> tasks_queue;
    std::mutex tasks_mutex;
    std::condition_variable tasks_cv;
    void worker_thread();
};