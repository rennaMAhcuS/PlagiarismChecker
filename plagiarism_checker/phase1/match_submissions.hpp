#include <array>
#include <cmath>
#include <iostream>
#include <span>
#include <vector>
// -----------------------------------------------------------------------------
#include <chrono>
#include <string>
// -----------------------------------------------------------------------------
#include <unordered_map>

#define TEST_NUM_MATCHES 0

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

int numExactMatches(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.empty() || v2.empty()) return 0;

    const int n = v1.size();
    const int m = v2.size();
    int num = 0;

    std::vector<bool> used(m, false);

    // For each length from 20 down to 10
    for (int L = 20; L >= 10; --L) {
        if (L > n || L > m) continue;

        // Map to store substrings of v1
        std::unordered_multimap<std::string, int> substr_map;

        // Collect all substrings of length L from v1
        for (int i = 0; i <= n - L; ++i) {
            std::string key;
            key.reserve(L * sizeof(int));
            for (int j = 0; j < L; ++j) {
                key.append(reinterpret_cast<const char*>(&v1[i + j]), sizeof(int));
            }
            substr_map.emplace(key, i);
        }

        // Search for matching substrings in v2
        for (int i = 0; i <= m - L; ++i) {
            // Check if positions are already used
            bool is_used = false;
            for (int k = i; k < i + L; ++k) {
                if (used[k]) {
                    is_used = true;
                    break;
                }
            }
            if (is_used) continue;

            // Create key for current substring in v2
            std::string key;
            key.reserve(L * sizeof(int));
            for (int j = 0; j < L; ++j) {
                key.append(reinterpret_cast<const char*>(&v2[i + j]), sizeof(int));
            }

            auto range = substr_map.equal_range(key);
            for (auto it = range.first; it != range.second; ++it) {
                // Exact match found
                // Mark positions as used
                for (int k = i; k < i + L; ++k)
                    used[k] = true;
                num += L;
                break;  // Avoid multiple counts for the same position
            }
        }
    }
    return num;
}

std::array<int, 3> longestApproxMatch(std::vector<int>& v1, std::vector<int>& v2) {
    int n = v1.size(), m = v2.size();
    int maxLen = 0, maxI = 0, maxJ = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int len = 0, match = 0;
            while (i + len < n && j + len < m) {
                if (v1[i + len] == v2[j + len]) {
                    match++;
                }
                len++;
                if (match >= 0.8 * len) {
                    if (len > maxLen) {
                        maxLen = len;
                        maxI = i;
                        maxJ = j;
                    }
                } else {
                    break;
                }
            }
        }
    }
    return {maxLen, maxI, maxJ};
}

bool isPlagged(const int exactMatches, const int approxMatches,
               const int v1Size, const int v2Size) {
    double exactMatchRatio = (double)exactMatches / v1Size;
    double approxMatchRatio = (double)approxMatches / v1Size;

    double threshold = 0.5;
    double weightExact = 0.8;
    double weightApprox = 1 - weightExact;
    double score = weightExact * exactMatchRatio + weightApprox * approxMatchRatio;

    if (score > threshold) return true;
    return false;
}

std::array<int, 5> match_submissions(std::vector<int>& submission1,
                                     std::vector<int>& submission2) {
    // TODO: Write your code here
    std::array<int, 5> result = {0, 0, 0, 0, 0};
    result[1] = numExactMatches(submission2, submission1);
    std::array<int, 3> approxMatch = longestApproxMatch(submission1, submission2);
    result[2] = approxMatch[0];
    result[3] = approxMatch[1];
    result[4] = approxMatch[2];
    result[0] = isPlagged(result[1], result[2], submission1.size(), submission2.size());
    return result;
    // End TODO
}
