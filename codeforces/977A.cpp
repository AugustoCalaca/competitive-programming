#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}


int main() {
  fast();
  int a, b;

  cin >> a >> b;

  for(int i = 0; i < b; i++) {
    if(a % 10 == 0) a /= 10;
    else a -= 1;
  }

  cout << a << "\n";
  return 0;
}
