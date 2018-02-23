#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
typedef unsigned long long ull;

// accepted
int main() {
	ull t, qtd;
	ull tam[25];
	ull int mat[25][25];
	int k = 4;
	string resp = "";

	cin >> t;
	for(size_t ind = 0; ind < t; ind++, k++) {
		cin >> qtd;
		for(size_t i = 0; i < qtd; i++) {
			for(size_t j = 0; j < qtd; j++) {
				cin >> mat[i][j];
				mat[i][j] = mat[i][j] * mat[i][j];
			}
		}

		fill ( tam, tam + qtd + 1, 0 );
		for ( size_t j = 0; j < qtd; j++ ) {
			for ( size_t i = 0; i < qtd; i++ ) {
				stringstream stri;
				stri << mat[i][j];
				string os = stri.str ();
				if ( os.size () > tam[j] )
					tam[j] = os.size ();
			}
		}

		cout << "Quadrado da matriz #" << k << ":\n";
		size_t i = 0;
		for(; i < qtd; i++) {
			for(size_t j = 0; j < qtd; j++) {
				cout << setw(tam[j]);
				cout << mat[i][j];
				if(j < qtd - 1)
					cout << " ";
			}
			cout << "\n";
		}
		if(ind + 1 < t)
			cout << "\n";
	}

	return 0;
}
