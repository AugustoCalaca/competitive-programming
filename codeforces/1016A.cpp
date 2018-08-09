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

  int n, m, v;
  ll sum = 0, act = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> v;
    sum += v;
    cout << (sum / m) - act << " ";
    act = sum / m;
  }

  cout << "\n";
  return 0;
}
