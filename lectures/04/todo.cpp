#include <iostream>
using namespace std;
#include <cmath>

void perfect_cube() {
	int to_check;
	int not_found = 1;
	cout << "Enter number to cube check\n";
	cin >> to_check;
	for(int i = 0; i < sqrt(to_check); i++) {
		if(i * i * i == to_check) {
			cout << "Cube of:   " << i << 
				"\n";
			not_found = 0; 
			break;
		}
		else {}
	}
	if(not_found == 1) {
		cout << "No cubes found\n";
	}
}

void sum_odd_cubes() {
	int noof_cubes;
	int cube_count = 1;
	int sum = 0;
	int to_add;
	cout << "Number of odd cubes to add?    ";
	cin >> noof_cubes;
	/* set for loop with argument that allows
	 * it to break whenever iterator i goes over
	 * the value of noof_cubes. i will iterate
	 * in an i+=2 fashion such that it only 
	 * covers odd numbers to cube. This is 
	 * because the cube of an even number will
	 * ALWAYS be even due to 2 being a factor.
	 * The other way round is also true. The 
	 * cube of an odd is ALWAYS odd since 2 can
	 * never be a factor */
	for(int i=1;cube_count <= noof_cubes;i+=2)	{
		to_add = i * i * i;
		sum += to_add;
		cube_count++;
	}
	cout << "The sum of the first " <<
			noof_cubes << " odd cubes is " << 
			sum << "\n";
}

/* This one is in the works. Does not quite work
 * as of yet... */
void fibonacci_term(int n_terms) {
	int preceding1 = 1;
	int preceding2 = 1;
	int fib_total;
	for(size_t i = 2; i < n_terms; i++) {
		fib_total = preceding1 + preceding2;
		preceding1 = preceding2;
		preceding2 = fib_total;
	}

	cout << "The " << n_terms << "th/rd/st/nd term is "
		<< fib_total << "\n";
}

/* TODO: Find the greatest common divisor of an integer n and m */

void greatest_divisor(int n, int m) {
	int candidate1 = n;
	int candidate2 = m;
	int largest_divisor = 1;
	for(size_t i = 2; i <= (candidate1); ++i) {
		if(candidate1 % i == 0 && candidate2 % i == 0) {
			largest_divisor = i;
		} else {}
	}
	cout << "The largest divisor of " << n << " and " 
		<< m << " is " << largest_divisor << endl;
}





int main() {
	/* perfect cube function */
	//perfect_cube();
	//sum_odd_cubes();
	greatest_divisor(9102, 10022);
	fibonacci_term(10);
}


