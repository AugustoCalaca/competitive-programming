#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int a[110];
  ll n;
  string str;

  cin >> str >> n;

  a[0] = 0;
  for(size_t i = 0; i < str.size(); i++) {
    if(str[i] == 'a') a[i + 1] = a[i] + 1;
    else a[i + 1] = a[i];
  }

  int sz = str.size();
  ll ans;
  if(sz < n)
    ans = (n / sz) * a[sz] + a[n % sz];
  else ans = a[n];

  cout << ans << "\n";
  return 0;
}
