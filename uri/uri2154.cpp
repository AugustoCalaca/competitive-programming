#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
  int t, n, m;
  char ch, a;
  string ans;

  while(cin >> t) {
    ans = "";
    while(t--){
      cin >> n >> ch >> m;

      ans += to_string(n * m) + "x" + (m - 1 > 1 ? to_string(m - 1) : "");
      if(t){
        ans += " + ";
        cin >> a;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
