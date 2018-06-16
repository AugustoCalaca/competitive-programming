#include <iostream>
#include <algorithm>
#include <cmath>
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

  string s, a;
  cin >> s;
  s += "WUB";
  a = "";
  for(size_t i = 0; i < s.size() - 3; i += 3) {
    if(s.substr(i, 3) != "WUB") {
      while(s.substr(i, 3) != "WUB") {
        a += s[i];
        i++;
      }
      a += " ";
    }
  }

  cout << a << "\n";
  return 0;
}
