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

	return *max_element(pd.begin(), pd.end());
}

