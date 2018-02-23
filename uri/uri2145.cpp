#include <iostream>

using namespace std;
typedef unsigned int ul;

// accepted
ul sumDivisors(ul n) {
  ul sum = 0;
  for(ul i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      if(n / i == i)
        sum += i;
      else {
        sum += (n / i) + i;
      }
    }
  }

  return sum - n;
}

int main() {
  ul n, m;

  while(true) {
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    ul sdn = sumDivisors(n);
    ul sdm = sumDivisors(m);

    if((sdn == m || m % sdn == 0) && (sdm == n || n % sdm == 0))
      cout << "Friends and lovers <3\n";
    else if(sdn == sdm)
      cout << "Almost lovers!\n";
    else if(sdn != sdm && (n % sdm == 0 && m % sdn != 0))
        cout << n << " friendzoned " << m << "!\n";
    else if(sdn != sdm && (m % sdn == 0 && n % sdm != 0))
        cout << m << " friendzoned " << n << "!\n";
    else if(sdn != sdm && (m % sdn != 0 && n % sdm != 0))
      cout << "No connection.\n";
  }


  return 0;
}