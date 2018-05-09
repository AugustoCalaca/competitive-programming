#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int main() {
  fast();

  int n;
  string s, s2;
  map<string, int> m;

  cin >> n;
  cin.ignore(252, '\n');
  cin >> s;

  string ans = "[[[[[[[[[[[[[[[[[[[";
  int max = -1;
  for(int i = 1; i < n; i++) {
    s2 = s.substr(i - 1, 2);
    m[s2]++;
  }

  for(auto i = m.begin(); i != m.end(); i++) {
    if(i->second > max) {
      ans = i->first;
      max = i->second;
    }
  }

  cout << ans << "\n";
  return 0;
}
