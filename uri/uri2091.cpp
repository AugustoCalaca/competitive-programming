#include <iostream>
#include <map>

#define f first
#define s second
using namespace std;
typedef long long ll;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();

  int n;
  ll v;

  while(true) {
    cin >> n;
    if(!n) break;

    map<ll, ll> m;
    for(int i = 0; i < n; i++) {
      cin >> v;
      m[v]++;
    }

    for(auto it = m.begin(); it != m.end(); it++) {
      if(it->s & 1) {
        cout << it->f << "\n";
        break;
      }
    }
  }

  return 0;
}
