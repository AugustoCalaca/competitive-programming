#include <iostream>
#include <cmath>

using namespace std;

// accepted
int main() {
  int t, n;
  const double eq = sqrt(25 + 10*sqrt(5)) / 4;

  cout.precision(3);
  cout << fixed;

  for(cin >> t; t--;) {
    cin >> n;
    cout << n * n * eq << "\n";
  }

  return 0;
}