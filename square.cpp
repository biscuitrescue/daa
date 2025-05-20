#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSquareSubmatrix(const vector<vector<int>>& mat) {
  int n = mat.size();
  if (n == 0) return 0;
  int m = mat[0].size();

  vector<vector<int>> dp(n, vector<int>(m, 0));

  int maxSide = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 1) {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
        maxSide = max(maxSide, dp[i][j]);
      }
    }
  }

  return maxSide;
}

int main() {
  vector<vector<int>> mat = {
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}
  };

  int maxSide = maxSquareSubmatrix(mat);
  cout << "Maximum length of square sub-matrix with all 1s: " << maxSide << endl;

  return 0;
}
