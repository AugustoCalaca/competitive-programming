#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int s[35];

int main() {
  for(int i = 0; i < 10; i++) cin >> s[i];
  sort(s, s + 10);

  int n, m;
  cin >> n;
  while(n--) {
    int c = 0;
    for(int i = 0; i < 6; i++) {
      cin >> m;
      if(binary_search(s, s + 10, m)) c++;
    }

    if(c >= 3) cout << "Lucky\n";
    else cout << "Unlucky\n";
  }

  return 0;
}
