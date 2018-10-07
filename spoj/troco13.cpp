#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX1 1010
#define MAX2 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, m, sum = 0, v[MAX1];
  vector<int> subset[MAX1];

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> v[i];
    if(sum < MAX2)
      sum += v[i];
  }

  if(sum >= MAX2) sum = MAX2 - 5;

  for(int i = 0; i <= m; i++) {
    subset[i].resize(sum + 1);
    subset[i][0] = 1;
  }

  for(int j = 1; j <= sum; j++)
    subset[0][j] = 0;

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= sum; j++) {
      if(j < v[i - 1])
        subset[i][j] = subset[i - 1][j];
      else
        subset[i][j] = subset[i - 1][j] || subset[i - 1][j - v[i - 1]];
    }
  }

  if(subset[m][n]) cout << "S\n";
  else cout << "N\n";

  return 0;
}
