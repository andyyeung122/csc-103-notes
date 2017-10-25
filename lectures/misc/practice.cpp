#include <iostream>
using namespace std;

int main() {
	size_t i;
	int count = 0;
	for(i = 0; i < 100; ++i) {
		cout << i << endl;
		count++;
	}
	cout << "<<<<<<<<<<<<<    " << count << endl;

	count = 0;
	for(i = 0; i < 100; i++) {
		cout << i << endl;
		count++;
	}
	cout << "<<<<<<<<<<<<<    " << count << endl;

	return 0;
}

