#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// accepted
int vn[1010];

int main() {
  int n, m;

  cin >> n >> m;

  for(int i = 0; i < n; i++)
    cin >> vn[i];

  int count = 0;
  for(int i = 0; i + 1 < n; i++) {
    if(vn[i] == m) {}
    else {
      int dif = abs(m - vn[i]);
      count += dif;
      if(vn[i] < m) {
        vn[i] += dif;
        vn[i + 1] += dif;
      }
      else {
        vn[i] -= dif;
        vn[i + 1] -= dif;
      }
    }
  }
    cout << count << endl;

  return 0;
}