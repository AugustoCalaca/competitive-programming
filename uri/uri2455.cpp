#include <iostream>

using namespace std;

// accepted
int main() {
  int p1, c1, p2, c2;

  cin >> p1 >> c1 >> p2 >> c2;

  int left = p1 * c1;
  int rigth = p2 * c2;

  if(left > rigth) cout << "-1\n";
  else if(left < rigth) cout << "1\n";
  else cout << "0\n";

  return 0;
}