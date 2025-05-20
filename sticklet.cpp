#include <bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n+1, 0);

  dp[0] = 0;
  dp[1] = arr[0];

  for (int i = 2; i <= n; i++) 
    dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);

  return dp[n];
}

int main() {
  vector<int> arr = {6, 5, 5, 7, 4};
  cout << findMaxSum(arr) << endl;
  return 0;
}
