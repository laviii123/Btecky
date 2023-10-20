#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n to calculate the nth Fibonacci number: ";
    std::cin >> n;
    
    if (n < 0) {
        std::cout << "Please enter a non-negative integer.\n";
    } else {
        int result = fibonacci(n);
        std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
    }
    
    return 0;
}
