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
