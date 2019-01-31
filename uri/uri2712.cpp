#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  string str;
  int n;
  for(cin >> n; n--; ) {
    cin >> str;

    int sz = str.size();
    bool ok = (sz == 8 && str[3] == '-');

    for(int i = 0; i < sz; i++) {
      if(i < 3 && (str[i] < 'A' || str[i] > 'Z')) {
        ok = false;
        break;
      }
      if(i > 3 && (str[i] < '0' || str[i] > '9')) {
        ok = false;
        break;
      }
    }

    char ch = str[7];
    if(ok) {
      if(ch == '1' || ch == '2') cout << "MONDAY\n";
      else if(ch == '3' || ch == '4') cout << "TUESDAY\n";
      else if(ch == '5' || ch == '6') cout << "WEDNESDAY\n";
      else if(ch == '7' || ch == '8') cout << "THURSDAY\n";
      else if(ch == '9' || ch == '0') cout << "FRIDAY\n";
    } else cout << "FAILURE\n";
  }

  return 0;
}
