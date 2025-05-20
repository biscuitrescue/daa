#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string lcs(const string& s1, const string& s2) {
  int n = s1.size();
  int m = s2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = 1 + dp[i][j];
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }

  int i = n, j = m;
  string lcs_str;

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      lcs_str.push_back(s1[i - 1]);
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  reverse(lcs_str.begin(), lcs_str.end());
  return lcs_str;
}

int main() {
  string s1 = "AGGTAB";
  string s2 = "GXTXAYB";
  string lcs_str = lcs(s1, s2);
  cout << lcs_str.length() << endl;
  cout << lcs_str << endl;

  return 0;
}
