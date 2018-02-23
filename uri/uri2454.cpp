#include <iostream>

using namespace std;

// accepted
int main() {
  int p, r;

  cin >> p >> r;

  if(!p) cout << "C\n";
  else if(p && !r) cout << "B\n";
  else if(p && r) cout << "A\n";

  return 0;
}