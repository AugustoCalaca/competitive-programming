#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back
using namespace std;

vector<int> sieveSundaram(int n) {
  int nNew = n / 2;
  vector<bool> marked(nNew + 100, false);
  vector<int> result;

  for(int i = 1; i <= (floor(sqrt(n)) / 2); i++)
    for(int j = (i*(i + 1)) << 1; j <= nNew; j = j + 2*i + 1)
      marked[j] = true;

  result.pb(2);

  for(int i = 1; i <= nNew; i++)
    if(marked[i] == false)
      result.pb(2*i + 1);

  return result;
}

int main() {
  int n;

  cin >> n;

  vector<int> result = sieveSundaram(n);
  for(auto& show : result) cout << " " << show;
  cout << endl;

	return 0;
}
