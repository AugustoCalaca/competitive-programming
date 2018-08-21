#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 400010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll st[MAX] = { 0 };
int input[MAX];

ll sum(ll a, ll b) { return a + b; }

void build(int low, int hight, int pos = 0) {
  if(low == hight) {
    st[pos] = input[low];
    return ;
  }

  int md = low + (hight - low) / 2;
  build(low, md, 2 * pos + 1);
  build(md + 1, hight, 2 * pos + 2);
  st[pos] = sum(st[2 * pos + 1], st[2 * pos + 2]);
}

void update(int qlow, int qhight, int low, int hight, int up, int pos = 0) {
  if(qlow <= low && qhight >= hight) {
    st[pos] = up;
    return ;
  }

  if(qlow > hight || qhight < low) return ;

  int md = low + ( hight - low) / 2;
  update(qlow, qhight, low, md, up, 2 * pos + 1);
  update(qlow, qhight, md + 1, hight, up, 2 * pos + 2);
  st[pos] = sum(st[2 * pos + 1], st[2 * pos + 2]);
}

ll query(int qlow, int qhight, int low, int hight, int pos = 0) {
  if(qlow <= low && qhight >= hight) return st[pos];
  if(qlow > hight || qhight < low) return 0;

  int md = low + (hight - low) / 2;
  return sum(query(qlow, qhight, low, md, 2 * pos + 1),
             query(qlow, qhight, md + 1, hight, 2 * pos + 2));
}

int main() {
  FAST;

  int n, q;
  char ch;

  cin >> n;
  input[0] = 0;
  for(int i = 1; i <= n; i++) cin >> input[i];
  build(0, n);

  while(cin >> ch >> q) {
    if(ch == 'a')
      update(q, q, 0, n, 0);
    else cout << query(1, q - 1, 0, n) << "\n";
  }
  return 0;
}
