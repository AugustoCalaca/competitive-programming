#include <iostream>
#include <list>

using namespace std;

// accepted
int main() {
	int cartas;
	list<int> removidos;
	list<int> lista;

	while(true) {
		cin >> cartas;
		if(!cartas) return 0;

		for(int i = cartas; i; i--)
			lista.push_back(i);

		while(lista.size() > 1) {
			removidos.push_back(lista.back());
			lista.pop_back();
			lista.push_front(lista.back());
			lista.pop_back();
		}

		size_t i = 0;
		cout << "Discarded cards: ";
		for(auto it = removidos.begin(); it != removidos.end(); it++, i++) {
			cout << *it;
			if(i < removidos.size() - 1)
				cout << ", ";
			else
				cout << "\n";
		}
		cout << "Remaining card: " << lista.back() << "\n";
		lista.clear();
		removidos.clear();
	}

	return 0;
}
