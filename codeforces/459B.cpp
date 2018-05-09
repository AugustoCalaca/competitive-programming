#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  ll n, v[1000000];
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);

  cout << v[n - 1] - v[0] << " ";
  if(v[n - 1] == v[0]) {
    cout << (n * n - n) / 2 << "\n";
    return 0;
  }

  ll m = 1;
  for(ll i = 1; v[i] == v[i - 1]; i++, m++) {}
  ll o = 1;
  for(ll j = n - 1; v[j] == v[j - 1]; j--, o++) {}

  cout << m * o << "\n";
  return 0;
}