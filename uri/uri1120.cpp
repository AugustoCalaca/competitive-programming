#include <iostream>
#include <algorithm>
#include <string>

// maratona de 2010 //
// contratos        //
using namespace std;

int main() {
	char numBugado;
	string contrato;

	while(true) {
		cin >> numBugado;
		cin >> contrato;

		if(numBugado == '0' || contrato[0] == '0')
			break;
		else {
			auto fim = remove(contrato.begin(), contrato.end(), numBugado);
			if(contrato.begin() == fim)
				cout << 0;
			else{
				if(contrato[0] == '0'){
					bool achou = false;
					for(auto i = contrato.begin(); i != fim ; i++) {
						if(*i != '0' && !achou) {
							cout << *i;
							achou = true;
						} else { if(achou)
								cout << *i;
								else if(i == fim - 1 && !achou)
									cout << 0;
						}
					}
				}
				else
					for(auto it = contrato.begin(); it != fim; it++)
						cout << *it - '0';
			}

			cout << endl;
		}
	}

	return 0;
}
