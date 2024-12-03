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

void dijkstra1(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra2(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra3(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra4(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra5(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra6(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra7(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra8(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra9(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra10(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra11(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra12(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra13(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra14(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra15(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra16(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra17(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra18(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra19(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra20(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra21(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra22(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra23(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra24(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra25(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra26(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra27(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra28(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra29(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra30(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra31(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra32(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra33(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra34(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra35(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra36(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra37(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra38(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra39(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra40(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra41(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra42(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra43(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra44(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra45(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra46(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra47(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra48(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra49(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra50(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra51(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra52(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra53(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra54(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra55(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra56(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra57(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra58(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra59(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra60(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra61(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra62(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra63(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra64(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra65(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra66(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra67(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra68(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra69(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra70(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra71(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra72(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra73(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra74(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra75(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra76(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra77(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra78(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra79(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra80(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra81(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra82(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra83(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra84(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra85(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra86(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra87(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra88(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra89(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra90(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra91(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra92(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra93(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra94(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra95(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra96(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra97(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra98(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra99(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra100(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra101(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra102(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra103(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra104(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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

void dijkstra105(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
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
