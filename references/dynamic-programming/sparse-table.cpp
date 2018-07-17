#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// range min query
// range sum query

// int table[n][(int)floor(log2(n)) + 1];
int table[6][3];

int func(int a, int b) {
  return min(a, b); // for range min query
  // return a + b;     // for range sum query
}

// O(log n)
int sumquery(int l, int r, int n) {
  int k = (int)floor(log2(n));

  int sum  = 0;
  for(int j = k; j >= 0; j--)
    if((1 << j) <= r - l + 1) {
      sum += table[l][j];
      l += (1 << j);
    }

  return sum;
}

// O(1)
int minquery(int l, int r) {
  int h = r - l + 1;
  int k = (int)floor(log2(h)); // here 'h' and no 'n'

  return func(table[l][k], table[l + h - (1 << k)][k]);
}

int main() {
  int input[] = { 4, 6, 1, 5, 7, 3 };
  int n = sizeof(input) / sizeof(input[0]);

  // build
  for(int i = 0; i < n; i++)
    table[i][0] = input[i];

  for(int j = 1; (1 << j) <= n; j++)
    for(int i = 0; i + (1 << (j - 1)) <= n; i++)
      table[i][j] = func(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);

  // cout << sumquery(0, 3, n) << "\n";
  // cout << sumquery(0, 5, n) << "\n";
  cout << minquery(0, 1) << "\n";
  cout << minquery(3, 4) << "\n";
  cout << minquery(4, 5) << "\n";
}