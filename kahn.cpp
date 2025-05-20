#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSortKahn(int V, vector<vector<int>>& edges) {
  vector<vector<int>> adj(V);
  vector<int> indegree(V, 0);
  for (auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    indegree[edge[1]]++;
  }

  queue<int> q;
  for (int i = 0; i < V; ++i)
    if (indegree[i] == 0) q.push(i);

  vector<int> result;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    result.push_back(u);
    for (int v : adj[u])
    if (--indegree[v] == 0) q.push(v);
  }
  return result;
}

int main() {
  int V = 6;
  vector<vector<int>> edges = {{2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}};
  vector<int> order = topologicalSortKahn(V, edges);
  cout << "Kahn's Algorithm: ";
  for (int node : order) cout << node << " ";
  cout << endl; // Output: 4 5 0 2 3 1 (or similar valid order)
  return 0;
}
