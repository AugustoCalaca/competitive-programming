#include <iostream>

#define TEN 10
#define M 60
#define H 24
using namespace std;

// accepted
bool hasSeven(int n) {
  int rest;

  for(; n; n = n / TEN) {
    rest = n % TEN;
    if(rest == 7) return true;
  }

  return false;
}

int main() {
  int c = 0, x, hh, mm;

  cin >> x >> hh >> mm;

  for(; true; c++) {
    if(hasSeven(mm)) break;
    if(hasSeven(hh)) break;

    mm -= x;
    if(mm < 0) {
      mm += M;
      hh -= 1;
      if(hh < 0) hh += H;
    }
  }

  cout << c << "\n";

  return 0;
}
