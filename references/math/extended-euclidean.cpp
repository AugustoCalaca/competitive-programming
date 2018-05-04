#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

vector<int> extEucli(int a, int b) {
	int q, r, b0 = b;
	vector<int> m = {1, 0};
	vector<int> n = {0, 1};
	vector<int> ans;

	int i = 0;
	for(; b > 0; i++) {
		q = a / b;
		r = a % b;
		a = b;
		b = r;

		m.pb(m[i] - (m[i + 1] * q));
		n.pb(n[i] - (n[i + 1] * q));
	}

	if(m[i] < 0) m[i] += b0;

	resp.pb(m[i]);
	resp.pb(n[i]);

	return resp;
}

int extendEuclides(int a, int b) {
  int quoc, b0 = b;
  int x = 1, y = 0;

  while(b > 0) {
    quoc =  a / b;
    x = x - (y * quoc);
    // y tem q receber o valor antigo de x
    x ^= y;
    y ^= x;
    x ^= y;

    a %= b;
    a ^= b;
    b ^= a;
    a ^= b;
  }

  if(x < 0) x += b0;

  return x;
}

int main() {

	int a, b;
	vector<int> resp;

	cin >> a >> b;
	resp = extEucli(a, b);
	for(auto it = resp.begin(); it != resp.end(); it++)
		cout << " " << *it;
	cout << endl;

	return 0;
}
