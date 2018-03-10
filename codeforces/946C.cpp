#include <iostream>
#include <string>

using namespace std;

// ac
int main() {
  string s;
  int ch = 0;

  cin >> s;
  int sz = s.size();
  for(int i = 0; i < sz && ch < 26; i++)
    if(s[i] - 'a' <= ch) {
      s[i] = 'a' + ch;
      ch++;
    }

  if(ch != 26) cout << "-1\n";
  else cout << s << endl;

  return 0;
}
