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
typedef pair<int, string> pis;

bool comp(pis& a, pis& b) {
  if(a.f == b.f) return a.s < b.s;
  return a.f > b.f;
}

int main() {
  FAST;

  vector<pis> vec;
  int n, m;
  string str;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str >> m;
    vec.pb({ m, str });
  }

  sort(vec.begin(), vec.end(), comp);
  for(auto i : vec) 
    cout << i.s << " " << i.f << "\n";

  return 0;
}
