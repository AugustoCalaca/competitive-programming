#include <iostream>

using namespace std;

// accepted
int main() {
  int n, t;

  for(cin >> t; t--;) {
    cin >> n;
    cout << n * (n + 1) / 2 + 1 << "\n";
  }

  return 0;
}
