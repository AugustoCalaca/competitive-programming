#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

#define M (int)1e5
using namespace std;

int segTree[M] = { INT_MAX }; // for sum start with 0, for max start with INT_MIN
int lazy[M] = { 0 };

void constructSegTree(int input[], int low, int hight, int pos = 0) {
  if(low == hight) {
    segTree[pos] = input[low];
    return ;
  }

  int mid = low + (hight - low) / 2;

  constructSegTree(input, low, mid, 2 * pos + 1);
  constructSegTree(input, mid + 1, hight, 2 * pos + 2);
  segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int rangeMinQuery(int qlow, int qhight, int low, int hight, int pos = 0) {
  if(lazy[pos] != 0) {
    segTree[pos] += lazy[pos];
    if(low != hight) {
      lazy[2 * pos + 1] += lazy[pos];
      lazy[2 * pos + 2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  // total overlap
  if(qlow <= low && qhight >= hight)
    return segTree[pos];
  // no overlap
  if(qlow > hight || qhight < low)
    return INT_MAX;
  // partil overlap
  int mid = low + (hight - low) / 2;
  return min(rangeMinQuery(qlow, qhight, low, mid, 2 * pos + 1),
             rangeMinQuery(qlow, qhight, mid + 1, hight, 2 * pos + 2));
}

void lazyPropagation(int qlow, int qhight, int low, int hight, int update,
                     int pos = 0) {
  if(lazy[pos] != 0) {
    segTree[pos] += lazy[pos];
    if(low != hight) {
      lazy[2 * pos + 1] += lazy[pos];
      lazy[2 * pos + 2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  // total overlap
  if(qlow <= low && qhight >= hight) {
    segTree[pos] += update;
    if(low != hight) {
      lazy[2 * pos + 1] += update;
      lazy[2 * pos + 2] += update;
    }
    return ;
  }

  // no overlap
  if(qlow > hight || qhight < low) { return ; }

  // partial overlap
  int mid = low + (hight - low) / 2;
  lazyPropagation(qlow, qhight, low, mid, update, 2 * pos + 1);
  lazyPropagation(qlow, qhight, mid + 1, hight, update, 2 * pos + 2);
  segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int main() {
  int input[] = {};
  int szInput; // size of array input
  int low = 0, hight = szInput - 1;
  int szSegTree = 2 * (int)pow(2, ceil(log2(szInput))) - 1; // size of segment tree

  return 0;
}