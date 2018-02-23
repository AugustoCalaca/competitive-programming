#include <iostream>

using namespace std;

// accepted
int main(){

	int num, ric, vic, aux;

	cin >> num;

	for(; num; num--){
		cin >> ric >> vic;
		while(true){
			if(ric > vic)
				ric -= vic;
			else if(ric < vic){
				aux = vic;
				vic = ric;
				ric = aux;
			}
			if(ric == vic){
				cout << ric << "\n";
				break;
			}
		}
	}

	return 0;
}
