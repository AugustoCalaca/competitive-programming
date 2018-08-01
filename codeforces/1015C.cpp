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

bool comp(int a, int b) {
  return a > b;
}

int main() {
  FAST;
  int n, m, a, b, v[100010];
  ll sum1 = 0, sum2 = 0, sum3 = 0;

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    sum1 += a;
    v[i] = a - b;
    sum3 += b;
  }

  if(sum3 > m) {
    cout << "-1\n";
    return 0;
  }

  if(sum1 <= m) {
    cout << "0\n";
    return 0;
  }

  sum1 -= m;
  sort(v, v + n, comp);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    sum2 += v[i];
    if(sum2 < sum1)
      ans++;
    else break;
  }

  cout << ++ans << "\n";
  return 0;
}
