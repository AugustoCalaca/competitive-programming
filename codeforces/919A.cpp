#include <iostream>

using namespace std;

// acecpted
int main() {
  int n, m, a, b;
  float min = 1000;

  cin >> n >> m;
  while(n--) {
    cin >> a >> b;

    if((float)a / b < min) min =  (float)a / b;
  }

  cout.precision(8);
  cout << fixed << min * m << "\n";

  return 0;
}
