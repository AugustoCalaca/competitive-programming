#include <iostream>
#include <algorithm>
#include <cmath>
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
  string s, aux, temp;
  cin >> n >> s;

  for(int i = 1; i < n; i++) {
    temp = "";
    if(n % (i + 1) == 0) {
      for(int j = i + 1; j < n; j++) temp += s[j];
      aux = s.substr(0, i + 1);
      reverse(aux.begin(), aux.end());
      s = aux + temp;
    }
  }

  cout << s << "\n";
  return 0;
}
