#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define V 6

bool bfs(int residualGraph[V][V], int s, int t, int parent[]) {
  bool visited[V] = {false};
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 0; v < V; v++) {
      if (!visited[v] && residualGraph[u][v] > 0) {
        parent[v] = u;
        visited[v] = true;
        q.push(v);
        if (v == t) return true;
      }
    }
  }
  return false;
}

int fordFulkerson(int graph[V][V], int s, int t) {
  int u, v;
  int residualGraph[V][V];

  for (u = 0; u < V; u++)
    for (v = 0; v < V; v++)
      residualGraph[u][v] = graph[u][v];

  int parent[V];
  int maxFlow = 0;

  while (bfs(residualGraph, s, t, parent)) {
    int pathFlow = INT_MAX;
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      pathFlow = min(pathFlow, residualGraph[u][v]);
    }
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      residualGraph[u][v] -= pathFlow;
      residualGraph[v][u] += pathFlow;
    }

    maxFlow += pathFlow;
  }

  return maxFlow;
}

int main() {
  int graph[V][V] = {
    {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}
  };

  cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5) << endl;
  return 0;
}
