#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* aqui eh gambiarra porra!! */
/* objetivo concluido quando nem voce entende seu próprio código */
/* o importante é funcionar */

// accepted
int main(){
	int num, comp, cont;
	string str, result;
	vector<int> vec;

	for(cin >> num; num--;) {
		cin >> comp;
		if(comp == 0)
			cout << "N\n";
		else {
			cin >> str;
			if(count(str.begin(), str.end(), 'D') % 2 == 0)
				cout << "N\n";
			else {
				cont = 0;
				int i = 0;
				for(; i < comp; i++) {
					if(str[i] == 'D'){
						cont++;
						vec.push_back(i + 1);

						if(cont == comp) {
							cout << "Y\n";

							for(auto i = vec.begin(); i != vec.end(); i++) {
								cout << *i;
								if(i + 1 == vec.end()){}
								else cout << " ";
							}
							cout << "\n";
							break;
						}
						str[i] = 'A';
						if(i == 0) {
							if(str[i + 1] == 'D')
								str[i + 1] = 'B';
							else if(str[i + 1] == 'B')
								str[i + 1] = 'D';
						} else {
							if(i + 1 == comp) {
								if(str[i - 1] == 'D')
									str[i - 1] = 'B';
								else if(str[i - 1] == 'B')
									str[i - 1] = 'D';
							} else {
								if(str[i + 1] == 'D')
									str[i + 1] = 'B';
								else if(str[i + 1] == 'B')
									str[i + 1] = 'D';

								if(str[i - 1] == 'D')
									str[i - 1] = 'B';
								else if(str[i - 1] == 'B')
									str[i - 1] = 'D';
							}
							i = i - 2;
						}
					}
					if(i + 1 == comp) {
						cout << "N\n";
						break;
					}
				}

				vec.clear();
			}
		}
	}

	return 0;
}
