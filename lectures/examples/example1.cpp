#include <iostream>
using namespace std;

int main() {
	/* calculating the gcd of two numbers
	 * using basic c++ logic and intuition 
	 * NOTE: The biggest gcd can be the smallest
	 * of a pair of two numbers. We will attempt 
	 * to make a brute force algorithm at first */
	int a;
	int b;
	/* a <= b, and the smallest gcd is always 1. 
	 * The list of gcd hence starts at 1 and 
	 * ends at a. */
	cout << "a?    "; 
	cin >> a;
	cout << "b?    ";
	cin >> b;

	/* We must make sure that a is always less than
	 * or equal to the value of b. In the case where b
	 * is smaller than a we must do the following: */
	if(b < a) {
		int temp = a;
		a = b; 
		b = temp;
	}
	/* The thing below can also be done using a for loop
	 * but the iterator must go in the reverse direction
	 * at all times. */ 
	int gcd_candidate = a;
	while(gcd_candidate >= 1) {
		if((a % gcd_candidate == 0) && 
				(b % gcd_candidate == 0)) {
			break;
		}
		gcd_candidate = gcd_candidate - 1;
	}
	cout << " THE GCD IS " << gcd_candidate << endl;
	return 0;
}

