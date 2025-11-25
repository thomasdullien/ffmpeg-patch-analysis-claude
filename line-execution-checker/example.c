// example.c - Simple example for line-checker

#include <stdio.h>

int add(int a, int b) {
    return a + b;  // Line 5
}

int multiply(int a, int b) {
    return a * b;  // Line 9 - NOT called
}

int main() {
    printf("Result: %d\n", add(10, 5));  // Line 13
    return 0;  // Line 14
}

// To test:
// gcc --coverage -o example example.c
// ./example
// g++ -O3 -std=c++17 ../line_checker.cpp -o line-checker
// ./line-checker example.c:5   # Should be EXECUTED
// ./line-checker example.c:9   # Should be NOT EXECUTED
// ./line-checker example.c:5 example.c:9  # Check both
