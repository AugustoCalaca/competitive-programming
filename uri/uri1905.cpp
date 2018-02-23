#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// accepted
bool dfs(vector<vector<int> >& mtr, vector<vector<bool> >& v) {
	stack<pair<int, int> > sta;

	for(int i = 1, j = 1; true; ) {
		if(!v[i][j] && mtr[i][j] == 0) {
			v[i][j] = true;
			sta.push(make_pair(i, j));

			i = sta.top().first;
			j = sta.top().second;

			// chegou ao final e capturou os ladroes
			if(i == 5 && j == 5)
				return true;
		}

		// busca por elemento nao visitado e que faz parte do caminho
		bool ok = false;
		if((j + 1 < 6) && (mtr[i][j + 1] == 0 && !v[i][j + 1])) {
			j += 1;
			ok = true;
		}
		else {
			if((i + 1 < 6) && (mtr[i + 1][j] == 0 && !v[i + 1][j])) {
				i += 1;
				ok = true;
			}
			else {
				if((j - 1 >= 1) && (mtr[i][j - 1] == 0 && !v[i][j - 1])) {
					j -= 1;
					ok = true;
				}
				else
					if((i - 1 >= 1) && (mtr[i - 1][j] == 0 && !v[i - 1][j])) {
						i -= 1;
						ok = true;
					}
			}
		}
		if(!ok) {
			if((i == 1 && j == 1))
				return false;

			sta.pop();
			i = sta.top().first;
			j = sta.top().second;
		}
	}
}

int main() {
	int t;
	int v;

	for(cin >> t; t--;) {
		vector<vector<int> > matriz(7);
		vector<vector<bool> > vis(7);

		for(int i = 0; i < 7; i++) {
			matriz[i].resize(7);
			visitado[i].resize(7);
		}

		for(int i = 0; i < 7; i++) {
			for(int j = 0; j < 7; j++) {
				if(i == 0 || i + 1 == 7 || j == 0 || j + 1 == 7)
					matriz[i][j] = 1;
				else {
					cin >> v;
					matriz[i][j] = v;
					vis[i][j] = false;
				}
			}
		}

		if(dfs(matriz, vis))
			cout << "COPS" << endl;
		else
			cout << "ROBBERS" << endl;
	}

	return 0;
}
