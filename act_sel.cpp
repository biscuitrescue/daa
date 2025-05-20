#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
  int start, finish, index;
};

bool activityCompare(const Activity &a1, const Activity &a2) {
  return a1.finish < a2.finish;
}

void activitySelection(const vector<int> &start, const vector<int> &finish) {
  int n = start.size();
  vector<Activity> activities(n);
  for (int i = 0; i < n; ++i) {
    activities[i] = {start[i], finish[i], i+1}; // index+1 for 1-based indexing
  }

  sort(activities.begin(), activities.end(), activityCompare);

  vector<int> selected;
  int lastFinish = 0;

  for (int i = 0; i < n; ++i) {
    if (activities[i].start >= lastFinish) {
      selected.push_back(activities[i].index);
      lastFinish = activities[i].finish;
    }
  }

  cout << "Maximum number of activities: " << selected.size() << endl;
  cout << "Selected activities (1-based index): ";
  for (int idx : selected) cout << idx << " ";
  cout << endl;
}

int main() {
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> finish = {2, 4, 6, 7, 9, 9};

  activitySelection(start, finish);

  return 0;
}
