
#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

string optparan(vector<vector<int>>& s, int i, int j) {
  if (i == j) {
    return "M" + to_string(i + 1);
  }
  return "(" + optparan(s, i, s[i][j]) + " x " + optparan(s, s[i][j] + 1, j) + ")";
}

void matorder(const vector<int>& arr) {
  int n = arr.size() - 1;
  
  vector<vector<int>> m(n, vector<int>(n, 0));
  vector<vector<int>> s(n, vector<int>(n, 0));

  for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int cost = m[i][k] + m[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
        if (cost < m[i][j]) {
          m[i][j] = cost;
          s[i][j] = k;
        }
      }
    }
  }
  
  string opti_str = optparan(s, 0, n - 1);
  cout << "Efficient way: " << opti_str << endl;
  cout << "Multiplications performed: " << m[0][n - 1] << endl;
}

int main() {
  vector<int> arr = {2, 1, 3, 4};
  matorder(arr);
  return 0;
}

