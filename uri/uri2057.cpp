#include <iostream>

using namespace std;

// accepted
int main() {
	int a, b, c, ans;

	cin >> a >> b >> c;

	ans = (a + b + c) % 24;
	if(ans >= 0) cout << ans << endl;
	else cout << 24 + ans << endl;

	return 0;
}
