#include <iostream>

using namespace std;

void fast() {
  cout.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {
  fast();

  int w, m;
  cin >> w >> m;

  if(w == 2) {
    cout << "YES\n";
    return 0;
  }

  for(; m; m /= w) {
    if(m % w > 1 && m % w < w - 1) {
      cout << "NO\n";
      return 0;
    }
    if(m % w == w - 1) m++;
  }

  cout << "YES\n";
  return 0;
}