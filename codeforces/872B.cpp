#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 100000
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int table[M][(int)floor(log2(M)) + 1];
int input[M];

int func(int a, int b, bool choice) {
  if(choice) return min(a, b);
  else       return max(a, b);
}

void build(int n, bool choice) {
  for(int i = 0; i < n; i++)
    table[i][0] = input[i];

  for(int j = 1; (1 << j) <= n; j++)
    for(int i = 0; i + (1 << (j - 1)) <= n; i++)
      table[i][j] = func(table[i][j - 1], table[i + (1 << (j - 1))][j - 1], choice);
}

int query(int l, int r, bool choice = true) {
  int h = r - l + 1;
  int k = (int)floor(log2(h));

  if(choice) return min(table[l][k], table[l + h - (1 << k)][k]);
  else       return max(table[l][k], table[l + h - (1 << k)][k]);
}

int main() {
  FAST;

  int n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++) cin >> input[i];

  build(n, k <= 2);

  ll ans;
  if(k == 1) ans = query(0, n - 1);
  else if(k == 2) {
    int temp = -1000000001;
    for(int i = 0; i + 1 < n; i++)
      temp = max(max(query(0, i), query(i + 1, n - 1)), temp);

    ans = temp;
  } else ans = query(0, n - 1, false);

  cout << ans << "\n";

  return 0;
}
