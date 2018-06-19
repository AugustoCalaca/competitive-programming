#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>

#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

ll arr[110010];
ll ans[110010];
map<ll, pair<ll, ll> > m;

int main() {
  fast();

  int n, k, v;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  for(int i = 0; i < n; i++) {
    cin >> v;
    m.insert({ arr[i], { v, i } });
  }

  multiset<ll> st;
  for(auto it = m.begin(); it != m.end(); it++) {
    ans[it->s.s] = it->s.f;
    auto it2 = st.end();
    for(int j = 0; j < (int)st.size(); j++)
      ans[it->s.s] += *(--it2);
    st.insert(it->s.f);
    if((int)st.size() > k) st.erase(st.begin());
  }

  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
