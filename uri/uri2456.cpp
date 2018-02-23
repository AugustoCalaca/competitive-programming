#include <iostream>

using namespace std;

int v[15];

// accepted
int main() {
  int i = 0;
  int j = 0;

  for(; cin >> v[i]; i++) {}
  for(; (v[j + 1] > v[j]) && j + 1 < i; j++) {}
  if(j + 1 == i) {
    cout << "C\n";
    return 0;
  }
  for(j = 0; (v[j + 1] < v[j]) && j + 1 < i; j++) {}
  if(j + 1 == i) {
    cout << "D\n";
     return 0;
  }

  cout << "N\n";

  return 0;
}
