#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dp[2010][2010];

int main() {
  FAST;

  string s1, s2;
  int t;

  for(cin >> t; t--; ) {
    cin >> s1 >> s2;

    int sz1, sz2;
    sz1 = s1.size(), sz2 = s2.size();

    for(int i = 0; i <= sz1; i++) dp[i][0] = i;
    for(int j = 0; j <= sz2; j++) dp[0][j] = j;

    for(int i = 1; i <= sz1; i++)
      for(int j = 1; j <= sz2; j++) {
        if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
      }

    cout << dp[sz1][sz2] << "\n";
  }

  return 0;
}