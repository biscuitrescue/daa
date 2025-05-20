#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
  char id;
  int deadline;
  int profit;
};

bool jobCompare(const Job &a, const Job &b) {
  return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs) {
  sort(jobs.begin(), jobs.end(), jobCompare);

  int max_deadline = 0;
  for (const auto &job : jobs) {
    if (job.deadline > max_deadline)
      max_deadline = job.deadline;
  }

  vector<bool> slot(max_deadline + 1, false);
  vector<char> result(max_deadline + 1, '\0');
  int total_profit = 0;

  for (const auto &job : jobs) {
    for (int j = job.deadline; j > 0; --j) {
      if (!slot[j]) {
        slot[j] = true;
        result[j] = job.id;
        total_profit += job.profit;
        break;
      }
    }
  }

  cout << "Selected Jobs: ";
  for (int i = 1; i <= max_deadline; ++i) {
    if (result[i] != '\0')
      cout << result[i] << " ";
  }
  cout << endl;
  cout << "Maximum Profit: " << total_profit << endl;
}

int main() {
  vector<Job> jobs = {
    {'a', 4, 20},
    {'b', 1, 10},
    {'c', 1, 40},
    {'d', 1, 30}
  };

  jobSequencing(jobs);

  return 0;
}
