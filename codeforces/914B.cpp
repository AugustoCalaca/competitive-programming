#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int main() {
  int n, max = 0;

  int v[100100];

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] > max) max = v[i];
  }

  sort(v, v + n);

  int i = n - 1;
  int j = i;
  while(i >= 0) {
    int ans = 0;
    for(; v[i] == v[j] && i >= 0; i--, ans++) {}
    j = i;
    if(ans & 1) {
      cout << "Conan\n";
      return 0;
    }
  }

  cout << "Agasa\n";
  return 0;
}
