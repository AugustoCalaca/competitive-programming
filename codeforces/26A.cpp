#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 3010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> primes;
vector<bool> marked(MAX, true);
void sieve() {
  for(int i = 2; i * i < MAX; i++)
    for(int j = i * i; j < MAX; j += i)
      if(marked[j])
        marked[j] = false;

  for(int i = 2; i < MAX; i++)
    if(marked[i])
      primes.pb(i);
}

bool almost(int n) {
  int ans = 0;
  for(int i = 0; primes[i] * primes[i] <= n; i++) {
    int c = 0;
    for(; n % primes[i] == 0; n /= primes[i], c++) {}
    if(c) ans++;
  }
  if(n > 1) ans++;
  return ans == 2;
}

int solve(int n) {
  if(n < 6) return 0;

  int ans = 1; // 1 at 9 -> 6 almost
  for(int i = 10; i <= n; i++)
    if(almost(i)) ans++;

  return ans;
}

int main() {
  FAST;

  sieve();

  int n;
  cin >> n;
  cout << solve(n) << "\n";
  return 0;
}
