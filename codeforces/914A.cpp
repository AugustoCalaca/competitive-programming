#include <iostream>
#include <cmath>

using namespace std;

// accepted
int main() {
  int cases;
  float n, sq, lgst = -1000000;

  for(cin >> cases; cases--;) {
    cin >> n;
    sq = floor(sqrt(n));
    if(sq * sq != n && n > lgst) lgst = n;
  }

  cout.precision(0);
  cout << fixed << lgst << "\n";

  return 0;
}
