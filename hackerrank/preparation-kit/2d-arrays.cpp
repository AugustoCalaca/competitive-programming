#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int mmax(int a, int b) { return a >= b ? a : b; }

int main() {
  FAST;

  int str[7][7];
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++)
    cin >> str[i][j];

  int ans = -100;
  for(int i = 2; i < 6; i++) {
    for(int j = 2; j < 6; j++) {
      int sum = 0;
      sum += (str[i - 2][j - 2]) + (str[i - 2][j - 1]) + (str[i - 2][j]);
      sum += str[i - 1][j - 1];
      sum += (str[i][j - 2]) + (str[i][j - 1]) + (str[i][j]);
      ans = mmax(ans, sum);
    }
  }

  cout << ans << "\n";

  return 0;
}
