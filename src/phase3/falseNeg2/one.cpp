// Time Complexity: O(o * l + k^3 + n * c * l), Space Complexity: O(o * l + k^2 + c + l)
// Graph Algorithm, Floyd-Warshall, Dynamic Programming
class Solution {
   public:
    long long findMinCost(string start, string end, vector<string>& originals, vector<string>& modified, vector<int>& costs) {
        const auto INFINITE = numeric_limits<int64_t>::max();

        const auto floydWarshallAlgo = [](auto& graph) {
            for (int middle = 0; middle < graph.size(); ++middle) {
                for (int src = 0; src < graph.size(); ++src) {
                    if (graph[src][middle] == INFINITE) continue;
                    for (int dest = 0; dest < graph[src].size(); ++dest) {
                        if (graph[middle][dest] == INFINITE) continue;
                        graph[src][dest] = min(graph[src][dest], graph[src][middle] + graph[middle][dest]);
                    }
                }
            }
        };

        unordered_map<int, unordered_map<string, int>> stringMappings;
        for (const auto& word : originals) {
            int len = word.length();
            auto& mapForLen = stringMappings[len];
            if (mapForLen.find(word) == mapForLen.end()) {
                mapForLen[word] = mapForLen.size();
            }
        }
        for (const auto& word : modified) {
            int len = word.length();
            auto& mapForLen = stringMappings[len];
            if (mapForLen.find(word) == mapForLen.end()) {
                mapForLen[word] = mapForLen.size();
            }
        }

        unordered_map<int, vector<vector<int64_t>>> distanceGraphs;
        for (const auto& [length, mapping] : stringMappings) {
            auto& graph = distanceGraphs[length];
            graph.assign(mapping.size(), vector<int64_t>(mapping.size(), INFINITE));
            for (int idx = 0; idx < graph.size(); ++idx) {
                graph[idx][idx] = 0;
            }
        }

        for (int idx = 0; idx < originals.size(); ++idx) {
            int len = originals[idx].length();
            auto& graph = distanceGraphs[len];
            auto& mapForLen = stringMappings[len];
            int srcIdx = mapForLen[originals[idx]];
            int destIdx = mapForLen[modified[idx]];
            graph[srcIdx][destIdx] = min(graph[srcIdx][destIdx], static_cast<int64_t>(costs[idx]));
        }

        for (auto& [_, graph] : distanceGraphs) {
            floydWarshallAlgo(graph);
        }

        unordered_set<int> validLengths;
        int maxLen = 0;
        for (const auto& word : originals) {
            validLengths.insert(word.length());
            maxLen = max(maxLen, static_cast<int>(word.length()));
        }

        vector<int64_t> costDP(maxLen + 1, INFINITE);
        costDP[0] = 0;

        for (int idx = 0; idx < start.size(); ++idx) {
            if (costDP[idx % costDP.size()] == INFINITE) continue;
            if (start[idx] == end[idx]) {
                costDP[(idx + 1) % costDP.size()] = min(costDP[(idx + 1) % costDP.size()], costDP[idx % costDP.size()]);
            }

            for (const auto& len : validLengths) {
                if (idx + len > start.size()) continue;

                const auto substringSource = start.substr(idx, len);
                const auto substringTarget = end.substr(idx, len);

                auto& mapForLen = stringMappings[len];
                auto& graph = distanceGraphs[len];

                if (mapForLen.count(substringSource) && mapForLen.count(substringTarget) &&
                    graph[mapForLen[substringSource]][mapForLen[substringTarget]] != INFINITE) {
                    costDP[(idx + len) % costDP.size()] = min(costDP[(idx + len) % costDP.size()],
                                                              costDP[idx % costDP.size()] + graph[mapForLen[substringSource]][mapForLen[substringTarget]]);
                }
            }
            costDP[idx % costDP.size()] = INFINITE;
        }
        return costDP[start.size() % costDP.size()] != INFINITE ? costDP[start.size() % costDP.size()] : -1;
    }
};
