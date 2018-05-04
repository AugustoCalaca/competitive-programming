#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

vector<long long> sieveEratostenes(long long n) {
  vector<bool> marked(n + 1, true);
  vector<long long> primes;

  for(long long i = 2; i * i <= n; i++)
    if(marked[i])
      for(long long j = i * 2; j <= n; j += i)
        marked[j] = false;

  for(long long i = 2; i <= n; i++)
    if(marked[i] == true)
      primes.pb(i);

  return primes;
}

int main() {
  long long n;

  cin >> n;

  vector<long long> result = sieveEratostenes(n);

  for(auto& show : result)
    cout << " " << show;
  cout << endl;

  return 0;
}

