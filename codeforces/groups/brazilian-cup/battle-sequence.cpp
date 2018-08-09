#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int c = 0, s = 0;
  string str, ans = "";

  cin >> str;
  for(int i = 0; i < (int)str.size(); i++) {
    if(str[i] == 'C') {
      c++;
      s = 0;
      if(c == 3) ans += "P", c = 0;
      else ans += "B";
    }
    else if(str[i] == 'S') {
      s++;
      c = 0;
      if(s == 3) ans += "T", s = 0;
      else ans += "D";
    }
  }

  cout << ans << "\n";

  return 0;
}
