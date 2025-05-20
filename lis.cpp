#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr) {
  int n = arr.size();
  vector<int> lis(n, 1);
  for (int i = 1; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (arr[i] > arr[prev] && lis[i] < lis[prev] + 1) {
        lis[i] = lis[prev] + 1;
      }
    }
  }
  return *max_element(lis.begin(), lis.end());
}

int main() {
  vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
  cout << lis(arr) << endl;
  return 0;
}
