#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back
using namespace std;

vector<int> primeFactors(int n) {
  vector<int> result;

  for(; n % 2 == 0; n /= 2)
    result.pb(2);

  for(int i = 3; i*i <= n; i += 2)
    for(; n % i == 0; n /= i)
      result.pb(i);

  // case when n is prime number greater than 2
  if(n > 2) result.pb(n);

  return result;
}
