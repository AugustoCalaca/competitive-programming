#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int main() {
	int j, r, jr, pnt, v;

	cin >> j >> r;

	jr = j * r;
	int tb[j + 1];

	for(int i = 0; i <= j; i++)
		tb[i] = 0;

	for(int i = 0; i < jr; i++) {
		cin >> pnt;
		int id = i % j;
		tb[id] = tb[id] + pnt;
	}

	v = 0;
	for(int id = 1; id < j; id++)
		if(tb[id] >= tb[v])
			v = id;

	cout << v + 1 << endl;

	return 0;
}
