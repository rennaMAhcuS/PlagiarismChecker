#include <array>
#include <cmath>
#include <iostream>
#include <span>
#include <vector>
// -----------------------------------------------------------------------------

// You are free to add any STL includes above this comment, below the --line--.
// DO NOT add "using namespace std;" or include any other files/libraries.
// Also DO NOT add the include "bits/stdc++.h"

// OPTIONAL: Add your helper functions and data structures here

std::vector<int> kmp_table(std::string&& s) {
    int i = 1, j = 0;
    std::vector<int> h(s.size() + 1);
    h[0] = -1;
    while (i < s.size()) {
        if (s[j] != s[i]) {
            h[i] = j;
            while (j >= 0 && s[j] != s[i]) j = h[j];
        } else
            h[i] = h[j];
        i++, j++;
    }
    h[s.size()] = j;
    return h;
}

std::vector<std::vector<int>> allKmps(std::string& s) {
    std::vector<std::vector<int>> res(s.size(), std::vector<int>());
    for (int i = 0; i < s.size(); i++) {
        res[i] = kmp_table(s.substr(i));
    }
    return res;
}

std::array<int, 5> match_submissions(std::vector<int>& submission1,
                                     std::vector<int>& submission2) {
    // TODO: Write your code here
    std::array<int, 5> result = {0, 0, 0, 0, 0};
    return result;  // dummy return
    // End TODO
}
