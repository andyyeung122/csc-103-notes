#include <iostream>
using namespace std;
int main() {

	/* TODO: given an integer n, find exponent of the largest power of two that
	 * divides n.  Example: if n = r*8 with r odd, then you should output 3
	 * since 8 = 2^3.  (You are just recovering the exponent of the 2 in the
	 * number's factorization into primes.) */
	/* IDEA: keep on dividing n by two until we can't,
	 * and keep track of how many times it worked. */
	int candidate = 0;
	cout << " Enter number\t";
	cin >> candidate;
	size_t factor_count = 0;
	while(candidate % 2 == 0) {
		candidate /= 2;
		factor_count++;
	}
	cout << " Largest factor of 2 is:\t" << "2^"
		<< factor_count << endl;
	return 0;
}

