#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// accepted
int main() {
  char ch;
  string str;
  int exist, words;

  exist = words = 0;

  cin >> ch;
  while(cin >> str) {
    if(str.find(ch) != string::npos)
      exist++;
    words++;
  }

  cout.precision(1);
  cout << fixed << exist * 100.0 / words << endl;

  return 0;
}