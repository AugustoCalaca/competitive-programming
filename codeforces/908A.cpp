#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
  string s;
  int c = 0;

  cin >> s;
  for(auto &i : s) {
    if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
      c++;
    if(i > '0' && i <= '9') {
      i = i - '0';
      if(i & 1) c++;
    }
  }

  cout << c << "\n";

  return 0;
}
