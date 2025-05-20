#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& color, int c) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        if (graph[v][i] && color[i] == c) {
            return false; // Adjacent vertex has same color
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    int n = graph.size();
  if (v == n) {
    return true; // All vertices colored
  }

  for (int c = 1; c <= m; ++c) {
    if (isSafe(v, graph, color, c)) {
      color[v] = c;
      if (graphColoringUtil(graph, m, color, v + 1)) {
        return true;
      }
      // Backtrack
      color[v] = 0;
    }
  }
  return false; // No color assignment possible
}

void graphColoring(const vector<vector<int>>& graph, int m) {
  int n = graph.size();
  vector<int> color(n, 0);

  if (graphColoringUtil(graph, m, color, 0)) {
    cout << "Solution Exists: Following are the assigned colors:\n";
    for (int i = 0; i < n; ++i) {
      cout << color[i] << " ";
    }
    cout << endl;
  } else {
    cout << "Solution does not exist\n";
  }
}

int main() {
  vector<vector<int>> graph1 = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
  };
  int m1 = 3;
  cout << "Example 1:\n";
  graphColoring(graph1, m1);

  return 0;
}
