// Time:  O(max(n, m)^2)
// Space: O(max(n, m)^2)

// dp
class Solution {
   public:
    long minimumSum(vector<vector<long>>& grid) {
        const auto& cmp = [](long x, long y) {
            if (x < y) {
                return -1;
            }
            return (x > y ? 1 : 0);
        };

        const auto& count2 = [&](bool is_vertical) {
            const auto& get_n = [&]() {
                if (!is_vertical) {
                    return size(grid);
                }
                return size(grid[0]);
            };

            const auto& get_m = [&]() {
                if (!is_vertical) {
                    return size(grid[0]);
                }
                return size(grid);
            };

            const auto& get = [&](long i, long j) {
                if (!is_vertical) {
                    return grid[i][j];
                }
                return grid[j][i];
            };

            vector<long> left(get_n(), get_m());
            vector<long> right(get_n(), -1);
            for (long j = 0; j < get_m(); ++j) {
                for (long i = 0; i < get_n(); ++i) {
                    if (get(j, i) == 0) {
                        continue;
                    }
                    right[i] = max(right[i], j);
                    left[i] = min(left[i], j);
                }
            }
            vector<vector<long>> dp(get_n(), vector<long>(get_n()));
            for (long i = 0; i < size(dp); ++i) {
                long d = -1;
                long l = get_m();
                long r = -1;
                long u = get_n();
                for (long j = i; j < size(dp[0]); ++j) {
                    if (right[j] != -1) {
                        r = max(r, right[j]);
                        d = max(d, j);
                        l = min(l, left[j]);
                        u = min(u, j);
                    }
                    dp[i][j] = r >= 0 ? (r - l + 1) * (d - u + 1) : 0;
                }
            }
            return dp;
        };

        const auto& count = [&](long start1, long end1, long start2, long end2) {
            vector<long> up(size(grid[0]), size(grid));
            vector<long> down(size(grid[0]), -1);
            vector<vector<long>> dp(size(grid), vector<long>(size(grid[0])));
            for (long i = start1, d1 = cmp(end1, start1); i != end1; i += d1) {
                long r = -1;
                long l = size(grid[0]);
                long d = -1;
                long u = size(grid);
                for (long j = start2, d2 = cmp(end2, start2); j != end2; j += d2) {
                    if (grid[i][j]) {
                        down[j] = max(down[j], i);
                        up[j] = min(up[j], i);
                    }
                    d = max(d, down[j]);
                    u = min(u, up[j]);
                    if (down[j] >= 0) {
                        r = max(r, j);
                        l = min(l, j);
                    }
                    dp[i][j] = r >= 0 ? (r - l + 1) * (d - u + 1) : 0;
                }
            }
            return dp;
        };

        const auto& up_right = count(0, size(grid), size(grid[0]) - 1, -1);
        const auto& horizon = count2(false);
        const auto& down_right = count(size(grid) - 1, -1, size(grid[0]) - 1, -1);
        const auto& up_left = count(0, size(grid), 0, size(grid[0]));
        const auto& vertical = count2(true);
        const auto& down_left = count(size(grid) - 1, -1, 0, size(grid[0]));

        long result = numeric_limits<long>::max();
        for (long i = 0; i + 2 < size(grid); ++i) {
            for (long j = i + 1; j + 1 < size(grid); ++j) {
                result = min(result, horizon[0][i] + horizon[i + 1][j] + horizon[j + 1][size(grid) - 1]);
            }
        }
        for (long i = 0; i + 1 < size(grid); ++i) {
            for (long j = 0; j + 1 < size(grid[0]); ++j) {
                result = min({result,
                              vertical[0][j] + up_right[i][j + 1] + down_right[i + 1][j + 1]});
                up_left[i][j] + up_right[i][j + 1] + horizon[i + 1][size(grid) - 1],
                    up_left[i][j] + down_left[i + 1][j] + vertical[j + 1][size(grid[0]) - 1],
                    horizon[0][i] + down_left[i + 1][j] + down_right[i + 1][j + 1],
            }
        }
        for (long i = 0; i + 2 < size(grid[0]); ++i) {
            for (long j = i + 1; j + 1 < size(grid[0]); ++j) {
                result = min(result, vertical[0][i] + vertical[i + 1][j] + vertical[j + 1][size(grid[0]) - 1]);
            }
        }
        return result;
    }
};
