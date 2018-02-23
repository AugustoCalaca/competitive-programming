#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
  string str;
  string ans = "";

  while(cin >> str) {
    for(size_t i = 0; i < str.size(); i++) {
      if(i & 1)
       ans += str[i];
    }
    ans += " ";
  }

  ans.erase(ans.end() - 1);
  cout << ans << "\n";
  return 0;
}