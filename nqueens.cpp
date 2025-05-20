#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, const vector<int>& positions) {
  for (int prevRow = 0; prevRow < row; ++prevRow) {
    int prevCol = positions[prevRow];
    if (prevCol == col || abs(prevCol - col) == abs(prevRow - row)) {
      return false;
    }
  }
  return true;
}

void solveNQueens(int n, int row, vector<int>& positions, vector<vector<int>>& solutions) {
  if (row == n) {
    solutions.push_back(positions);
    return;
  }

  for (int col = 0; col < n; ++col) {
    if (isSafe(row, col, positions)) {
      positions[row] = col;
      solveNQueens(n, row + 1, positions, solutions);
    }
  }
}

int main() {
  int n = 4;
  vector<vector<int>> solutions;
  vector<int> positions(n, -1);  // positions[i] = column of queen in row i

  solveNQueens(n, 0, positions, solutions);

  cout << "Number of solutions: " << solutions.size() << "\n";
  for (const auto& sol : solutions) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
      cout << sol[i] + 1;  // +1 for 1-based indexing as per problem statement
      if (i != n - 1) cout << ", ";
    }
    cout << "]\n";
  }

  return 0;
}
