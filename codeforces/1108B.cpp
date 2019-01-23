#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, a, b, arr[130], i = 0;
  for(cin >> n; n--; )
    cin >> arr[i++];
  sort(arr, arr + i);

  a = b = arr[--i];
  while(a % b == 0) {
    b = arr[--i];
    if(b == arr[i + 1]) break;
    if(b == 1) break;
  }

  cout << a << " " << b << "\n";
  return 0;
}
