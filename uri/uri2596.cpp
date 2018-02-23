#include <iostream>

using namespace std;

// accepted
int balls[1010];

void solve() {
  balls[0] = 0;
  for(int j = 1; j < 1010; j++) {
    int cont = 0;
    for(int i = 1; i * i <= j; i++){
      if(j % i == 0) {
        if(j / i == i) cont++;
        else cont += 2;
      }
    }
    balls[j] = !(cont & 1) ? balls[j - 1] + 1: balls[j - 1];
  }
}

int query(int n) {
  return balls[n];
}

int main() {
  int t, n;

  cin >> t;
  solve();

  while(t--) {
    cin >> n;
    cout << query(n) << "\n";
  }

  return 0;
}