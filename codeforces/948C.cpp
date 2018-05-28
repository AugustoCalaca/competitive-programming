#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define pb push_back
using namespace std;
typedef long long ll;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

vector<ll> v;
vector<ll> t;
multiset<ll> snow;
//  ac
int main() {
  int n;
  ll val;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> val;
    v.pb(val);
  }
  for(int i = 0; i < n; i++) {
    cin >> val;
    t.pb(val);
  }

  ll sum = 0;
  for(int i = 0; i < n; i++) {
    ll ans = 0;
    snow.insert(v[i] + sum);
    while(!snow.empty()) {
      ll key = *snow.begin();
      if(key <= sum + t[i]) {
        ans += (key - sum);
        snow.erase(snow.find(key));
      } else break;
    }

    sum += t[i];
    cout << ans + t[i] * (ll)snow.size() << " ";
  }

  cout << "\n";
  return 0;
}