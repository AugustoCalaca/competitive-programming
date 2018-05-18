#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

int main() {
  int n, k;
  vector<int> v;  
	
	for(cin >> n; n--; ) {
	  cin >> k;
	  v.pb(k);
	}
	
  auto i = v.begin();
	while(true) {   
    if(i + 1 == v.end()) break;
	  auto it = i + 1;
	  bool f = true;
	  for(; it != v.end(); it++) {
	    if(*i == *it) {
	      v.erase(i);
	      f = false;
	      break;
	    }
	  }
	  
	  if(f) i++;
	  else  i = v.begin();
	}
	
	cout << v.size() <<"\n";
	for(auto i : v) cout << i << " ";
	cout << "\n";

	return 0;
}
