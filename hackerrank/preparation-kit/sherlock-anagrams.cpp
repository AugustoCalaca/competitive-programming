#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b) {
  int f[26] = { 0 }, s[26] = { 0 };
  for(size_t i = 0; i < a.size(); i++)
    f[a[i] - 'a']++;
  for(size_t i = 0; i < b.size(); i++)
    s[b[i] - 'a']++;
  for(int i = 0; i < 26; i++)
    if(f[i] != s[i])
      return false;

  return true;
}

int solve(string s) {
int sz = s.size(), ans = 0;
string a, b;

for(int len = 1; len < sz; len++) {
  for(int i = 0; i + len < sz; i++) {
    a = s.substr(i, len);
    for(int j = i + 1; j + len - 1 < sz; j++) {
      b = s.substr(j, len);
      if(check(a, b))
        ans++;
    }
  }
}

return ans;
}

int main() {
  int q;
  cin >> q;

  while(q--) {
    string s;
    cin >> s;

    cout << solve(s) << "\n";
  }

  return 0;
}
