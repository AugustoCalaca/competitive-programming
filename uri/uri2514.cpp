#include <iostream>

using namespace std;
typedef long long ll;

// accepted
ll gcd(ll a, ll b) {
  while(b > 0) {
    a %= b;
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return a;
}

ll lcd(ll a, ll b) {
  return a * b / gcd(a, b);
}


int main() {
  ll l1, l2, l3, m;

  while(cin >> m >> l1 >> l2 >> l3)
    cout << lcd(l1, lcd(l2, l3)) - m << "\n";

  return 0;
}