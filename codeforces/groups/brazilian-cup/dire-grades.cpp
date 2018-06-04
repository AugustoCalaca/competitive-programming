#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>

#define M ((int)1e6 + 10)
#define pb push_back
#define mk make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

double segTree[M] = { 0.0 }; // for sum start whith 0, for max start with INT_MIN
double lazy[M] = { 0.0 };

double sum(double a, double b) { return a + b; }

void constructSegTree(double input[], int low, int hight, int pos = 0) {
  if(low == hight) {
    segTree[pos] = input[low];
    return ;
  }

  int mid = low + (hight - low) / 2;

  constructSegTree(input, low, mid, 2 * pos + 1);
  constructSegTree(input, mid + 1, hight, 2 * pos + 2);
  segTree[pos] = sum(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

double sumQuery(int qlow, int qhight, int low, int hight, int pos = 0) {
  if(lazy[pos] != 0) {
    segTree[pos] += lazy[pos];
    if(low != hight) {
      lazy[2 * pos + 1] += lazy[pos];
      lazy[2 * pos + 2] += lazy[pos];
    }
    lazy[pos] = 0.0;
  }

  // total overlap
  if(qlow <= low && qhight >= hight)
    return segTree[pos];
  // no overlap
  if(qlow > hight || qhight < low)
    return 0;
  // partil overlap
  int mid = low + (hight - low) / 2;
  return sum(sumQuery(qlow, qhight, low, mid, 2 * pos + 1),
             sumQuery(qlow, qhight, mid + 1, hight, 2 * pos + 2));
}

void lazyPropagation(int qlow, int qhight, int low, int hight, double update,
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
    segTree[pos] = update;
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
  segTree[pos] = sum(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int main() {
  fast();

  double input[M], val;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> input[i];

  constructSegTree(input, 0, n - 1);
  cout.precision(6);
  cout << fixed;

  int q, t, l, r;
  cin >> q;
  while(q--) {
    cin >> t;
    if(t == 1) {
      cin >> l >> val;
      lazyPropagation(l - 1, l - 1, 0, n - 1, val);
    }
    else if(t == 2) {
      cin >> l >> r;
      cout << sumQuery(l - 1, r - 1, 0, n - 1) / (r - l + 1) << "\n";
    }
  }

  return 0;
}
