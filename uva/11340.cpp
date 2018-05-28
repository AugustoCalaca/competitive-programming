#include <iostream>
#include <cstdio>
#include <string>
#include <map>

#define f first
#define s second
using namespace std;

// ac
int main() {
  int t, k, n;
  int prize;
  char ch;


  for(cin >> t; t--; ) {
    map<char, int> m;

    cin >> k;
    while(k--){
      cin >> ch >> prize;
      m[ch] = prize;
    }

    cin >> n;
    cin.ignore();
    double ans = 0;
    while(n--) {
      string str;
      getline(cin, str);
      for(size_t i = 0; i < str.size(); i++){
        auto it = m.find(str[i]);
        if(it != m.end()){
          ans += it->s;
        }
      }
    }

    cout.precision(2);
    cout << fixed;
    cout << ans / 100 << "$\n";
    // printf("%.2lf$\n", ans / 100);
  }

  return 0;
}
