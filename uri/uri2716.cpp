#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define L 160
#define C 300010
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, v[L];
  vector<bool> subSum[L];

  for(int i = 0; i < L; i++) {
    subSum[i].resize(C);
    subSum[i][0] = true;
  }

  for(int j = 1; j < C; j++)
    subSum[0][j] = false;

  while(cin >> n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }

    if(n == 1) {
      cout << v[0] << "\n";
      continue;
    }

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= sum; j++) {
        if(j < v[i - 1])
          subSum[i][j] = subSum[i - 1][j];
        else
          subSum[i][j] = subSum[i - 1][j] || subSum[i - 1][j - v[i - 1]];
      }

    int ans, start, fl = 0;
    if(!(sum & 1)) {
      start = 2, fl = 1;;
      if(subSum[n][sum / 2]) {
        cout << "0\n";
        continue;
      }
    }
    else
      start = 1;

    int i = sum / 2 - fl;
      for(; i >= 0; i--, start += 2) {
        if(subSum[n][i] && subSum[n][i + start]) break;
      }

    cout << start << "\n";
  }

  return 0;
}
