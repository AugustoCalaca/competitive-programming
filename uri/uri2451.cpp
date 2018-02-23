#include <iostream>

using namespace std;

// accepted
char board[110][110];

int main() {
  int n;

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];

  int food = 0, max = 0;
  for(int i = 0; i < n; i++) {
    int j;
    if(i & 1) {
      for(j = n - 1; j >= 0; j--) {
        if(board[i][j] == 'o') food++;
        if(board[i][j] == 'A') {
          if(food > max)
            max = food;
          food = 0;
        }
      }
    }
    else {
      for(j = 0; j < n; j++) {
        if(board[i][j] == 'o') food++;
        if(board[i][j] == 'A') {
          if(food > max)
            max = food;
          food = 0;
        }
      }
    }
  }
  if(food > max)
    max = food;

  cout << max << endl;
  return 0;
}