#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

// ac
int main() {
  fast();

  int v[5];

  for(int i = 0; i < 3; i++)
    cin >> v[i];
  int c = count(v, v + 3, 1);
  if(!c)
    cout << v[0] * v[1] * v[2] << "\n";
  else if(v[0] == 1 && v[2] == 1)
     cout << v[0] + v[1] + v[2] << "\n";
  else if(c == 1) {
    if(v[0] == 1) cout << (v[0] + v[1]) * v[2] << "\n";
    else if(v[2] == 1) cout << (v[1] + v[2]) * v[0] << "\n";
    else if(v[1] == 1) cout << max((v[0] + v[1]) * v[2], v[0] * (v[1] + v[2])) << "\n";
  } else cout << *max_element(v, v + 3) * 2 << "\n";




  return 0;
}
