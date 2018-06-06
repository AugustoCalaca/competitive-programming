#include <iostream>

using namespace std;

int main() {
  int ans[5][5];
  for(int i = 1; i < 4; i++)
    for(int j = 1; j < 4; j++)
      ans[i][j] = 1;
      
  int n;
  for(int i = 1; i < 4; i++)
    for(int j = 1; j < 4; j++) {
      cin >> n;
      if(n & 1) {
        ans[i][j] = ans[i][j] ? 0 : 1; 
        ans[i][j + 1] = ans[i][j + 1] ? 0 : 1;
        ans[i + 1][j] = ans[i + 1][j] ? 0 : 1;
        ans[i - 1][j] = ans[i - 1][j] ? 0 : 1;
        ans[i][j - 1] = ans[i][j - 1] ? 0 : 1;
      }
    }
    
  for(int i = 1; i < 4; i++) {
    for(int j = 1; j < 4; j++)
      cout << ans[i][j];
    cout << "\n";
  }
  
  return 0;
}
