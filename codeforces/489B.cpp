#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int boys[110];
int girls[110];

int main() {
  fast();
  int n, m;

  cin >> n;
  for(int i = 0; i < n; i++) cin >> boys[i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> girls[i];

  sort(boys, boys + n);
  sort(girls, girls + m);

  int ans = 0;
  for(int i = 0, j = 0; i < n && j < m;) {
    int a = abs(boys[i] - girls[j]);
    if(a > 1) boys[i] < girls[j] ? ++i : ++j;
    else {
      ans++;
      ++i, ++j;
    }
  }

  cout << ans << "\n";
  return 0;
}
