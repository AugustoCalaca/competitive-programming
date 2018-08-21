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

  int n, la, lb, sa, sb;
  cin >> n >> la >> lb >> sa >> sb;
  if(n >= la && n <= lb && n >= sa && n <= sb)
    cout << "possivel\n";
  else
    cout << "impossivel\n";
  return 0;
}
