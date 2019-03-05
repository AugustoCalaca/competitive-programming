#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>
#include <map>

#define LIM 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, r;
  ll arr[LIM];
  map<ll, ll> left, right;

  cin >> n >> r;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    right[arr[i]]++;
  }

  ll ans = 0;
  for(int i = 0; i < n; i++) {
    right[arr[i]]--;
    if(arr[i] % r == 0) 
      ans += left[arr[i] / r] * right[arr[i] * r];
    left[arr[i]]++;
  }
  
  cout << ans << "\n";
  return 0;
}
