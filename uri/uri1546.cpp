#include <iostream>
#include <map>

using namespace std;

// accepted
int main() {
	int t, dias, membro;
	map<int, string> feedback;
	feedback[1] = "Rolien";
	feedback[2] = "Naej";
	feedback[3] = "Elehcim";
	feedback[4] = "Odranoel";

	for(cin >> t; t--;) {
		for(cin >> dias; dias--;) {
			cin >> membro;
			cout << feedback.find(membro)->second << endl;
		}
	}

	return 0;
}
