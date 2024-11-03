#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Node {
    int to, cost;
};

void shortestPath(int source, vector<vector<Node>> &adjList, vector<int> &distances) {
    distances[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
        int node = minHeap.top().second;
        int nodeDist = minHeap.top().first;
        minHeap.pop();

        if (nodeDist > distances[node]) continue;

        for (auto &neighbor : adjList[node]) {
            int neighborNode = neighbor.to;
            int newDist = nodeDist + neighbor.cost;

            if (newDist < distances[neighborNode]) {
                distances[neighborNode] = newDist;
                minHeap.push({newDist, neighborNode});
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Provide the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<Node>> adjList(vertices);
    cout << "Enter edges as: start end weight\n";
    for (int i = 0; i < edges; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        adjList[start].push_back({end, weight});
        adjList[end].push_back({start, weight});  // Assuming undirected graph
    }

    int source;
    cout << "Specify the source node: ";
    cin >> source;

    vector<int> distances(vertices, INF);
    shortestPath(source, adjList, distances);

    cout << "Minimum distances from source node " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        if (distances[i] == INF) {
            cout << "Node " << i << " is not reachable\n";
        } else {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}
