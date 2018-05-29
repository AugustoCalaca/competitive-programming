#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// ac
bool subset[110][5010];
int v[5010];

void init() {
  for(int i = 1; i <= 5010; i++)
    subset[0][i] = false;
  for(int i = 0; i <= 110; i++)
    subset[i][0] = true;
}

void subsum(int n, int sum) {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= sum; j++) {
      if(j < v[i - 1]) subset[i][j] = subset[i - 1][j];
      else subset[i][j] = subset[i - 1][j] || subset[i - 1][j - v[i - 1]];
    }
  }
}

int main() {
  fast();
  init();

  string ans = "";
  int a, b, c = 0, n, sum;
  while(true) {
    sum = 0;
    cin >> a >> b >> n;
    if(a == 0 && b == 0 && n == 0) break;

    for(int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }

    ans += "Teste " + to_string(++c) + "\n";
    subsum(n, sum);

    if(a == b) {
      if(!(sum & 1) && subset[n][sum / 2]) ans += "S\n";
      else ans += "N\n";
    }
    else {
      int diff = abs(a - b);
      bool f = true;
      for(int i = 1; i <= sum; i++)
        if(subset[n][i])
          if(subset[n][sum - i])
            if(abs(abs(sum - i) - i) == diff) {
              ans += "S\n";
              f = false;
              break;
            }

      if(f) ans += "N\n";
    }
    ans += "\n";
  }

  cout << ans;
  return 0;
}
