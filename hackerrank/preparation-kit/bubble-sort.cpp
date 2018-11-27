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

  int n, v[610];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j + 1 < n; j++)
      if(v[j] > v[j + 1])
        swap(v[j], v[j + 1]), ans++;

  cout << "Array is sorted in "  << ans << " swaps.\n"
       << "First Element: " << v[0] << "\n"
       << "Last Element: " << v[n - 1] << "\n";
  return 0;
}
