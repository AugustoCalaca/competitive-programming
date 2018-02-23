#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// accepted
int main(){
	int n, year, arrived;
	string str;
	map<string, int> msg;
	vector<pair<int, string> > vec;

	while(cin >> n && n != 0){
		while(n--){
			cin >> str >> year >> arrived;
			msg[str] = year - arrived;
		}

		for(map<string, int>::iterator it = msg.begin(); it != msg.end(); it++)
			vec.push_back(make_pair(it->second, it->first));

		cout << min_element(vec.begin(), vec.end())->second << "\n";

		msg.clear();
		vec.clear();
	}

	return 0;
}
