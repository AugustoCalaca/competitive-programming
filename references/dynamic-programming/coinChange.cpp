#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coin, int change) {
	int qtCoin = 0;
	int auxCoin;

	sort(coin.begin(), coin.end(), greater<int>());

	for(auto it = coin.begin(); it != coin.end(); it++) {
		auxCoin = change / *it;
		change = change - (*it) * auxCoin;
		qtCoin = qtCoin + auxCoin;
	}

	return qtCoin;
}

int main() {
	vector<int> coin;
	int change, val;

	while(cin >> val) {
		if(val == 0)
			break;
		coin.push_back(val);
	}

	cin >> change;
	cout << "Coin number: " << coinChange(coin, change) << "\n";

	return 0;
}
