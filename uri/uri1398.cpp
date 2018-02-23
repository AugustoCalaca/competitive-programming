#include <iostream>
#include <vector>
#include <string>

#define N 131071
#define pb push_back
using namespace std;

// accepted
vector<int> v;

int mypow(int n) {
  int sz = v.size();
  if(n < sz) return v[n];

  for(int i = sz - 1; i < n; i++)
    v.pb((v[i] * 2) % N);

  return v[n];
}

int main() {
  char ch;
  v.pb(1);

  while(cin >> ch) {
    string bin;
    bin.pb(ch);

    while(true) {
      cin >> ch;
      if(ch == '#') break;
      bin.pb(ch);
    }

    int num = 0;
    int i = 0;
    for(auto it = bin.rbegin(); it != bin.rend(); it++, i++)
      if(*it == '1') num = (num + mypow(i)) % N;

    if(num % N) cout << "NO\n";
    else cout << "YES\n";
  }

  return 0;
}