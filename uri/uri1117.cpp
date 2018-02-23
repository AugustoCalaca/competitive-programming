#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int count = 1;
	float note, average = 0;

	while(cin >> note && count < 3) {
		if(note < 0 || note > 10)
			cout << "nota invalida\n";
		else {
			average = (float)(average + note) / count;
			count++;
		}
	}

	cout.precision(2);
	cout << fixed;
	cout << "media = " << average << "\n";

	return 0;
}
