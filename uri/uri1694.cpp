#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 2510
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> primes;
bool marked[M];
ll comb[M][M];
int v1[M], v2[M];

void sieve() {
  fill(marked, marked + M, true);
  for(int i = 2; i < M; i++)
    if(marked[i])
      for(int j = i * i; j < M; j += i)
        marked[j] = false;

  for(int i = 2; i < M; i++)
    if(marked[i]) primes.pb(i);
}

void combinations() {
  for(int i = 1; i < M; i++) {
    for(int j = 1; j <= min(i, j); j++) {
      if(j == 1) comb[i][j] = i;
      else if(j == i) comb[i][j] = 1;
      else comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }
}

int main() {
  FAST;

  sieve();
  combinations();
  int n, m, k;


  while(true) {
    cin >> n >> m >> k;
    if(n == 0 && m == 0 && k == 0) break;
    fill(v1, v1 + M, 0);
    fill(v2, v2 + M, 0);

    int disp = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(!binary_search(primes.begin(), primes.end(), i * m + j))
          v1[i]++, v2[j]++, disp++;
      }
    }

    if(k == 1) cout << disp << "\n";
    else {
      ll ans = 0;
      for(int i = 0; i < n; i++) if(v1[i] >= k) ans += comb[v1[i]][k];
      for(int j = 0; j < m; j++) if(v2[j] >= k) ans += comb[v2[j]][k];

      cout << ans << "\n";
    }
  }

  return 0;
}
