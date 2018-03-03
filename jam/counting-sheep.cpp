#include <iostream>
#include <string>
#include <climits>
#include <set>

using namespace std;
typedef long long ll;

// ac
set<int> st;

bool dig(ll n) {
  for(; n > 0; n /= 10)
    st.insert(n % 10);

  if(st.size() == 10) return true;
  else return false;
}

int main() {
  int t;
  ll n, tmp;
  string ans;

  cin >> t;
  for(int i = 0; i < t; ) {
    cin >> n;

    if(n == 0) ans = "INSOMNIA";
    else {
      tmp = n;
      for(ll j = 2; ; j++) {
        if(dig(tmp)) break;
        tmp = n * j;
      }
      ans = to_string(tmp);
    }

    cout << "Case #" << ++i << ": " << ans << "\n";
    st.clear();
  }

  return 0;
}
