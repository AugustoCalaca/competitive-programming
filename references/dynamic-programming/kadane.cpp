/*
	implementacao do algoritmo de Kadane
	aproveito para implentar o msm algoritmo com programcao dinamica
	serve para encontrar a maior soma contigua de uma sequencia
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int kadane(vector<int>& vec){
	int maxCorrent = 0, maxTotal = -1;

	for(auto it = vec.begin(); it != vec.end(); it++){
		maxCorrent += *it;

		if(maxCorrent < 0)
			maxCorrent = 0;
		if(maxCorrent > maxTotal)
			maxTotal = maxCorrent;
	}

	return maxCorrent;
}

int progDin(vector<int>& v) {
	int sz = vetor.size();
	vector<int> pd(sz);

	pd[0] = v.front();
	for(int i = 1; i < sz; i++) {
		if(v[i] + pd[i - 1] >= pd[i - 1])
			pd[i] = v[i] + pd[i - 1];
		else if(v[i] + pd[i - 1] < 0)
			pd[i] = 0;
		else
			pd[i] = v[i] + pd[i - 1];
	}

	cout << "Vector: ";
	for(auto it = v.begin(); it != v.end(); it++)
		cout << " " << *it;
	cout << endl;

	cout << "Vector de sums:";
	for(auto it = pd.begin(); it != pd.end(); it++)
		cout << " " << *it;
	cout << endl;

	return *max_element(pd.begin(), pd.end());
}

int main(){
	vector<int> vec;
	int valor;

	while(cin >> valor)
		vec.push_back(valor);

	cout << "Kadane: " << kadane(vec) << "\n";
	cout << "Prog. Dinam: " << progDin(vec) << "\n";

	return 0;
}

