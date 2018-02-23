#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ll;

// accepted
int main() {
  ll query, n;

  cout.precision(0);

  for(cin >> query; query; query--) {
    cin >> n;
    cout << fixed << floor((floor(sqrt(1 + 8*n)) - 1) / 2) << "\n";
  }

  return 0;
}
