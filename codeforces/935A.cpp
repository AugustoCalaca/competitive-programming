#include <iostream>

using namespace std;

// accepted
int main() {
  int n, c = 1;

  cin >> n;
  for(int i = 2; i <= n / 2; i++) {
    if((n - i) % i == 0) c++;
  }

  cout << c << "\n";
  return 0;
}
