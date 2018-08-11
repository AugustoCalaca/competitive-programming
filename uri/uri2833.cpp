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

const int N = 16;
int v[N], deaph[N], graph[2 * N];

int func(int a, int b) {
  if(a == 9 || a == 1) return a;
  if(b == 9 || b == 1) return b;
  return min(a, b);
}

void construct(int low, int hight, int pos = 0) {
  if(low == hight) {
      graph[pos] = v[low];
      return ;
    }

  int mid = low + (hight - low) / 2;
  construct(low, mid, 2 * pos + 1);
  construct(mid + 1, hight, 2 * pos + 2);
  graph[pos] = func(graph[2 * pos + 1], graph[2 * pos + 2]);
}

int main() {
  FAST;

  vector<string> vec = {
    "final\n",
    "semifinal\n",
    "quartas\n",
    "oitavas\n",
  };

  for(int i = 0; i < N; i++) {
    cin >> v[i];
    deaph[i] = -1;
  }

  construct(0, N - 1);

  for(int i = 0; i < 2 * N; i++) {
    if(graph[i] == 9 || graph[i] == 1) {
      if(graph[2 * i + 1] == 9 || graph[2 * i + 1] == 1)
        if(graph[2 * i + 2] == 9 || graph[2 * i + 2] == 1)
          cout << vec[floor(log2(i + 1))];
    }
  }

  return 0;
}
