
// DAA_Fractionalknapsack.cpp
#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight, value;
  Item(int w, int v) : weight(w), value(v) {}
};

int main() {
  vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
  int capacity = 50;

  // Sort by value/weight ratio in descending order
  sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
  });

  double totalValue = 0.0;

  for (auto &item : items) {
    if (capacity >= item.weight) {
      capacity -= item.weight;
      totalValue += item.value;
    } else {
      totalValue += (double)item.value * capacity / item.weight;
      break;
    }
  }

  cout << "Maximum value = " << totalValue << endl;

  return 0;
}
