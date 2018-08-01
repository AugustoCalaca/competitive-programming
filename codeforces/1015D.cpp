#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int k;
  ll n, s;

  cin >> n >> k >> s;

  if(s < k || s > k * (n - 1))
    return cout << "NO\n", 0;

  cout << "YES\n";

  ll d, house = 1;
  for(int i = k; i > 0; i--, s -= d) {
    d = min(n - 1, s - (i - 1));
    if(house - d > 0) house -= d;
    else house += d;
    cout << house << " ";
  }

  cout << "\n";
  return 0;
}
