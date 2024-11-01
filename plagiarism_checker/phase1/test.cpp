#include "../tokenizer.hpp"
#include "match_submissions.hpp"

template <typename T>
void printContainer(T& v) {
    for (auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main(void) {
    tokenizer_t file_one("testcases/one/one.cpp");
    tokenizer_t file_two("testcases/one/two.cpp");
    std::vector<int> v1 = file_one.get_tokens();
    std::vector<int> v2 = file_two.get_tokens();
    std::array<int, 5> res = match_submissions(v1, v2);
    printContainer(v1);
}
