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

int main() {
  FAST;

  int n;
  string str;

  cin >> n >> str;

  bool isdown = false;
  int down = 0, up = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    if(str[i] == 'U') up++;
    else if(str[i] == 'D') down++;
    if(down > up) isdown = true;
    if(up == down && isdown) ans++, isdown = false;
  }

  cout << ans << "\n";
  return 0;
}
