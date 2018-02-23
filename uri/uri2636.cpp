#include <iostream>
#include <vector>

#define pb push_back
using namespace std;
typedef unsigned long long int ll;

// accepted
vector<ll> primeFactors(ll number) {
  vector<ll> ans;

  for(; number % 2 == 0; number /= 2)
    ans.pb(2);

  for(ll i = 3; i*i <= number; i += 2)
    for(; number % i == 0; number /= i)
      ans.pb(i);

  if(number > 2) ans.pb(number);

  return ans;
}

int main() {
  ll number;

  while(true) {
    cin >> number;

    if(number == 0) break;

    vector<ll> ans = primeFactors(number);

    cout << number << " = ";
    for(auto it = ans.begin(); it != ans.end(); it++) {
      cout << *it;
      if(it != ans.end() - 1)
        cout << " x ";
    }
    cout << "\n";
  }

  return 0;
}
