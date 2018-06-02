#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();
  int n;
  string str;
  multimap<int, string> s;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str;
    s.insert({ str.size(), str});
  }

  vector<string> vec;
  for(auto it = s.begin(); it != s.end(); it++)
    vec.pb(it->second);

  auto it2 = vec.begin();
  for(auto it = it2++; it2 != vec.end(); it++, it2++) {
    auto i = it2->find(*it);
    if(i == string::npos) {
        cout << "NO\n";
        return 0;
      }
  }

  cout << "YES\n";
  for(auto it = s.begin(); it != s.end(); it++)
    cout << it->second << "\n";

  return 0;
}
