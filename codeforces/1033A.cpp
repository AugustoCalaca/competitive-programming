#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int q[4], q2[4];
int main() {
  FAST;

  int n, ax, ay, bx, by, cx, cy;
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

  if(bx >= 1 && bx < ax && by >= 1 && by < ay) q[0] = 1;
  if(cx >= 1 && cx < ax && cy >= 1 && cy < ay) q2[0] = 1;

  if(bx > ax && bx <= n && by >= 1 && by < ay) q[1] = 1;
  if(cx > ax && cx <= n && cy >= 1 && cy < ay) q2[1] = 1;

  if(bx > ax && bx <= n && by > ay && by <= n) q[2] = 1;
  if(cx > ax && cx <= n && cy > ay && cy <= n) q2[2] = 1;

  if(bx >= 1 && bx < ax && by > ay && by <= n) q[3] = 1;
  if(cx >= 1 && cx < ax && cy > ay && cy <= n) q2[3] = 1;

  for(int i = 0; i < 4; i++)
    if(q[i] == 1 && q2[i] == 1) return cout << "YES\n", 0;

  return cout << "NO\n", 0;
}
