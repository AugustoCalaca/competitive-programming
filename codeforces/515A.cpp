#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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

  ll a, b, s;
  cin >> a >> b >> s;
  a = abs(a) + abs(b);
  if(s >= a) {
    if((a & 1 && s & 1) || (!(a & 1) && !(s & 1))) cout << "Yes\n";
    else cout << "No\n";
  }
  else cout << "No\n";
  return 0;
}
