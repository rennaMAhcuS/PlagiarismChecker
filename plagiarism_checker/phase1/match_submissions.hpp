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

// @param s: vector
// @return: kmp table of s
std::vector<int> kmp_table(const std::vector<int>& p) {
    int i = 1, j = 0;
    std::vector<int> h(p.size() + 1);
    h[0] = -1;
    while (i < p.size()) {
        if (p[j] != p[i]) {
            h[i] = j;
            while (j >= 0 && p[j] != p[i]) j = h[j];
        } else
            h[i] = h[j];
        i++, j++;
    }
    h[p.size()] = j;
    return h;
}

// @param s: test vector
// @return: kmp table for all suffixes of s
std::vector<std::vector<int>> allKmpTables(const std::vector<int>& s) {
    std::vector<std::vector<int>> res(s.size());
    for (int i = 0; i < s.size(); i++) {
        std::vector<int> subvec(s.begin() + i, s.end());
        res[i] = kmp_table(subvec);
    }
    return res;
}

// @param p: pattern vector
// @param i: end of prefix ([0, i) is taken)
// @param h: kmp table of p
// @param last: stores kmp_table[i]
// @return : kmp_table of prefix
std::vector<int> prefixKmpTable(const std::vector<int>& h, const std::vector<int>& last, int i) {
    std::vector<int> res(h.begin(), h.begin() + i + 1);
    res[i] = last[i];
    return res;
}

std::vector<int> calcLast(const std::vector<int>& kmpTable) {
    if (kmpTable.empty()) return {};
    std::vector<int> res = kmpTable;
    int i = res.size() - 2;
    while (i > 0) {
        res[i] = res[i + 1] - 1 > res[i] ? res[i + 1] - 1 : res[i];
        i--;
    }
    res[0] = -1;
    return res;
}

// @param s: test vector
// @param p: pattern
// @param h: kmp table
// @return: start indices of all matches
std::vector<int> kmp(const std::vector<int>& s, const std::vector<int>& p, const std::vector<int>& h) {
    if (p.empty()) throw std::invalid_argument("Pattern is empty");
    int i = 0, j = 0;
    std::vector<int> found;
    while (i < s.size()) {
        if (p[j] == s[i]) {
            i++, j++;
            if (j == p.size()) {
                found.push_back(i - j);
                j = h[j];
            }
        } else {
            j = h[j];
            if (j < 0) {
                i++, j++;
            }
        }
    }
    return found;
}

int numMatches(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::vector<std::vector<int>> kmps = allKmpTables(v1);
    int n = v1.size(), num = 0;
    std::vector<std::vector<int>> lasts(kmps.size());
    for (int j = 0; j < kmps.size(); j++) {
        lasts[j] = calcLast(kmps[j]);
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < n - i + 1; j++) {
            std::vector<int> pattern(v1.begin() + j, v1.begin() + j + i);
            int temp = kmps[j][i];
            kmps[j][i] = lasts[j][i];
            std::vector<int> res = kmp(v2, pattern, kmps[j]);
            kmps[j][i] = temp;
            num += res.size();
        }
    }
    return num;
}

std::array<int, 5> match_submissions(std::vector<int>& submission1,
                                     std::vector<int>& submission2) {
    //  TODO: Write your code here
    std::array<int, 5> result = {0, 0, 0, 0, 0};
    result[1] = numMatches(submission1, submission2);
    return result;
    //  TODO: End
}
