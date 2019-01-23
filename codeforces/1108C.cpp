#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n;
  string s, s2, aux = "BGR";

  cin >> n >> s;
  s2 = s;

  int ans = n + 1;
  do {
    int temp = 0;
    for(int i = 0; i < n; i++)
      if(aux[i % 3] != s2[i])
        temp++;
    if(temp < ans) {
      ans = temp;
      for(int i = 0; i < n; i++)
        s[i] = aux[i % 3];
    }
  } while(next_permutation(aux.begin(), aux.end()));

  cout << ans << "\n" << s << "\n";
  return 0;
}
