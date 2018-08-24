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

int main() {
  FAST;

  string v[5];
  string s;
  for(int i = 0; i < 4; i++) {
    cin >> s;
    v[i] = s;
  }

  int val[85], sz = s.size();
  for(int j = 0; j < sz; j++) {
    int n = 1000;
    val[j] = 0;
    for(int i = 0; i < 4; i++, n /= 10)
      val[j] += (v[i][j] - '0') * n;
  }

  for(int i = 1; i + 1 < sz; i++)
    cout << char((val[0] * val[i] + val[sz - 1]) % 257);
  cout << "\n";
  return 0;
}
