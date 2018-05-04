#include <iostream>
#include <set>
#include <string>

using namespace std;

// ac
int main() {
  set<string> s;
  set<char> s2;

  int n;
  string str;
  string str2;
  for(cin >> n; n--; ) {
    cin >> str;
    for(int i = 0; i < str.size(); i++)
      s2.insert(str[i]);
    str2 = "";
    for(auto it = s2.begin(); it != s2.end(); it++)
      str2 += *it;
    s.insert(str2);
    s2.clear();
  }

  cout << s.size() << "\n";
  return 0;
}