#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 1000000007
#define MAX 10000010
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> phi(MAX, 0);

void precomp() {
  for(int i = 1; i < MAX; i++) phi[i] = i;
  for(int i = 2; i < MAX; i++)
    if(phi[i] == i) {
      phi[i] = i - 1;
      for(int j = (i << 1); j < MAX; j += i)
        phi[j] = (phi[j] / i) * (i - 1);
    }
}

vector<int> pqtd;
vector<bool> marked(MAX, true);
void sieve() {
  for(int i = 2; i * i < MAX; i++)
    for(int j = i * i; j < MAX; j += i)
      if(marked[j])
        marked[j] = false;

  pqtd.pb(0);
  pqtd.pb(0);
  pqtd.pb(1);
  for(int i = 3; i < MAX; i++) {
    if(marked[i])
      pqtd.pb(pqtd.back() + 1);
    else
      pqtd.pb(pqtd.back());
  }
}

int fexp(int b, int e) {
  int ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) ans = (ans % M * b % M) % M;
    b = (b % M * b % M) % M;
  }

  return ans;
}

int fat(int n) {
  int f = 1;
  for(int i = 1; i <= n; i++)
    f = (f % M * i % M) % M;
  return f;
}

int main() {
  FAST;

  precomp();
  sieve();

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << fexp(phi[n], fat(pqtd[n] - phi[n])) << "\n";
  }
  return 0;
}
