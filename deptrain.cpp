#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int timeToMinutes(const string& t) {
  int h, m;
  char colon;
  stringstream ss(t);
  ss >> h >> colon >> m;
  return h * 60 + m;
}

int findMinPlatforms(const vector<string>& arr, const vector<string>& dep) {
  int n = arr.size();
  vector<int> arr_min(n), dep_min(n);
  for (int i = 0; i < n; ++i) {
    arr_min[i] = timeToMinutes(arr[i]);
    dep_min[i] = timeToMinutes(dep[i]);
  }
  sort(arr_min.begin(), arr_min.end());
  sort(dep_min.begin(), dep_min.end());

  int platforms_needed = 1, max_platforms = 1;
  int i = 1, j = 0;
  while (i < n && j < n) {
    if (arr_min[i] <= dep_min[j]) {
      platforms_needed++;
      i++;
      if (platforms_needed > max_platforms)
        max_platforms = platforms_needed;
    } else {
      platforms_needed--;
      j++;
    }
  }
  return max_platforms;
}

int main() {
  vector<string> arr = {"9:00", "9:40", "9:50", "11:00", "15:00", "18:00"};
  vector<string> dep = {"9:10", "12:00", "11:20", "11:30", "19:00", "20:00"};

  cout << "Minimum platforms required: " << findMinPlatforms(arr, dep) << endl;
  return 0;
}
