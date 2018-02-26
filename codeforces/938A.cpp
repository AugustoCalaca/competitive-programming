#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
  int n;
  string s, ans = "";
  string c = { 'a', 'e', 'i', 'o', 'u', 'y' };

  cin >> n >> s;
  ans += s[0];
  for(int i = 0; i + 1 < n; i++) {
    bool f = true;
    for(int j = 0; j < 6; j++) {
      if(s[i] == c[j]) {
        for(int k = 0; k < 6; k++) {
          if(s[i + 1] == c[k]) {
            f = false;
            break;
          }
        }
        break;
      }
    }
    if(f) ans += s[i + 1];
    else ans += "";
  }

  cout << ans << "\n";

  return 0;
}
