#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, m;
  string s;
  for(cin >> n; n--; ) {
    cin >> s;

    s += " ";

    bool f = s.substr(0, 2) == "RA";
    m = 2;
    for(size_t i = 2; i < s.size(); i++) {
      if(s[2] > '0' && s[2] <= '9') {
        m = i;
        break;
      }
      if(s[i] == '0' && (s[i + 1] > '0' && s[i + 1] <= '9')) {
        m = i + 1;
        break;
      }
      if(s[i] < '0' || s[i] > '9') f = false;
    }

    s.erase(s.size() - 1);
    if(f && s.size() == 20) cout << s.substr(m) << "\n";
    else cout << "INVALID DATA\n";
  }

  return 0;
}
