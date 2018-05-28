#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  string s;
  set<string> st;
  while(cin >> s)
    st.insert(s);

  if(s[s.size() - 1] == '?') {
    cout << "7\n";
    return 0;
  }
  s.pop_back();
  if(s == "Sussu" || st.find("Sussu") != st.end()) cout << "AI SUSSU!\n";
  else cout << "O cara é bom!\n";

  return 0;
}
