#include <iostream>
#include <algorithm>
#include <cmath>
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
  ll a, b;
  int v[1000010];

  cin >> s;
  cin >> a >> b;

  ll n = 0;
  for(size_t i = 0; i < s.size() - 1; i++) {
    n = n * 10 + (s[i] - '0');
    n %= a;
    if(!n) v[i] = 1;
  }

  n = 0;
  ll pot = 1;
  for(size_t i = s.size() - 1; i + 1; i--) {
    n = n + pot *(s[i] - '0');
    n %= b;
    if(!n && s[i] != '0') {
      if(v[i - 1] == 1) {
        cout << "YES\n";
        cout << s.substr(0, i) << "\n"
             << s.substr(i) << "\n";
        return 0;
      }
    }
    pot *= 10;
    pot %= b;
  }

  cout << "NO\n";
  return 0;
}
