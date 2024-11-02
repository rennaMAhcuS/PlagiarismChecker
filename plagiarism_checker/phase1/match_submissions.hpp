#include <array>
#include <cmath>
#include <iostream>
#include <span>
#include <vector>
// -----------------------------------------------------------------------------
#include <chrono>
#include <string>

// You are free to add any STL includes above this comment, below the --line--.
// DO NOT add "using namespace std;" or include any other files/libraries.
// Also DO NOT add the include "bits/stdc++.h"

// OPTIONAL: Add your helper functions and data structures here

// color codes for good printing
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";

template <typename T>
void printTimeTaken(T duration) {
    std::cout << CYAN << "Time taken in (s): " << duration << RESET << std::endl;
}

template <typename T>
void printContainer(T& v, const std::string& color = GREEN, std::string sep = " ") {
    for (auto& i : v) {
        std::cout << color << i << RESET << sep;
    }
    std::cout << "\n";
}

template <typename T>
void printContainerToFile(T& v, std::string filename) {
    std::ofstream fileStream(filename);
    if (!fileStream) {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
    for (auto& i : v) {
        fileStream << i << "\n";
    }
    fileStream << "\n";
    fileStream.close();
}

// @param s: test vector
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

// helper function for efficient kmp_table computation of all prefixes
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
std::vector<int> kmp(const std::vector<int>& s,
                     const std::vector<int>& p,
                     const std::vector<int>& h) {
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

// @param v1: submission 1
// @param v2: submission 2
// @return: number of maximal matches
// we'll check presence of each substring of v1 in v2 using kmp
int numExactMatches(const std::vector<int>& v1, const std::vector<int>& v2) {
    // using a copy of v2 so that I can replace elements with `-1` whenever
    // a match is found so that the match is not searched again
    std::vector<int> v2Copy = v2;

    // kmpTables[j] -> kmp table of (suffix of v1 starting at j)
    std::vector<std::vector<int>> kmpTables = allKmpTables(v1);
    int n = v1.size(), num = 0;

    // for efficient calculation of kmp table of v1[j : j + i]
    std::vector<std::vector<int>> lasts(kmpTables.size());
    for (int j = 0; j < kmpTables.size(); j++) {
        lasts[j] = calcLast(kmpTables[j]);
    }

    // i -> length of pattern
    // j -> start index of pattern
    for (int i = 20; i >= 10; i--) {
        for (int j = 0; j < n - i + 1; j++) {
            std::vector<int> pattern(v1.begin() + j, v1.begin() + j + i);
            // adjusting to get kmp table of v1[j : j + i]
            int temp = kmpTables[j][i];
            kmpTables[j][i] = lasts[j][i];
            // finding all occurence of pattern in v2

            std::vector<int> res = kmp(v2Copy, pattern, kmpTables[j]);
            for (auto start : res) {
                for (int index = start; index < start + i; index++) {
                    v2Copy[index] = -1;
                }
            }

            // restoring the adjustment
            kmpTables[j][i] = temp;
            num += res.size() * i;
        }
    }

    return num;
}

// start indices of (sorted suffixes)
std::vector<int> suffixArray(const std::vector<int>& v) {
    std::vector<std::pair<std::vector<int>, int>> suffixes(v.size());

    for (int i = 0; i < v.size(); i++) {
        suffixes.push_back({std::vector<int>(v.begin() + i, v.end()), i});
    }

    std::sort(suffixes.begin(), suffixes.end());

    std::vector<int> res(v.size());
    for (auto& [_, index] : suffixes) {
        res.push_back(index);
    }

    return res;
}

std::vector<int> LCPArray(const std::vector<int>& v,
                          const std::vector<int>& sa) {
    int n = v.size();
    std::vector<int> rank(n, 0), lcp(n - 1, 0);

    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = sa[rank[i] - 1];
            while (i + h < n && j + h < n && v[i + h] == v[j + h]) {
                h++;
            }
            lcp[rank[i] - 1] = h;
            if (h > 0) h--;
        }
    }

    return lcp;
}

// @param v1: vector 1
// @param v2: vector 2
// @return: length and starting indices of longest matches in both the vectors
// we'll do this using a dp table `dp` where `dp[i][j]` holds the length of
// longest common subsequence of the two vectors upto index `i` and `j`
std::array<int, 3> longestApproxMatch(std::vector<int>& v1,
                                      std::vector<int>& v2) {
    int n = v1.size(), m = v2.size();
    int min_length = 30;
    int min_match_length = static_cast<int>(0.8 * std::max(n, m));

    std::vector<int> combined = v1;
    combined.push_back(-1);
    combined.insert(combined.end(), v2.begin(), v2.end());

    auto suffix_array = suffixArray(combined);
    auto lcp_array = LCPArray(combined, suffix_array);

    int best_length = 0, best_start_index_v1 = -1, best_start_index_v2 = -1;

    return {best_length, best_start_index_v1, best_start_index_v2};
}

std::array<int, 5> match_submissions(std::vector<int>& submission1,
                                     std::vector<int>& submission2) {
    //  TODO: Write your code here
    std::array<int, 5> result = {0, 0, 0, 0, 0};
    result[1] = numExactMatches(submission1, submission2);
    std::array<int, 3> approxMatch = longestApproxMatch(submission1, submission2);
    result[2] = approxMatch[0];
    result[3] = approxMatch[1];
    result[4] = approxMatch[2];
    return result;
    //  TODO: End
}
