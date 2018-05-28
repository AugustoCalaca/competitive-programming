#include <iostream>

using namespace std;
// ac
char place[600][600];

int main() {
  int r, c;

  cin >> r >> c;
  for(int i = 1 ; i <= r; i++) {
    for(int j = 1; j <= c; j++)
      cin >> place[i][j];
  }
  for(int i = 1 ; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      if(place[i][j] == 'S' &&
        ((place[i][j + 1] == 'W' || place[i + 1][j] == 'W') ||
         (place[i - 1][j] == 'W' || place[i][j - 1] == 'W'))) {
        cout << "No\n";
        return 0;
      }
      if(place[i][j] == 'S') {
        if(place[i][j + 1] == '.')
          place[i][j + 1] = 'D';
        if(place[i + 1][j] == '.')
          place[i + 1][j] = 'D';
        if(place[i - 1][j] == '.')
          place[i - 1][j] = 'D';
        if(place[i][j - 1] == '.')
          place[i][j - 1] = 'D';
      }
    }
  }

  cout << "Yes\n";
  for(int i = 1 ; i <= r; i++) {
    for(int j = 1; j <= c; j++)
      cout << place[i][j];
    cout << "\n";
  }

  return 0;
}
