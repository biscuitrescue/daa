#include <iostream>
#include <vector>
using namespace std;


void knapsack01(const vector<int>& profit, const vector<int>& weight, int W) {
  int N = profit.size();

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));


  for (int i = 1; i <= N; ++i) {
    for (int w = 1; w <= W; ++w) {
      if (weight[i-1] <= w) {
        dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w - weight[i-1]]);
      } else {
        dp[i][w] = dp[i-1][w];
      }
    }
  }


  vector<int> selected_items;
  int w = W;
  for (int i = N; i > 0; --i) {
    if (dp[i][w] != dp[i-1][w]) {
      selected_items.push_back(i);
      w -= weight[i-1];
    }
  }


  cout << "Items selected:";
  for (int i = selected_items.size() - 1; i >= 0; --i) {
    cout << " Item " << selected_items[i];
  }
  cout << endl;
  cout << "Maximum profit: " << dp[N][W] << endl;
}

int main() {
  int N = 4, W = 7;
  vector<int> profit = {5, 3, 8, 6};
  vector<int> weight = {2, 3, 4, 5};

  knapsack01(profit, weight, W);

  return 0;
}
