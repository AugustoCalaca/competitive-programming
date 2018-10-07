#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100100
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ans[MAX];

int main() {
  int t, k = 0, n, q, last, l, r, in;

  for(scanf("%d", &t); t--; ) {
    printf("Case %d:\n", ++k);

    ans[0] = 1;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
      scanf("%d", &in);
      if(i == 1)
        last = in;
      if(last == in)
        ans[i] = ans[i - 1];
      else {
        ans[i] = ans[i - 1] + 1;
        last = in;
      }
    }

    for(int i = 0; i < q; i++) {
      scanf("%d %d", &l, &r);
      if(l == 1)
        printf("%d\n", ans[r]);
      else
        printf("%d\n", ans[r] - ans[l] + 1);
    }
  }

  return 0;
}
