#include <iostream>

using namespace std;
typedef unsigned long long ull;

// accepted
void myfill(ull Pbona[]) {
  for(int i = 3; i < 20; i++) {
    if(i & 1) Pbona[i] = Pbona[i - 1] + Pbona[i - 2];
    else Pbona[i] = Pbona[i - 1] * Pbona[i - 2];
  }
}

int main() {
  int n;
  ull Pbonati[20];

  Pbonati[1] = 0;
  Pbonati[2] = 1;

  myfill(Pbonati);

  while(cin >> n)
    cout << Pbonati[n] << "\n";

  return 0;
}
