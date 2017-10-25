#include <iostream>
using std::cout;
using std::cin;

int main(void)
{
	int x = 23;
	int y = 99;
	int* p = &x;
	int* q = &y;
	cout << "p == " << p << "\n&x == " << &x << "\n";
	cout << "q == " << q << "\n&y == " << &y << "\n";
	cout << "x == " << x << "\n*p == " << *p << "\n";
	cout << "y == " << y << "\n*q == " << *q << "\n";
	p = q;
	/* TODO: think carefully and predict the output of the following: */
	cout << "p == " << p << "\n&x == " << &x << "\n";
	cout << "q == " << q << "\n&y == " << &y << "\n";
	cout << "x == " << x << "\n*p == " << *p << "\n";
	cout << "y == " << y << "\n*q == " << *q << "\n";
	return 0;
}
