#include "functionality.hpp"
#include "tokenizer.hpp"

#ifdef CHECKER_NUMBER
#if CHECKER_NUMBER == 0
#include "checkers/checker_zero.hpp"
#elif CHECKER_NUMBER == 1
#include "checkers/checker_one.hpp"
#elif CHECKER_NUMBER == 2
#include "checkers/checker_two.hpp"
#elif CHECKER_NUMBER == 3
#include "checkers/checker_three.hpp"
#elif CHECKER_NUMBER == 4
#include "checkers/checker_four.hpp"
#elif CHECKER_NUMBER == 5
#include "checkers/checker_five.hpp"
#else
#error "Invalid CHECKER_NUMBER"
#endif
#endif
#ifndef CHECKER_NUMBER
#include "checkers/match_submissions.hpp"
#endif

extern std::array<int, 5> match_submissions(std::vector<int> &submission1,
                                            std::vector<int> &submission2);

int main(int argc, char const *argv[]) {
    std::string test_dir = (argc == 1) ? "one" : argv[1];

    tokenizer_t file_one("testcases/" + test_dir + "/one.cpp");
    tokenizer_t file_two("testcases/" + test_dir + "/two.cpp");
    std::vector<int> submission1 = file_one.get_tokens();
    std::vector<int> submission2 = file_two.get_tokens();

    auto start = std::chrono::high_resolution_clock::now();
    std::array<int, 5> output = match_submissions(submission1, submission2);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    printTimeTaken(duration);
    std::cout << BOLD << BLUE << "Results: " << RESET;
    printContainer(output, MAGENTA, true);

    std::ifstream in("testcases/" + test_dir + "/expected.txt");
    if (in.is_open()) {
        std::array<int, 5> expected;
        in >> expected[0] >> expected[1] >> expected[2] >> expected[3] >> expected[4];
        in.close();
        std::cout << BOLD << BLUE << "Expected: " << RESET;
        printContainer(expected);

        std::array<double, 5> results;
        results[0] = (output[0] == expected[0]) ? 1.0 : 0.0;
        results[1] = (1.0 * std::min(output[1], expected[1])) / std::max(output[1], expected[1]);
        results[2] = (1.0 * std::min(output[2], expected[2])) / std::max(output[2], expected[2]);
        results[3] = std::pow(1.1, -std::abs(output[3] - expected[3]));
        results[4] = std::pow(1.1, -std::abs(output[4] - expected[4]));

        double score = (2.0 * results[0] + results[1] + results[2] + 0.5 * (results[3] + results[4]));
        std::cout << BOLD << RED << "Score: " << YELLOW << score << " / 5.0" << RESET << std::endl;
    }
}
