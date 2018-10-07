#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 1000010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ans[MAX], v[MAX], ptr = 0;

void solve(int n, int val) {
  if(n == 1) {
    ans[ptr++] = val;
    return ;
  }
  if(n == 2) {
    ans[ptr++] = val;
    ans[ptr++] = val * 2;
    return ;
  }
  if(n == 3) {
    ans[ptr++] = val;
    ans[ptr++] = val;
    ans[ptr++] = val * 3;
    return ;
  }
  for(int i = 0; i < n; i++)
    if(v[i] & 1)
      ans[ptr++] = val;
  for(int i = 0; i < n / 2; i++)
    v[i] = v[2 * i + 1] / 2;
  solve(n / 2, val * 2);
}

int main() {
  FAST;

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) v[i] = i + 1;
  solve(n, 1);
  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
