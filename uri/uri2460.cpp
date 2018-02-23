#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back
using namespace std;

// accepted
int main() {
  int n, m, value;
  vector<pair<int, bool> > mymap;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> value;
    mymap.pb(make_pair(value, true));
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> value;
    find(mymap.begin(), mymap.end(), make_pair(value, true))->second = false;
  }
  bool flag = false;
  for(auto it = mymap.begin(); it != mymap.end(); it++) {
    if(it->second) {
      if(flag)
        cout << " " << it->first;
      else {
        cout << it->first;
        flag = true;
      }
    }
  }
  cout << "\n";

  return 0;
}