#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

set<string> s;
string str, str2;

string arroba(int j) {
  while(str[j] != '@') j++;
  return str.substr(j);
}

int main() {
  FAST;
  int n;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str;

    str2 = "";
    for(size_t j = 0; j < str.size(); j++) {
      if(str[j] == '+') {
        str2 += arroba(j);
        break;
      }
      if(str[j] != '.') str2 += str[j];
      if(str[j] == '@') {
        str2 += str.substr(j + 1);
        break;
      }
    }

    s.insert(str2);
  }

  cout << s.size() << "\n";
  return 0;
}
