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

int main() {
  fast();
  string s;
  cin >> s;
  int ans = s.size();
  int n = ans;

  for(int i = 0, j = n - 1; i < n / 2;) {
    if(s[i] == s[j]) {
      i++, j--;
    }
    else{
      cout << ans << "\n";
      return 0;
    }
  }

  int i = 0;
  while(s[i] == s[n - 1]) i++;
  if(i == n) cout << "0\n";
  else cout << ans - 1 << "\n";

  return 0;
}
