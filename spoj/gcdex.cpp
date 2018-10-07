#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 1000010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll ans[MAX], phi[MAX];
void precomp() {
  for(int i = 1; i < MAX; i++) phi[i] = i;
  for(int i = 2; i < MAX; i++) {
    if(phi[i] == i) {
      phi[i] = i - 1;
      for(int j = (i << 1); j < MAX; j += i)
        phi[j] = (phi[j] / i) * (i - 1);
    }
  }
}

void sumgcd() {
  for(int i = 1; i < MAX; i++)
    for(int j = 2; i * j < MAX; j++) {
      ans[i * j] += i * phi[j];
    }

  for(int i = 2; i < MAX; i++) {
    ans[i] += ans[i - 1];
  }
}

int main() {
  FAST;

  precomp();
  sumgcd();

  int n;
  while(true) {
    cin >> n;
    if(n == 0) break;
    cout << ans[n] << "\n";
  }
  return 0;
}
