#include <iostream>

std::pair<long long, int> fibonacci_iter(int n) {
    if (n < 0)
        return { -1, -1 };
    if (n == 0 || n == 1)
        return { n, 1 };

    int steps = 0;
    long long a = 0;
    long long b = 1;
    long long c;
    
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        steps++;
    }
    return { c, steps };
}

std::pair<long long, int> fibonacci_recur(int n) {
    if (n < 0)
        return { -1, -1 };
    if (n == 0 || n == 1)
        return { n, 1 };

    std::pair<long long, int> fib1 = fibonacci_recur(n - 1);
    std::pair<long long, int> fib2 = fibonacci_recur(n - 2);

    return { fib1.first + fib2.first, fib1.second + fib2.second };
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Iterative: " << fibonacci_iter(n).first << std::endl;
    std::cout << "Steps: " << fibonacci_iter(n).second << std::endl;
    std::cout << "Recursive: " << fibonacci_recur(n).first << std::endl;
    std::cout << "Steps: " << fibonacci_recur(n).second << std::endl;

    return 0;
}