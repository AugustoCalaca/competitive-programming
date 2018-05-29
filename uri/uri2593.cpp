#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// ac
string txt, pat;
int lps[10010];
void arrPS() {
  int m = pat.size();

  for(int j = 0, i = 1; i < m; ) {
    if(pat[j] == pat[i]) j++, lps[i] = j, i++;
    else {
      if(j == 0) lps[i] = 0, i++;
      else j = lps[j - 1];
    }
  }
}

string kmp() {
  int m = pat.size();
  int n = txt.size();

  arrPS();
  bool f = true;
  string ans = "";
  for(int j = 0, i = 0; i < n; ) {
    if(pat[j] == txt[i]) j++, i++;
    if(j == m) {
      if(i - j == 0) {
        if(txt[i - j + m] == ' ') {
          ans += to_string(i - j) + " ";
          f = false;
        }
      } else if(i - j == n - m) {
        if(txt[i - j - 1] == ' ') {
          ans += to_string(i - j) + " ";
          f = false;
        }
      } else if(txt[i - j - 1] == ' ' && txt[i - j + m] == ' ') {
        ans += to_string(i - j) + " ";
        f = false;
      }
      j = lps[j - 1];
    }
    else if(i < n && pat[j] != txt[i]) {
      if(j == 0) i++;
      else j = lps[j - 1];
    }
  }
  if(f) ans += "-1 ";
  return ans.erase(ans.size() - 1);
}

int main() {
  fast();
  getline(cin , txt);
  int n;
  cin >> n;
  while(n--) {
    cin >> pat;
    cout << kmp() << "\n";
  }

  return 0;
}
