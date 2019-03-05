#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define LIM 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, spend;
  ll arr[LIM];

  cin >> n >> spend;
  for(int i = 0; i < n; i++) 
    cin >> arr[i];

  sort(arr, arr + n);
  for(int i = 1; i < n; i++)
    arr[i] += arr[i - 1];

  int ans = (lower_bound(arr, arr + n, spend) - arr);
  cout << (arr[ans] == spend ? ++ans : ans) << "\n";    

  return 0;
}
