#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();
  int k, n, v;
  map<int, int> m;
  cin >> k >> n;
  while(n--) {
    cin >> v;
    m[v]++;
  }

  if(m.size() < k) {
    for(int i = 1; i <= k; i++) {
      if(m.find(i) == m.end()) m.insert({ i, 0 });
    }
  }

  map<int, int> m2;
  multimap<int, int> m3;
  for(auto i = m.begin(); i != m.end(); i++) {
    m2[i->s]++;
    m3.insert({ i->s, i->f });
  }

  if(m2.size() == 2) {
    if((m2.begin()->f < m2.rbegin()->f) && (m2.begin()->f + 1 == m2.rbegin()->f && (m2.begin()->s == 1 || m2.rbegin()->s == 1))) {
      if(m2.begin()->s <= m2.rbegin()->s) {
        auto it = m3.find(m2.begin()->f);
        cout << "+" << it->s;
      }
      else if(m2.begin()->s > m2.rbegin()->s) {
        auto it = m3.find(m2.rbegin()->f);
        cout << "-" << it->s;
      }
      else cout << "*";
    }
    else cout << "*";
  }
  else if(m2.size() == 3) {
    auto ite = m2.begin();
    ite++;
    if((ite->f - 1 == m2.begin()->f) && (ite->f + 1 == m2.rbegin()->f)) {
      auto it = m3.find(m2.rbegin()->f);
      cout << "-" << it->s;
      auto it2 = m3.find(m2.begin()->f);
      cout << " +" << it2->s;
    } else cout << "*";
  } else cout << "*";

  cout << "\n";
  return 0;
}
