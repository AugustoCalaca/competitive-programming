#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// accepted
int binarySearch(vector<int> arr, int search) {
  int begin = 0;
  int end = arr.size() - 1;
  int middle;

  while(begin <= end) {
    middle = begin + (end - begin) / 2;

    if(arr[middle] == search) return middle;
    if(arr[middle] < search) begin = middle + 1;
    else end = middle - 1;
  }

  // chegou aqui não encontrou o numero
}

int main() {
  int n, m;
  int time = 0;
  int previous = 0;

  cin >> n >> m;

  vector<int> houses(n);
  vector<int> package(m);

  for(int i = 0; i < n; i++) cin >> houses[i];

  sort(houses.begin(), houses.end());

  for(int i = 0; i < m; i++) {
    cin >> package[i];

    int index = binarySearch(houses, package[i]);
    time = time + abs(index - previous);
    previous = index;
  }

  cout << time << endl;
  return 0;
}