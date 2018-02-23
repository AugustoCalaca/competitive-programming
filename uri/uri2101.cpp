#include <iostream>

#define M 1713371337
using namespace std;

// accepted
typedef long long int ll;

ll gcd(ll a, ll b) {
  while(b > 0) {
    a %= b;

    a = ((a % M) ^ (b % M)) % M;
    b = ((b % M) ^ (a % M)) % M;
    a = ((a % M) ^ (b % M)) % M;
  }

  return a;
}

ll lcd(ll n, ll m) {
  return ((n % M) * (m % M)) / gcd(n, m) % M;
}

int main() {
  ll n, m;

  while(true) {
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    cout << lcd(n, m) << "\n";
  }

  return 0;
}
