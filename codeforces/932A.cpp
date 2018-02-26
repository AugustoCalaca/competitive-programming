#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
  string s;

  cin >> s;
  cout << s;
  for(int i = s;size() - 1; i >= 0; i++)
    cout << s[i];

  return 0;
}
