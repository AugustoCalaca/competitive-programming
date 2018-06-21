#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int arr[110];

int main() {
  fast();
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = 0;
  for(int i = 0, j = n - 1; i < n && j >= 0; ) {
    if(arr[i] <= k) ans++, i++;
    else if(arr[j] <= k) ans++, j--;
    else break;
  }

  cout << ans << "\n";
  return 0;
}
