#include <iostream>
#include <string>

using namespace std;

// ac
int v[100010];
int v2[100010];

int main() {
  int n, x, y, c;
  string s;

  cin >> n >> s;

  x = y = c = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'R') x++;
    else if(s[i] == 'U') y++;
    v[i] = x;
    v2[i] = y;
  }

  for(int i = 1; i < n - 1; i++)
    if(v[i] == v2[i] && (v[i - 1] == v[i + 1] || v2[i - 1] == v2[i + 1]))
      c++;
  cout << c << endl;

  return 0;
}
