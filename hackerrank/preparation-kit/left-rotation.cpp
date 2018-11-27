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

  int n, d, v[100010];

  cin >> n >> d;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  for(int i = 0, j = d; i < n; i++, j++) {
    if(j >= n) j = 0;
    cout << v[j] << " ";
  }
  cout << "\n";

  return 0;
}
