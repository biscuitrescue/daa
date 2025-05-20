#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
  visited[u] = true;
  for (int v : adj[u])
  if (!visited[v]) dfs(v, adj, visited, st);
  st.push(u);
}

vector<int> topologicalSortDFS(int V, vector<vector<int>>& edges) {
  vector<vector<int>> adj(V);
  for (auto& edge : edges)
  adj[edge[0]].push_back(edge[1]);

  vector<bool> visited(V, false);
  stack<int> st;

  for (int i = 0; i < V; ++i)
    if (!visited[i]) dfs(i, adj, visited, st);

  vector<int> result;
  while (!st.empty()) {
    result.push_back(st.top());
    st.pop();
  }
  return result;
}

int main() {
  int V = 6;
  vector<vector<int>> edges = {{2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}};
  vector<int> order = topologicalSortDFS(V, edges);
  cout << "DFS-based Algorithm: ";
  for (int node : order) cout << node << " ";
  cout << endl; // Output: 5 4 2 3 1 0 (or similar valid order)
  return 0;
}

