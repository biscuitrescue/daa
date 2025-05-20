#include <bits/stdc++.h>
using namespace std;

int countWays(int n, int k) {
    
    if (n == 1) return k;
    if (n == 2) return k*k;
    
    vector<int> dp(n+1);
    
    dp[1] = k;
    dp[2] = k*k;
    
    for (int i=3; i<=n; i++) {
        dp[i] = dp[i-1]*(k-1) + dp[i-2]*(k-1);
    }
    
    return dp[n];
}

int main() {
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}
