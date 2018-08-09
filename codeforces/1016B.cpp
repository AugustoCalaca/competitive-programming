#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s, t;
int lps[1010];
int n, m, q, l, r;

void arrpresuff() {
  lps[0] = 0;
  for(int i = 1, j = 0; i < m; ) {
    if(t[i] == t[j]) j++, lps[i] = j, i++;
    else {
      if(j != 0) j = lps[j - 1];
      else lps[i] = 0, i++;
    }
  }
}

int kmp() {
  int ans = 0;
  for(int i = l, j = 0; i < r; ) {
    if(s[i] == t[j]) i++, j++;
    if(j == m) {
      ans++;
      j = lps[j - 1];
    }
    else if(i < r && s[i] != t[j]) {
      if(j != 0) j = lps[j - 1];
      else i++;
    }
  }

  return ans;
}

int main() {
  FAST;

  cin >> n >> m >> q;
  cin >> s >> t;

  arrpresuff();
  while(q--) {
    cin >> l >> r;
    l--;
    cout << kmp() << "\n";
  }

  return 0;
}
