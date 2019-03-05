#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int t; 
  string str;

  for(cin >> t; t--; ) {
    set<char> st;
    bool ok = true;
    cin >> str;
    for(auto i : str) st.insert(i);
    
    cin >> str;
    for(auto i : str) 
      if(st.find(i) != st.end()) {
        cout << "YES\n";
        ok = false;
        break;
      }
    
    if(ok) cout << "NO\n";
  }
  
  return 0;
}
