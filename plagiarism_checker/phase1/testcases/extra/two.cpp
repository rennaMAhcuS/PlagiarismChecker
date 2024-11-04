#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.destination;
            int nextDist = currentDist + edge.weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph
    }

    int start;
    cout << "Enter the start node: ";
    cin >> start;

    vector<int> dist(n, INF);
    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
