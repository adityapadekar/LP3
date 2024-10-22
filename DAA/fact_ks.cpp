#include <iostream>
#include <vector>
#include <algorithm>
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

bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), compare);
    
    double finalValue = 0.0;
    for(int i = 0; i < arr.size(); i++) {
        if(w >= arr[i].weight) {
            finalValue += arr[i].profit;
            w -= arr[i].weight;
        }
        else {
            finalValue += arr[i].profit * ((double)w / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n;
    cout << "Enter number of items-\n";
    cin >> n;
    
    vector<Item> arr;
    for(int i = 0; i < n; i++) {
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
    
    cout << "Maximum value in knapsack: " << fractionalKnapsack(w, arr) << endl;
    
    return 0;
}