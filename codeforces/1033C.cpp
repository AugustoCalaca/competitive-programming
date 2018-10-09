#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ans[M], in[M], pos[M];

int main() {
  FAST;

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> in[i];
    pos[in[i]] = i;
  }

  for(int i = n; i > 0; i--) {
    bool win = 0;
    int x = pos[i];
    for(int j = x + i; j <= n; j += i)
      if(in[j] > i && ans[j] == 0) {
        win = 1;
        break;
      }

    for(int j = x - i; j >= 0; j -= i)
      if(in[j] > i && ans[j] == 0) {
        win = 1;
        break;
      }
    ans[x] = win;
  }

  for(int i = 0; i < n; i++) {
    if(ans[i] == 0) cout << "B";
    else cout << "A";
  }

  cout << "\n";
  return 0;
}
