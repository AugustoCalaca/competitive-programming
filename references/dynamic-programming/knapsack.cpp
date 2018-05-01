#include <iostream>

using namespace std;

int knapsack(int c, int e, int v[], int p[]){
	int tb[e + 1][c + 1];

	for(int i = 0; i <= e; i++)
		tb[i][0] = 0;
	for(int j = 1; j <= c; j++)
		tb[0][j] = 0;

	for(int i = 1; i <= e; i++){
		for(int j = 1; j <= c; j++){
			if(p[i - 1] <= j){
				if((v[i - 1] + t[i - 1][j - p[i - 1]]) > tb[i - 1][j])
					tb[i][j] = v[i - 1] + tb[i - 1][j - p[i - 1]];
				else
					tb[i][j] = tb[i - 1][j];
			}
			else
				tb[i][j] = tb[i - 1][j];
		}
	}

	return tb[e][c];
}

int main(){
	int c = 20;
	int e = 5;
	int v[] = {3, 5, 8, 4, 10};
	int p[] = {2, 4, 5, 3, 9};

	cout << "Max value: " << knapsack(c, e, v, p) << "\n";

	return 0;
}

