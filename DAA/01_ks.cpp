#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    int profit;
    int weight;

    Item(int p, int w) {
        profit = p;
        weight = w;
    }
};

int knapsack01(int w, vector<Item>& arr) {
    int n = arr.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (arr[i - 1].weight <= j) {
                dp[i][j] = max(arr[i - 1].profit + dp[i - 1][j - arr[i - 1].weight], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][w];
}

int main() {
    int n;
    cout << "Enter number of items-\n";
    cin >> n;

    vector<Item> arr;
    for (int i = 0; i < n; i++) {
        int profit, weight;
        cout << "Enter profit of item " << i + 1 << "-\n";
        cin >> profit;
        cout << "Enter weight of item " << i + 1 << "-\n";
        cin >> weight;
        arr.push_back(Item(profit, weight));
    }

    int w;
    cout << "Enter capacity of knapsack-\n";
    cin >> w;

    cout << "Maximum value in knapsack: " << knapsack01(w, arr) << endl;

    return 0;
}
