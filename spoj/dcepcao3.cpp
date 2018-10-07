#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 10010
#define sq(x) (x) * (x)
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll phi[MAX];
void precomp() {
  for(int i = 1; i < MAX; i++) phi[i] = i;
  for(int i = 2; i < MAX; i++)
    if(phi[i] == i) {
      phi[i] = i - 1;
      for(int j = (i << 1); j < MAX; j += i)
        phi[j] = (phi[j] / i) * (i - 1);
    }

  for(int i = 2; i < MAX; i++)
    phi[i] += phi[i - 1];
}

int main() {
  FAST;

  precomp();
  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << sq(phi[n]) << "\n";
  }
  return 0;
}
