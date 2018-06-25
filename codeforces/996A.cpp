#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();

  int n, ans = 0, c[] = { 100, 20, 10, 5, 1 };
  cin >> n;
  for(int i = 0; i < 5; i++) {
    if(n >= c[i]) ans += n / c[i], n %= c[i];
  }

  cout << ans << "\n";
  return 0;
}
