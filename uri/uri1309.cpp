#include <iostream>
#include <iomanip>
#include <string>

#define pb push_back
using namespace std;

// accepted
int main() {
  string dolars, cents;
  string ans;

  while(cin >> dolars >> cents) {
    int sz = dolars.size();
    int flag = sz % 3;

    ans.append("$");
    for(int i = 0; i < sz; i++) {
      ans.pb(dolars[i]);
      if(flag == 0) flag = 3;
      if(!(--flag)) {
        ans.pb(',');
        flag = 3;
      }
    }

    ans.erase(ans.end() - 1);
    ans.pb('.');
    if(cents.size() < 2)
      ans.append("0");
    ans.append(cents);
    ans.pb('\n');

  }

  cout << ans;

  return 0;
}