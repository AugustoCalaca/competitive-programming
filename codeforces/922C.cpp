#include <iostream>
#include <vector>
#include <set>

#define pb push_back
using namespace std;

// accepted
typedef unsigned long long ull;
int main() {
  ull n, k;
  vector<ull> v;
  set<ull> s;

  cin >> n >> k;
  bool flag = k & 1 ? true : false;

  for(ull i = 1; i <= k / 2; i++) {
    int tmp1 = n % i;
    int tmp2 = n % (k - i + 1);

    v.pb(tmp1);
    v.pb(tmp2);
    s.insert(tmp1);
    s.insert(tmp2);

    if(v.size() != s.size()) break;
  }

  if(flag) {
    int tmp = n % ((k / 2) + 1);
    v.pb(tmp);
    s.insert(tmp);
  }

  if(v.size() == s.size()) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}
