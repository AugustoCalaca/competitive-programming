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

int gcd(int a, int b) {
  while(b) {
    a %= b;
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return a;
}

int lcd(int a, int b) {
  return a * b / gcd(a, b);
}

int main() {
  int n, m;
  scanf("%d.%d", &n, &m);

  int l = n * 100 + m;
  printf("%d\n", lcd(360 * 100, l) / l);
  return 0;
}
