#include "../tokenizer.hpp"
#include "match_submissions.hpp"

template <typename T>
void printContainer(T& v) {
    for (auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

#define TEST_TOKENS 1

int main(void) {
#if TEST_TOKENS
    tokenizer_t file_one("testcases/one/one.cpp");
    tokenizer_t file_two("testcases/one/two.cpp");
    std::vector<int> v1 = file_one.get_tokens();
    std::vector<int> v2 = file_two.get_tokens();
    std::array<int, 5> res = match_submissions(v1, v2);
    printContainer(res);
#else
    std::vector<int> v1 = {};
    for (int i = v1.size(); i > 0; i--) {
        std::vector<int> temp(v1.begin(), v1.begin() + i);
        std::vector<int> kmptable = kmp_table(temp);
        printContainer(kmptable);
    }
    std::vector<int> h = kmp_table(v1);
    std::vector<int> last = calcLast(h);
    for (int i = v1.size(); i > 0; i--) {
        std::vector<int> kmptable = prefixKmpTable(h, last, i);
        printContainer(kmptable);
    }
#endif
    return 0;
}
