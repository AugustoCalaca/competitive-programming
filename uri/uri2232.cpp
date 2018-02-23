#include <iostream>

using namespace std;
typedef unsigned int ui;

// accepted
ui pot[32];

void myfill() {
  for(int i = 2; i < 32; i++)
    pot[i] = pot[i - 1] * 2;
}

ui query(int n) {
  ui ans = 0;
  for(int i = 0; i < n; i++)
    ans += pot[i];

  return ans;
}

int main() {
  int t, n;

  pot[0] = 1;
  pot[1] = 2;

  myfill();

  for(cin >> t; t--;) {
    cin >> n;
    cout << query(n) << "\n";
  }

  return 0;
}
