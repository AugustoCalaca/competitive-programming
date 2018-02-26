#include <iostream>

using namespace std;

// accepted
int fib[25];
bool v[1010] = {0};

void fibonacci(int n) {
  int i = 3;

  v[0] = false;
  v[1] = true;
  v[2] = true;

  for(; fib[i - 1] <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    v[fib[i]] = true;
  }
}

int main() {
  int n;
  cin >> n;
  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 1;

  fibonacci(n);

  for(int i = 1; i <= n; i++) {
    if(v[i])
      cout << "O";
    else
      cout << "o";
  }
  cout << "\n";

  return 0;
}
