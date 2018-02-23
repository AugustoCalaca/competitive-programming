#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void combinations(vector<int> vec, int vis[], int tam, int i = 0) {
	if(i == tam) {
		for(int j = 0; j < tam; j++) {
			if(vis[j] == true)
				cout << " " << vec[j];
		}
		cout << endl;
	}
	else {
		vis[i] = true;
		combinations(vec, vis, tam, i + 1);
		vis[i] = false;
		combinations(vec, vis, tam, i + 1);
	}

}

int main() {
	vector<int> vec = {20, 10, 50, 1};
	int sz = vec.size();
	int vis[sz];

	for(int i = 0; i < sz; i++)
		vis[i] = 0;

	combinations(vec, vis, sz);
	cout << "Comb. number: " << pow(2, sz) << endl; // conta com a solucao vazia

	return 0;
}
