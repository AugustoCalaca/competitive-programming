#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

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
  map<string, string> m;
  m["purple"] = "Power";
  m["green"] = "Time";
  m["blue"] = "Space";
  m["orange"] = "Soul";
  m["red"] = "Reality";
  m["yellow"] = "Mind";

  int n;
  string s;
  cin >> n;
  cout << 6 - n << "\n";
  while(n--) {
    cin >> s;
    m.erase(m.find(s));
  }

  for(auto it = m.begin(); it != m.end(); it++)
    cout << it->second << "\n";
  return 0;
}
