#include <iostream>
using namespace std;

int main() {
	int a = 1;
	int* b = &a;
	cout << *b;
	cout << "before increment by pointer \n" << a;
	a = (*b)++;
	
	cout << "after increment by pointer \n" << a;
	return 0;

}


