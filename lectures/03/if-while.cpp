/* Flow of control:
 * Boolean expressions; if and while statements.
 * */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main()
{
	/* IF STATEMENTS */

	/* IDEA: execute a piece of code 0 or 1 times, conditioned upon a
	 * boolean expression.
	 * */

	/* NOTE: change these 0s to 1s to un-comment until the #endif */
	#if 0
	string s;
	cout << "Feeling overwhelmed by 103? ";
	cin >> s;
	if (s == "yes") {
		cout << "I'm sorry :\\ It will get better!\n";
	} else if (s == "yes" || s == "YES") {
		cout << "T_T\n";
	} else {
		cout << "Excellent...\n";
	}
	#endif

	/* general form:
	 * if (<boolean expression>) {
	 *     statements...
	 * } else if (<boolean expression>) {
	 *     more statements...
	 * } else {
	 *     statements if all other cases failed...
	 * }
	 * NOTE: exactly ONE of the blocks of statements will be excuted: that
	 * of the first "match" (true expression), or the else at the end.
	 * */

	/* NOTE: TWO equals signs (==) are needed to test equality.
	 * Otherwise you'll end up doing assignment. */
	/* TODO: write an example where = is used when == was intended.
	 * Make sure you understand the behavior of the program, and also
	 * take a look at the compiler output -- it should at least give
	 * you a warning. */

	/* Boolean expressions: expressions that can evaluate to either
	 * true or false.  For example, x == 3, or response != "yes".
	 * other (binary) boolean operators:
	 * ==
	 * !=
	 * <
	 * >
	 * <=
	 * >=
	 * The above work on integers, strings, chars, and lots more.
	 * Furthermore, we have the following operators on booleans:
	 * && -- this gives the logical "and"
	 * || -- this gives the logical "or"
	 * !  -- this gives the logical negation
	 * */


	/* LOOPS */

	#if 0
	while (true) {
		cout << "T_T T_T T_T ";
	}
	#endif

	/* another example: print list of squares of first 10 integers. */
	#if 0
	int i = 1;
	while (i < 11) {
		cout << i*i << "\n";
		i = i+1;
	}
	cout << "i == " << i << "\n";
	#endif

	/* general form:
	 * while (<boolean expression>) {
	 *    statements to do while expression is true...
	 * }
	 * */

	/* example: read integers from standard input and print
	 * the *product* of them all. */
	int first;     /* store value from standard input */
	int product=1; /* store the product of all numbers read so far. */
	while (cin >> first) { /* read all the numbers from stdin. */
		/* our meaning for product is wrong right now! */
		product = product * first;
	}
	cout << "product was " << product << "\n";

	/* TODO: read those notes I gave you (l1.pdf was the file name) and
	 * try to do the exercises at the end. */

	/* TODO: given an integer n, find exponent of the largest power of two that
	 * divides n.  Example: if n = r*8 with r odd, then you should output 3
	 * since 8 = 2^3.  (You are just recovering the exponent of the 2 in the
	 * number's factorization into primes.) */
	/* IDEA: keep on dividing n by two until we can't,
	 * and keep track of how many times it worked. */

	return 0;
}

/* TODO: compile this via the makefile instead of typing out the g++
 * commands yourself.  */

// vim:foldlevel=1
