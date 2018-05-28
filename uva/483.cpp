#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ac
string inverse(string tmp) {
  int sz = tmp.size();
  for(int i = 0; i < sz / 2; i++)
    swap(tmp[i], tmp[sz - i - 1]);

  return tmp;
}

int main() {
  string s, tmp, ans;

  while(getline(cin , s)) {
    ans = tmp = "";
    for(int i = 0; i < s.size(); i++) {
      while(s[i] == ' ') i++;
      tmp += s[i];
      if(s[i + 1] == ' ' || s[i + 1] == '\0') {
        ans += inverse(tmp) + " ";
        tmp = "";
      }
    }

    ans = ans.erase(ans.size() - 1);
    cout << ans << endl;
  }

  return 0;
}
