#include "match_submissions.hpp"
#include "tokenizer.hpp"

int main(void) {
    tokenizer_t file_one_1("testcases/one/one.cpp");
    tokenizer_t file_two_1("testcases/one/two.cpp");
    std::vector<int> v1_1 = file_one_1.get_tokens();
    std::vector<int> v2_1 = file_two_1.get_tokens();

    auto start_1 = std::chrono::high_resolution_clock::now();
    std::array<int, 5> res_1 = match_submissions(v1_1, v2_1);
    auto end_1 = std::chrono::high_resolution_clock::now();
    std::cout << "Test case 1: " << std::endl;

    auto duration_1 = std::chrono::duration_cast<std::chrono::milliseconds>(end_1 - start_1);
    printTimeTaken(duration_1);
    printContainer(res_1);

    tokenizer_t file_one_2("testcases/two/one.cpp");
    tokenizer_t file_two_2("testcases/two/two.cpp");
    std::vector<int> v1_2 = file_one_2.get_tokens();
    std::vector<int> v2_2 = file_two_2.get_tokens();

    auto start_2 = std::chrono::high_resolution_clock::now();
    std::array<int, 5> res_2 = match_submissions(v1_2, v2_2);
    auto end_2 = std::chrono::high_resolution_clock::now();

    auto duration_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_2 - start_2);
    printTimeTaken(duration_2);
    printContainer(res_2);

    tokenizer_t file_one_3("testcases/three/one.cpp");
    tokenizer_t file_two_3("testcases/three/two.cpp");
    std::vector<int> v1_3 = file_one_3.get_tokens();
    std::vector<int> v2_3 = file_two_3.get_tokens();

    auto start_3 = std::chrono::high_resolution_clock::now();
    std::array<int, 5> res_3 = match_submissions(v1_3, v2_3);
    auto end_3 = std::chrono::high_resolution_clock::now();

    auto duration_3 = std::chrono::duration_cast<std::chrono::milliseconds>(end_3 - start_3);
    printTimeTaken(duration_3);
    printContainer(res_3);
}
