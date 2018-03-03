#include <iostream>
#include <string>

using namespace std;

// ac
int main() {
  int t;
  string str;

  cin >> t;
  for(int i = 0; i < t; ) {
    cin >> str;

    int k, j = 0, ans = 0, sz = str.size();
    while(j + 1 < sz) {
      if(str[j] != str[j + 1]) {
        ans++;
        k = j;
        for(; k >= 0; k--) {
          if(str[k] == '+') str[k] = '-';
          else str[k] = '+';
        }
      }
      j++;
    }

    if(str[j] == '-') ans++;

    cout << "Case #" << ++i << ": " << ans << "\n";
  }

  return 0;
}
