#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ll;

// accepted
ll distance(int mx, int my, int x, int y) {
  return (((x - mx) * (x - mx)) + ((y - my) * (y - my)));
}

int main() {
  int mx, my, n, x, y;
  int i = 1;
  bool flag = true;
  ll t;

  cin.tie(NULL);
  cout.sync_with_stdio(false);

  cin >> mx >> my >> n;
  for(; n--; ++i) {
    cin >> x >> y >> t;
    if(distance(mx, my, x, y) < t * t) {
      cout << i << (n ? " " : "");
      flag = false;
    }
  }

  if(flag) cout << "-1";
  cout << "\n";

  return 0;
}
