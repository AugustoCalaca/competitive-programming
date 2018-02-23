#include <iostream>

using namespace std;

// accepted
int main() {
	int street, i, ans;

	for(int k = 1; true; k++) {
		cin >> street >> i;

		if(street == 0 && i == 0) break;

		ans = (street - 1) / i;
		cout << "Case " << k << ": ";
		if(ans > 26) cout << "impossible\n";
		else cout << ans << "\n";
	}

	return 0;
}
