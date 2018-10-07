#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> primes(MAX, 2);
vector<bool> marked(MAX, true);
void sieve() {
  for(int i = 2; i * i < MAX; i++)
    for(int j = i * i; j < MAX; j += i)
      if(marked[j])
        marked[j] = false;

  for(int i = 2; i < MAX; i++)
    if(marked[i])
      primes[i] = 1;
}

int main() {
  FAST;

  sieve();
  int n;
  cin >> n;
  if(n <= 2) cout << "1\n";
  else       cout << "2\n";

  for(int i = 2; i <= n + 1; i++)
    cout << primes[i] << " ";
  cout << "\n";
  return 0;
}
