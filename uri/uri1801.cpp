#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll LIM = 1e12;

bool comp(char a, char b) { return a > b; }

int main() {
  FAST;

  map<int, int> mp;
  string str;
  cin >> str;

  for(int i = 0; i < (int)str.size(); i++)
    mp[str[i] - '0']++;

  ll x = stoll(str);

  sort(str.begin(), str.end(), comp);
  ll m = stoll(str);

  ll ans = 0, y;
  for(ll i = 1; i * i <= x + m; i++) {
    y = i * i - x;
    if(y < 0) continue;

    string str2 = to_string(y);
    bool ok = true;
    if(str2.size() != str.size()) continue;

    map<int, int> mp2;
    for(int i = 0; i < (int)str.size(); i++)
      mp2[str2[i] - '0']++;

    for(auto it = mp2.begin(); it != mp2.end(); it++)
      if(mp.find(it->f)->s != it->s) {
        ok = false;
        break;
      }

    if(ok && str2[0] != '0') ans++;
  }

  cout << ans << "\n";
  return 0;
}
