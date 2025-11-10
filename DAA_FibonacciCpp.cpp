
// DAA_Fibonacci.cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive method to find Fibonacci number
int fibonacciRecursive(int n) {
  if (n <= 1)
    return n;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Non-recursive (iterative) method to find Fibonacci number
int fibonacciNonRecursive(int n) {
  if (n <= 1)
    return n;
  int prev = 0, curr = 1;
  for (int i = 2; i <= n; i++) {
    int next = prev + curr;
    prev = curr;
    curr = next;
  }
  return curr;
}

int main() {
  int n = 10;
  cout << "Fibonacci number at position " << n
       << " (Recursive): " << fibonacciRecursive(n) << endl;
  cout << "Fibonacci number at position " << n
       << " (Non-Recursive): " << fibonacciNonRecursive(n) << endl;
  return 0;
}
