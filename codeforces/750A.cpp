#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int main() {
  fast();
  int n, k;
  cin >> n >> k;

  int d = 240 - k;

  int i = 1;
  for(; d >= i * 5 && i <= n; i++) {
    d -= i * 5;
  }

  cout << --i << "\n";
  return 0;
}
