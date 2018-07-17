#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// range min query
// int table[n][(int)floor(log2(n)) + 1];
int table[6][3];

int query(int l, int r) {
  int h = r - l + 1;
  int k = (int)floor(log2(h));

  return min(table[l][k], table[l + h - (1 << k)][k]);
}

int main() {
  int input[] = { 4, 6, 1, 5, 7, 3 };
  int n = sizeof(input) / sizeof(input[0]);

  // build
  for(int i = 0; i < n; i++)
    table[i][0] = input[i];

  for(int j = 1; (1 << j) <= n; j++)
    for(int i = 0; i + (1 << (j - 1)) <= n; i++)
      table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);

  cout << query(0, 5) << "\n";
  cout << query(3, 5) << "\n";
  cout << query(2, 4) << "\n";
  cout << query(4, 4) << "\n";
  cout << query(0, 1) << "\n";
}