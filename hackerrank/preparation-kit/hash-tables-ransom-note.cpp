#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int m, n;
  string str;
  map<string, int> mp;

  cin >> m >> n;
  while(m--) {
    cin >> str;
    mp[str]++;
  }

  while(n--) {
    cin >> str;
    if(!mp[str]) return cout << "No\n", 0;
    mp[str]--;
  }
  
  cout << "Yes\n";
  return 0;
}
