#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = ((s[s.size() - 1] - '0') + (s[s.size() - 2] - '0') * 10);
  cout << (n % 4 ? 0 : 4) << "\n";
    
  return 0;
}

