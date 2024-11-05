#include <bits/stdc++.h>

class Item {
public:
  int profit;
  int weight;

  Item(int p, int w) :profit(p), weight(w) {}
};

bool compare(const Item& a, const Item& b) {
  float valA = (float)a.profit / a.weight;
  float valB = (float)b.profit / b.weight;

  return valA > valB;
}

float fractional_ks(float weight, std::vector<Item> arr) {
  std::sort(arr.begin(), arr.end(), compare);
  float result = 0;

  for (int i{}; i < arr.size(); i++) {
    if (weight < arr[i].weight) {
      result += ((float)arr[i].profit / arr[i].weight) * weight;
      return result;
    }
    else {
      result += arr[i].profit;
      weight -= arr[i].weight;
    }
  }

  return result;
}

int main() {
  std::vector<Item> items = {
    Item(100, 20),
    Item(60, 10),
    Item(100, 50),
    Item(200, 50),
  };

  std::cout << fractional_ks(90, items);

  return 0;
}