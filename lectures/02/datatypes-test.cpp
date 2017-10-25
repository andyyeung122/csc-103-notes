#include <iostream>
using std::cout;

int main()
{
	/* remember: program will start here. */
	int x; /* make room for an integer and name it x */
	x = 77;
	/* other common (and built-in) datatypes:
	 * int -- for storing integers
	 * char -- single character data, e.g. 'h'
	 * double -- for floating point (an approx. to reals)
	 * */
	char c;
	double d;
	c = 'h';  /* NOTE: single quotes are for single characters. */
	d = 10;

	/* print the sizes of the different types of "boxes" (variables) */
	cout << "size of char:    " << sizeof(char) << "\n";
	cout << "size of int:     " << sizeof(int) << "\n";
	cout << "size of double:  " << sizeof(double) << "\n";

	/* mixing types in arithmetic expressions: */
	cout << x / 10 << "\n"; /* prints 7, as both x and 10 are int's */
	cout << x / 10.0 << "\n"; /* prints 7.7 */

	/* NOTE: some arithmetic identities breakdown for floating point.
	 * Consider the cancellation law: a+y == a+z ==> y == z. */
	double a,y,z;
	a = 100000000000000000000000000000.0;
	y = 0.0;
	z = 0.0000000001;
	cout << a+y << "   " << a+z << "\n";
	if (a+y == a+z) {
		cout << "y == z: " << (y == z) << "\n";
		/* NOTE: I used multiplication during lecture, but realized it
		 * would be easier to make an example with addition.  Note also
		 * that all constants are now of type double.
		 * */
	}
	/* NOTE: a single equals sign (=) does assignment,
	 * not an equality check!  That's what == is for. */

	return 0;
}

/* TODO:
 * 1. again, make sure you can compile this on the command line.
 * 2. experiment with it.  make a change that doesn't compile and
 *    try to make sense out of the resulting error messages.
 * 3  make sure you have streamlined the process of editing,
 *    compiling, and testing your program.
 * 4. play with git.  see the tutorial.  be sure to get
 *    familiar with 'git diff' and 'git log -p'. */
