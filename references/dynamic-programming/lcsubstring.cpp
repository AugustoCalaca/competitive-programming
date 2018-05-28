#include <iostream>
#include <string>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

// O(n x m)
int lcsubstring(string s, string s2) {
  int sz = s.size(), sz2 = s2.size();
  int pd[sz + 1][sz + 1];

  int ans = 0;
  for(int i = 0; i <= sz; i++)
    for(int j = 0; j <= sz2; j++) {
      if(i == 0 || j == 0) pd[i][j] = 0;
      else if(s[i - 1] == s2[j - 1]) pd[i][j] = pd[i - 1][j - 1] + 1;
      else pd[i][j] = 0;
      ans = max(ans, pd[i][j]);
    }

  return ans;
}

int main() {
  string s = "abcdef", s2 = "abc";
  cout << "l.c. substring: " << lcsubstring(s, s2) << "\n";
}