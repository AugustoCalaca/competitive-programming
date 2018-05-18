#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  
  cin >> n >> s;
  
  int c = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'x') 
      c++; 
    else c = 0;
    if(c == 3) break; 
  }  
  
  if(c != 3) { 
    cout << "0\n";
    return 0;
  }  
  
  int ans = 0;
  c = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'x') {
      c++; 
      if(c >= 3) ans++;
    }
    else c = 0;
  }
  
  cout << ans << "\n";

  return 0;
}
