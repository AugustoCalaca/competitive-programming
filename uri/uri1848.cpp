#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string whoop("caw caw");
	string str[1010];
	int sum = 0;
	int j;

	int i = 0;
	for(int cnt = 0; cnt < 3; i++){
		getline(cin, str[i]);
		if(str[i].compare(whoop) == 0)
			cnt++;
	}

	int temp = i;
	for(i = 0; i < temp; i++){
		if(str[i].compare(whoop) == 0){
			cout << sum << "\n";
			sum = 0;
		} else {
			j = 2;
			for(string::iterator it = str[i].begin(); it != str[i].end(); j--, it++) {
				if(*it == '*')
					sum += pow(2, j);
			}
		}
	}

	return 0;
}
