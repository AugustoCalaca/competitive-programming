#include <iostream>
#include <set>

using namespace std;

void powerset(int arr[], set<int>& x, int n, int begin) {
  for(int i = 0; i < (1 << n); i++) {
    int s = 0;
    for(int j = 0; j < n; j++)
      if(i & (1 << j))
        s += arr[j + begin];
    x.insert(s);
  }
}

// O(n * 2 ^ (n / 2))
bool meetmiddle(int arr[], int n, int sum) {
  set<int> x;
  set<int> y;
  powerset(arr, x, n / 2, 0);
  powerset(arr, y, n - n / 2, n / 2);

  for(auto it = x.begin(); it != x.end(); it++) {
    auto it2 = y.find(sum - *it);
    if(it2 != y.end())
      return true;
  }

  return false;
}

int main() {
  int arr[] = { 2, 3, 4, 5 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int sum = 15;

  if(meetmiddle(arr, n, sum)) cout << "Found\n";
  else cout << "No Found\n";
  return 0;
}
