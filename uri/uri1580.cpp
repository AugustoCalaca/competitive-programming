#include <iostream>
#include <string>
#include <map>

#define MOD 1000000007
#define MAX 1010
using namespace std;

// accepted
long long int fat[MAX];

void fatorial() {
  fat[0] = fat[1] = 1;

  for(int i = 2; i < MAX; i++) {
    fat[i] = (i  * fat[i - 1]) % MOD;
  }
}

int modularInverse(long long accum, long long k) {
  long long int ans = 1;

  while(k > 0) {
    if(k & 1) ans = (ans * accum) % MOD;
    k >>= 1;
    accum = (accum * accum) % MOD;
  }

  return ans;
}

int main() {
  string str;

  cin.tie(NULL);
  cout.sync_with_stdio(false);

  fatorial();

  while(cin >> str) {
    map<char, int> m;

    for(auto &i : str)
      m[i]++;

    long long int accum = 1;
    for(auto &it : m) {
        accum = (accum * fat[it.second]) % MOD;

    cout << (fat[str.size()] * modularInverse(accum, MOD - 2)) % MOD << "\n";
  }

  return 0;
}
