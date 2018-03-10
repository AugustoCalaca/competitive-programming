#include <iostream>

using namespace std;

// ac
int v[110];

int main() {
  int n, b = 0, c = 0;

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] >= 0) b += v[i];
    else c += v[i];
  }

  cout << b - c << endl;

  return 0;
}
