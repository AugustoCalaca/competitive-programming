#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, f, v[100010];

  cin >> n >> f;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  int l = 1, r = 1e9;

  int middle;
  while(l < r) {
    middle = l + ( r - l) / 2;

    ll sum = 0;
    for(int i = 0; i < n; i++)
      sum += middle / v[i];

    if(sum >= f) r = middle;
    else l = middle + 1;
  }

  cout << l << "\n";
  return 0;
}
