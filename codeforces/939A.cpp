#include <iostream>

using namespace std;

// ac
int main() {
  int v[5010], n;

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];

  for(int i = 1;i <= n; i++)
    if(v[v[v[i]]] == i) { cout << "YES\n"; return 0; }

  cout << "NO\n";
  return 0;
}
