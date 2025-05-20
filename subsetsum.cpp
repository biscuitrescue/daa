#include <iostream>
#include <vector>
using namespace std;

int perfectSum(vector<int> &arr, int target) {

    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1]) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> arr = {1, 2, 3, 3};
    int target = 6;
    cout << perfectSum(arr, target) << endl;

    return 0;
}
