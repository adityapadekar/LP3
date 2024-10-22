#include <iostream>
using namespace std;

pair<long long, int> fibonacci_iter(int n) {
    if (n < 0)
        return make_pair(-1, 1);
    if (n == 0 || n == 1)
        return make_pair(n, 1);
        
    int steps = 0;
    long long a = 0;
    long long b = 1;
    long long c;
    
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        steps++;
    }
    return make_pair(c, steps + 1);
}

pair<long long, int> fibonacci_recur(int n) {
    if (n < 0)
        return make_pair(-1, 1);
    if (n == 0 || n == 1)
        return make_pair(n, 1);
        
    pair<long long, int> fib1 = fibonacci_recur(n - 1);
    pair<long long, int> fib2 = fibonacci_recur(n - 2);
    
    return make_pair(fib1.first + fib2.first, fib1.second + fib2.second + 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Iterative: " << fibonacci_iter(n).first << endl;
    cout << "Steps: " << fibonacci_iter(n).second << endl;
    cout << "Recursive: " << fibonacci_recur(n).first << endl;
    cout << "Steps: " << fibonacci_recur(n).second << endl;
    
    return 0;
}