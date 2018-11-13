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

  int n, v[53], c = 0;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  for(int i = 0; i + 1 < n; i++)
    if(v[i + 1] <= v[i]) c++;

  cout << n - c << "\n";
  return 0;
}
