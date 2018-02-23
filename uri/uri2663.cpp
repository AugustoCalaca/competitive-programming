#include <iostream>
#include <algorithm>

using namespace std;


int main(){

	int n, minComp, minCompCopy, last, pnt, count = 0;
	vector<int> vpnt;		cin >> pnt;
		vpnt.push_back(pnt);


	cin >> n >> minComp;

	for(; n; n--){
		cin >> pnt;
		vpnt.push_back(pnt);
	}

	minCompCopy = minComp;
	for(vector<int>::iterator it; minComp; minComp--){
		it = max_element(vpnt.begin(), vpnt.end());
		last = *it;
		it = vpnt.erase(it);
		count++;
		if(count == minCompCopy){
			while(!vpnt.empty() && last == *max_element(vpnt.begin(), vpnt.end())){
				it = vpnt.erase(max_element(vpnt.begin(), vpnt.end()));
				count++;
			}
		}
	}

	cout << count << endl;
	return 0;
}
