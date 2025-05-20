#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
};

bool compare(const Item &a, const Item &b) {
    return (a.profit * b.weight) > (b.profit * a.weight);
}

double fractionalKnapsack(int capacity, vector<Item> items) {
    sort(items.begin(), items.end(), compare);
    
    double totalProfit = 0.0;
    int remaining = capacity;
    
  for (const Item &item : items) {
    if (remaining <= 0) break;

    if (item.weight <= remaining) {
      totalProfit += item.profit;
      remaining -= item.weight;
    } else {
      double fraction = static_cast<double>(remaining) / item.weight;
      totalProfit += item.profit * fraction;
      remaining = 0;
    }
  }

  return totalProfit;
}

int main() {
  vector<Item> items = {
    {60, 10},
    {100, 20},
    {120, 30}
  };
  int W = 50;

  cout << "Maximum profit: " << fractionalKnapsack(W, items) << endl;
  return 0;
}
