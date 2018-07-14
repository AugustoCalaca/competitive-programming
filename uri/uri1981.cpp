#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define M 100000007
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll fexp(ll b, ll e) {
  ll ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) ans = (ans % M * b % M) % M;
    b = (b % M * b % M) % M;
  }

  return ans;
}

ll v[10010] = { 0 };

void fat() {
  v[1] = 1;

  for(int i = 2; i < 10001; i++)
    v[i] = (v[i - 1] % M * i % M) % M;
}

int main() {
  FAST;

  fat();
  string str;

  while(true) {
    cin >> str;
    if(str == "0") break;

    map<char, int> m;

    int sz = str.size();
    for(int i = 0; i < sz; i++)
      m[str[i]]++;

    ll denom = 1;
    for(auto it = m.begin(); it != m.end(); it++)
      denom = (v[it->s] % M * denom % M) % M;

    cout << (v[sz] % M * fexp(denom, M - 2) % M) % M << "\n";
  }

  return 0;
}
