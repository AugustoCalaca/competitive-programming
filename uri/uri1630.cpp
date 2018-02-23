#include <iostream>

using namespace std;

// accepted
void show(int *stake){
	cout << *stake << "\n";
}

int main(){

	int x, y, per, stake;

	while(cin >> x >> y){
		per = x + x + y + y;

		while(x != y){
			if(x > y)
				x -= y;
			else{
				if(x < y){
					int aux = x;
					x = y;
					y = aux;
				}
			}
		}

		stake = per / x;
		show(&stake0);
	}

	return 0;
}
