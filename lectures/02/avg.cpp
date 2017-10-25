#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "average was " << (a+b+c)/3.0 << "\n";
	/* NOTE the necessity of the ".0" after the "3".  Without it,
	 * we would always get an integer result for the average.
	 * */
	return 0;
}

/* TODO: test this program.  Try typing the input manually, but also
 * try this:
 * $ echo 2 3 5 | ./average */
/* TODO: extend this program to take the average of 5 integers,
 * and do so *ONLY USING TWO VARIABLES TOTAL*. */
