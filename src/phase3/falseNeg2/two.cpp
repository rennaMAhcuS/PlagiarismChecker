// Time:  O(o * l + k^3 + n * c * l), o = len(original), l = max(len(x) for x in original), k = len(lookup), c = len({len(x) for x in original})
// Space: O(o * l + k^2 + c + l)
// hash table, Floyd-Warshall algorithm, dp
class Solution2 {
   public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();

        const auto& floydWarshall = [](auto& dist) {
            for (int k = 0; k < size(dist); ++k) {
                for (int i = 0; i < size(dist); ++i) {
                    if (dist[i][k] == INF) {
                        continue;
                    }
                    for (int j = 0; j < size(dist[0]); ++j) {
                        if (dist[k][j] == INF) {
                            continue;
                        }
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        };

        unordered_map<int, unordered_map<string, int>> lookups;
        for (const auto& x : original) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        for (const auto& x : changed) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        unordered_map<int, vector<vector<int64_t>>> dists;
        for (const auto& [l, lookup] : lookups) {
            auto& dist = dists[l];
            dist.assign(size(lookup), vector<int64_t>(size(lookup), INF));
            for (int u = 0; u < size(dist); ++u) {
                dist[u][u] = 0;
            }
        }
        for (int i = 0; i < size(original); ++i) {
            const int l = size(original[i]);
            auto& lookup = lookups[l];
            auto& dist = dists[l];
            const int u = lookup[original[i]];
            const int v = lookup[changed[i]];
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        for (auto& [_, dist] : dists) {
            floydWarshall(dist);
        }
        unordered_set<int> candidates;
        int l = 0;
        for (const auto& x : original) {
            candidates.emplace(size(x));
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
            }
            for (const auto& l : candidates) {
                if (i + l > size(source)) {
                    continue;
                }
                auto& lookup = lookups[l];
                auto& dist = dists[l];
                const auto& u = source.substr(i, l);
                const auto& v = target.substr(i, l);
                if (lookup.count(u) && lookup.count(v) && dist[lookup[u]][lookup[v]] != INF) {
                    dp[(i + l) % size(dp)] = min(dp[(i + l) % size(dp)], dp[i % size(dp)] + dist[lookup[u]][lookup[v]]);
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};
