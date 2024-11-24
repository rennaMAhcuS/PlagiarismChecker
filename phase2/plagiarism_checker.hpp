#include "structures.hpp"
// -----------------------------------------------------------------------------
// You should NOT modify ANYTHING in this file above this comment.
// You are free to add any STL includes above, below the --line--.
// DO NOT add "using namespace std;" or include any other files/libraries.
// Also DO NOT add the include "bits/stdc++.h"

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>

// OPTIONAL: Add your helper functions and classes here

class plagiarism_checker_t {
   public:
    plagiarism_checker_t(void);
    plagiarism_checker_t(std::vector<std::shared_ptr<submission_t>> __submissions);
    ~plagiarism_checker_t(void);
    void add_submission(std::shared_ptr<submission_t> __submission);

   protected:
    /// Queue that holds submissions awaiting processing.
    std::queue<std::shared_ptr<submission_t>> submission_queue;
    /// List of submissions with their timestamp and processing status.
    std::vector<std::tuple<int64_t, std::shared_ptr<submission_t>, bool>> submissions_list;
    /// Cache storing tokenized submissions for quick access.
    std::unordered_map<long, std::vector<int>> tokens_cache;

    /// Thread responsible for processing submissions in the queue.
    std::thread submission_processor_thread;
    /// Atomic flag to signal the processing thread to stop.
    std::atomic<bool> stop;
    /// Mutex to protect access to the submission_queue.
    std::mutex queue_mutex;
    /// Condition variable to notify the processing thread of new submissions.
    std::condition_variable cv;

    void submission_processor();
    void compare_submissions(int curr_index);
    void check_two_submissions(int curr_index, int prev_index, int& matches_last_second);
    std::pair<int, int> size_of_match(std::vector<int>& curr_tokens, std::vector<int>& prev_tokens);
    int64_t curr_time_millis();
    void worker_thread();

    /// Maximum number of threads in the thread pool.
    size_t max_threads;
    /// Pool of worker threads for processing tasks.
    std::vector<std::thread> thread_pool;
    /// Queue holding tasks to be processed by the worker threads.
    std::queue<int> tasks_queue;
    /// Mutex to protect access to the tasks_queue.
    std::mutex tasks_mutex;
    /// Condition variable to notify worker threads of new tasks.
    std::condition_variable tasks_cv;
};
