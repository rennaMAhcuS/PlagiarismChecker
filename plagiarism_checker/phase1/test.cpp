#include "../tokenizer.hpp"
#include "match_submissions.hpp"

void printVec(std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(void) {
    std::string s = "xyxy";
    std::vector<std::vector<int>> v = allKmps(s);
    for (auto& i : v) printVec(i);
    std::cout << "Hello beta\n";
}
