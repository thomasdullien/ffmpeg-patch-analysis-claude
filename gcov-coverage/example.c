// example.c - Simple coverage example

#include <stdio.h>

int add(int a, int b) {
    return a + b;  // Will be executed
}

int multiply(int a, int b) {
    return a * b;  // Will NOT be executed
}

int main() {
    printf("Result: %d\n", add(10, 5));
    return 0;
}

// To test coverage:
// gcc --coverage -o example example.c
// ./example
// gcov example.c
// cat example.c.gcov
//
// Expected:
// - Line 5 (add): EXECUTED
// - Line 9 (multiply): NOT EXECUTED
//
// For HTML report:
// gcovr --html-details -o coverage.html
