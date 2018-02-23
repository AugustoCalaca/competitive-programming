#include <iostream>

using namespace std;
typedef long long ll;

// accepted
// ultimos digitos de 1! até 9!
ll lstDig[] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8 };

ll lastDigit(int n) {
  if(n < 10) return lstDig[n];

  if(((n / 10) % 10) & 1)
    return (4 * lastDigit(n / 5) * lstDig[n % 10]) % 10;
  else
    return (6 * lastDigit(n / 5) * lstDig[n % 10]) % 10;
}

int main() {
  ll n, k = 1;

  while(cin >> n) {
    cout << "Instancia "
         << k << "\n"
         << lastDigit(n) << "\n\n";
    k++;
  }

  return 0;
}
