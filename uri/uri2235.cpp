#include <iostream>
#include <vector>

using namespace std;

// accepted
bool verify(vector<int>& v){
	if((v[0] == v[1] || v[0] == v[2]) || v[1] == v[2])
		return true;
	if(v[0] + v[1] == v[2] || v[0] - v[1] == v[2])
		return true;
	if(v[0] + v[2] == v[1] || v[0] - v[2] == v[1])
		return true;
	return false;
}

int main(){
	int val;
	vector<int> v;

	for(int i = 0; i < 3; i++){
		cin >> val;
		v.push_back(val);
	}

	if(verify(v)) cout << "S";
	else cout << "N";
	cout << "\n";

	return 0;
}
