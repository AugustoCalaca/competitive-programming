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

  vector<string> v = { "oitavas\n", "quartas\n", "semifinal\n", "final\n" };
  int k, l;
  cin >> k >> l;

  for(int i = 0, p = 2; i < 4; i++, p <<= 1)
    if((k - 1) / p == (l - 1) / p) return cout << v[i], 0;

  return 0;
}
