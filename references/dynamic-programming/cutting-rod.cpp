#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int cuttingRod(vector<int> prizes, int len) {
  int sz = prizes.size();
  int pd[sz + 1][len + 1];

  for(int i = 0; i <= sz; i++) pd[i][0] = 0;
  for(int i = 0; i <= len; i++) pd[0][i] = 0;

  for(int i = 1; i <= sz; i++) {
    for(int j = 1; j <= len; j++) {
      if(j >= i) pd[i][j] = max(prizes[i - 1] + pd[i][j - i], pd[i - 1][j]);
      else pd[i][j] = pd[i - 1][j];
    }
  }

  return pd[sz][len];
}

int main() {
  vector<int> prizes = { 2, 5, 7, 8 };
  cout << cuttingRod(prizes, 5) << "\n";

  return 0;
}