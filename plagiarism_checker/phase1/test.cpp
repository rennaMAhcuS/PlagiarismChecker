#include "../tokenizer.hpp"
#include "match_submissions.hpp"

#define TEST_TOKENS 1

int main(void) {
#if TEST_TOKENS
    tokenizer_t file_one("testcases/one/one.cpp");
    tokenizer_t file_two("testcases/one/two.cpp");
    std::vector<int> v1 = file_one.get_tokens();
    std::vector<int> v2 = file_two.get_tokens();
    printContainerToFile(v1, "v1.txt");
    printContainerToFile(v2, "v2.txt");

    auto start = std::chrono::high_resolution_clock::now();
    std::array<int, 5> res = match_submissions(v1, v2);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printTimeTaken(duration / 1e6);
    printContainer(res);
#else
    std::vector<int> v1 = {};
    for (int i = 0; i < v1.size(); i++) {
        std::vector<int> temp(v1.begin() + i, v1.end());
        std::vector<int> kmptable = kmp_table(temp);
        printContainer(kmptable, " ");
    }
    std::cout << "-----------------------------\n";
    for (int i = v1.size(); i > 0; i--) {
        std::vector<int> temp(v1.begin(), v1.begin() + i);
        std::vector<int> kmptable = kmp_table(temp);
        printContainer(kmptable);
    }
#endif
    return 0;
}
