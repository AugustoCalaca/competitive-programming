#include <iostream>
#include <vector>
#include <algorithm>

#define f first
#define s second
#define pb push_back

using namespace std;

int main() {
  int n, a, b;
  vector<pair<int, int> > v;
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.pb({ a, b });
  }
  
  sort(v.begin(), v.end());
  for(auto it = v.begin(); it != --v.end(); it++) {
    if(it->s > (it + 1)->s) {
      cout << "Happy Alex\n";
      return 0;
    }
  }
  
  cout << "Poor Alex\n";
  return 0;
}
