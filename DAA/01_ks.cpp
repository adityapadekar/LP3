#include <bits/stdc++.h>

class Item {
public:
    int profit;
    int weight;

    Item(int p, int w) :profit(p), weight(w) {}
};

int knapsack(std::vector<Item>& items, int W) {
    int n = items.size();
    std::vector<int> prev(W + 1, 0);

    for (int i = items[0].weight; i <= W; i++) {
        prev[i] = items[0].profit;
    }

    for (int i = 1; i < n; i++) {
        for (int j = W; j >= 0; j--) {
            int notTaken = prev[j];
            int taken = INT_MIN;

            if (items[i].weight <= j) {
                taken = items[i].profit + prev[j - items[i].weight];
            }

            prev[j] = std::max(notTaken, taken);
        }
    }

    return prev[W];
}

int main() {
    std::vector<Item> items = {
        Item(5,1),
        Item(4,2),
        Item(8,4),
        Item(6,5)
    };

    std::cout << knapsack(items, 5);

    return 0;
}

