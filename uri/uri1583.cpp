#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// accepted
void dfs(char mp[][55], bool visit[][55], int n, int m, int i, int j) {
	stack<pair<int, int> > sta;

	while(true) {
		if(!visit[i][j] && mp[i][j] == 'T') {
			visit[i][j] = true;
			sta.push(make_pair(i, j));

			i = sta.top().first;
			j = sta.top().second;
		}

		bool ok = false;
		if(!visit[i][j + 1] && mp[i][j + 1] == 'A') {
			j += 1;
			mp[i][j] = 'T';
			pk = true;
		} else {
			if(!visit[i + 1][j] && mp[i + 1][j] == 'A') {
				i += 1;
				mp[i][j] = 'T';
				ok = true;
			}
			else {
				if(!visit[i][j - 1] && mp[i][j - 1] == 'A') {
					j -= 1;
					mp[i][j] = 'T';
					ok = true;
				}
				else if(!visit[i - 1][j] && mp[i - 1][j] == 'A') {
						i -= 1;
						mp[i][j] = 'T';
						ok = true;
				}
			}
		}

		if(!ok) {
			sta.pop();

			if(sta.empty())
				return ;

			i = sta.top().first;
			j = sta.top().second;
		}
	}
}

void show(char mp[][55], int n, int m) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m ; j++) {
			cout << mp[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n, m;
	char ch;
	char mp[55][55];
	bool visit[55][55];

	while(true) {
		cin >> n >> m;
		if(!n && !m)
			break;


		for(int i = 0; i < n + 2; i++) {
			for(int j = 0; j < m + 2; j++) {
				if(i == 0 || j == 0 || i + 1 == n + 2|| j + 1 == m + 2)
					mp[i][j] = '*';
				else {
					cin >> ch;
					mp[i][j] = ch;
				}
				visit[i][j] = false;
			}
		}

		// a busca so pode começar quando encontra o 'T'
		// e se ele ainda nao foi visitado
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(!visit[i][j] && mapa[i][j] ==  'T')
					dfs(mp, visit, n, m, i, j);
			}
		}

		show(mp, n, m);
	}

	return 0;
}
