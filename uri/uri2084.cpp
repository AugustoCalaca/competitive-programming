#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int main() {
  int n;
  float sum = 0;
  float v[12];
  float v2[12];

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }

  sort(v, v + n);

  bool ok = true;
  for(int i = n - 1; i >= 0; i--) {
    v2[i] = v[i] * 100 / sum;
    if(v2[i] >= 45.0) {
      cout << "1\n";
      ok = false;
      break;
    }
  }

  if(!ok) return 0;

  if(v2[n - 1] - v2[n - 2] >= 10.0)
    cout << "1\n";
  else
    cout << "2\n";

  return 0;
}
