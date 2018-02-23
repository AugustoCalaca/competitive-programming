#include <iostream>
#include <string>

using namespace std;
typedef unsigned long long ull;

// accepted
ull fat(int n, int k) {
  ull ans = n;
  for(int i = 1; n - i * k > 1; i++) {
    ans *= (n - i * k);
  }
  return ans;
}

int main() {
  int t, n;
  string str;

  for(cin >> t; t--;) {
    cin >> n >> str;
    int k = str.size();
    cout << fat(n, k) << endl;
  }

  return 0;
}
