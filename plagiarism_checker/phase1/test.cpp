#include "../tokenizer.hpp"
#include "match_submissions.hpp"

// void printVec(std::vector<int>& v) {
//     for (int i = 0; i < v.size(); i++) {
//         std::cout << v[i] << " ";
//     }
//     std::cout << "\n";
// }

int main(void) {
    tokenizer_t file_one("testcases/one/one.cpp");
    tokenizer_t file_two("testcases/one/two.cpp");
    std::vector<int> v1 = file_one.get_tokens();
    std::vector<int> v2 = file_two.get_tokens();
}
