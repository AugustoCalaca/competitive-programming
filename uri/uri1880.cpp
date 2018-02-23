#include <iostream>
#include <vector>

using namespace std;

// accepted
int main(){
	int c, num, numAux, b;
	vector<int> v, an;

	for(cin >> c; c--;){
		cin >> num;

		for(b = 2; b < 17; b++){
			for(numAux = num; numAux > 0 ;){
				v.push_back(numAux % b);
				numAux = numAux / b;
			}

			int sz = v.size();
			int m = sz / 2;
			int i = 0;
			sz -= 1;
			for(; i < m && (v[i] == v[sz - i]); i++){}

			if(i >= m)
				ans.push_back(b);

			v.clear();
		}
		if(ans.empty())
			cout << "-1";
		else{
			for(auto a = ans.begin(); a != ans.end(); a++){
				cout << *a;
				if(a + 1 == ans.end()){}
				else
					cout << " ";
			}
		}
		ans.clear();
		cout << "\n";
	}

	return 0;
}
