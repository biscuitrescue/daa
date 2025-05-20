#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, capacity;
};

class Dinic {
public:
    vector<vector<Edge>> graph;
    vector<int> level, ptr;
    Dinic(int n) : graph(n), level(n), ptr(n) {}

    void add_edge(int from, int to, int capacity) {
        Edge forward = {to, (int)graph[to].size(), capacity};
        Edge backward = {from, (int)graph[from].size(), 0};
        graph[from].push_back(forward);
        graph[to].push_back(backward);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (Edge &e : graph[u]) {
                if (e.capacity > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                    if (e.to == t) return true;
                }
            }
        }
        return false;
    }

    int dfs(int u, int t, int flow) {
        if (u == t) return flow;
        for (int &i = ptr[u]; i < graph[u].size(); i++) {
            Edge &e = graph[u][i];
            if (e.capacity > 0 && level[e.to] == level[u] + 1) {
                int pushed = dfs(e.to, t, min(flow, e.capacity));
                if (pushed > 0) {
                    e.capacity -= pushed;
                    graph[e.to][e.rev].capacity += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, INT_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U--; V--; // Convert to 0-based indices
        edges.emplace_back(U, V, W);
    }

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        A--; B--; // Convert to 0-based indices

        Dinic dinic(N);
        for (auto &[U, V, W] : edges) {
            dinic.add_edge(U, V, W);
        }

        cout << dinic.max_flow(A, B) << '\n';
    }

    return 0;
}
