#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

int binarySearch(vector<int>& arr, int search) {
  int begin = 0;
  int end = arr.size() - 1;
  int middle;

  while(begin <= end) {
    middle = begin + (end - begin) / 2;

    if(arr[middle] == search) return middle;
    if(arr[middle] < search) begin = middle + 1;
    else end = middle - 1;
  }

  return -1;
}

int main() {
  vector<int> arr = {2, 3, 5, 7, 11, 17};
  int search;

  cin >> search;

  int result = binarySearch(arr, search);

  if(result != -1) cout << "Found in position: " << result;
  else cout << "Not found!";
  cout << "\n";

  return 0;
}
