#include <iostream>

using namespace std;
typedef long double ld;

// accepted
int main() {
  ld a, b;
  int i = 0;

  cout.precision(2);
  cout << fixed;
  while(cin >> a >> b)
    cout << "Projeto " << ++i << ":\n"
         << "Percentual dos juros da aplicacao: "
         << (b - a) * 100 / a << " %\n\n";

  return 0;
}
