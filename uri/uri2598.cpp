#include <iostream>

using namespace std;

// accepted
int main() {
  int t, n, m;

  for(cin >> t; t--;) {
    cin >> n >> m;
    cout << (n + m - 1) / m << "\n";
  }

  return 0;
}
