// Time:  O(max(n, m)^2)
// Space: O(max(n, m)^2)

// dp
class Solution {
   public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& cmp = [](int x, int y) {
            return x < y ? -1 : (x > y ? 1 : 0);
        };

        const auto& count = [&](int start1, int end1, int start2, int end2) {
            vector<vector<int>> dp(size(grid), vector<int>(size(grid[0])));
            vector<int> up(size(grid[0]), size(grid));
            vector<int> down(size(grid[0]), -1);
            for (int i = start1, d1 = cmp(end1, start1); i != end1; i += d1) {
                int l = size(grid[0]);
                int r = -1;
                int u = size(grid);
                int d = -1;
                for (int j = start2, d2 = cmp(end2, start2); j != end2; j += d2) {
                    if (grid[i][j]) {
                        up[j] = min(up[j], i);
                        down[j] = max(down[j], i);
                    }
                    u = min(u, up[j]);
                    d = max(d, down[j]);
                    if (down[j] >= 0) {
                        l = min(l, j);
                        r = max(r, j);
                    }
                    dp[i][j] = r >= 0 ? (r - l + 1) * (d - u + 1) : 0;
                }
            }
            return dp;
        };

        const auto& count2 = [&](bool is_vertical) {
            const auto& get_n = [&]() {
                return !is_vertical ? size(grid) : size(grid[0]);
            };

            const auto& get_m = [&]() {
                return !is_vertical ? size(grid[0]) : size(grid);
            };

            const auto& get = [&](int i, int j) {
                return !is_vertical ? grid[i][j] : grid[j][i];
            };

            vector<int> left(get_n(), get_m());
            vector<int> right(get_n(), -1);
            for (int i = 0; i < get_n(); ++i) {
                for (int j = 0; j < get_m(); ++j) {
                    if (get(i, j) == 0) {
                        continue;
                    }
                    left[i] = min(left[i], j);
                    right[i] = max(right[i], j);
                }
            }
            vector<vector<int>> dp(get_n(), vector<int>(get_n()));
            for (int i = 0; i < size(dp); ++i) {
                int l = get_m();
                int r = -1;
                int u = get_n();
                int d = -1;
                for (int j = i; j < size(dp[0]); ++j) {
                    if (right[j] != -1) {
                        l = min(l, left[j]);
                        r = max(r, right[j]);
                        u = min(u, j);
                        d = max(d, j);
                    }
                    dp[i][j] = r >= 0 ? (r - l + 1) * (d - u + 1) : 0;
                }
            }
            return dp;
        };

        const auto& up_left = count(0, size(grid), 0, size(grid[0]));
        const auto& up_right = count(0, size(grid), size(grid[0]) - 1, -1);
        const auto& down_left = count(size(grid) - 1, -1, 0, size(grid[0]));
        const auto& down_right = count(size(grid) - 1, -1, size(grid[0]) - 1, -1);
        const auto& horizon = count2(false);
        const auto& vertical = count2(true);
        int result = numeric_limits<int>::max();
        for (int i = 0; i + 1 < size(grid); ++i) {
            for (int j = 0; j + 1 < size(grid[0]); ++j) {
                result = min({result,
                              up_left[i][j] + up_right[i][j + 1] + horizon[i + 1][size(grid) - 1],
                              horizon[0][i] + down_left[i + 1][j] + down_right[i + 1][j + 1],
                              up_left[i][j] + down_left[i + 1][j] + vertical[j + 1][size(grid[0]) - 1],
                              vertical[0][j] + up_right[i][j + 1] + down_right[i + 1][j + 1]});
            }
        }
        for (int i = 0; i + 2 < size(grid); ++i) {
            for (int j = i + 1; j + 1 < size(grid); ++j) {
                result = min(result, horizon[0][i] + horizon[i + 1][j] + horizon[j + 1][size(grid) - 1]);
            }
        }
        for (int i = 0; i + 2 < size(grid[0]); ++i) {
            for (int j = i + 1; j + 1 < size(grid[0]); ++j) {
                result = min(result, vertical[0][i] + vertical[i + 1][j] + vertical[j + 1][size(grid[0]) - 1]);
            }
        }
        return result;
    }
};
