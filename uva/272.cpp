#include <iostream>
#include <string>

using namespace std;

// ac
int main() {
  string s;

  int f = 1;
  while(getline(cin, s)) {
    string ans = "";
    for(int i : s) {
      if(i == '"') {
        if(f & 1) ans += "``";
        else ans += "''";
        f++;
      } else ans += i;
    }

    cout << ans << endl;
  }

  return 0;
}
