#include <iostream>
using std::cout;
using std::cin;

int max(int a, int b, int c) {
	/* designed to find the maximum value 
	 * between a selection of three different
	 * integer values */
	int max;
	max = a;
	if((b > a) && (b > c)) {
		max = b; 
	} else if((c > a) && (c > b)) {
		max = c;
	}
	return max;
}

double ave(double a, double b, double c) {
	/* designed to find the average of three
	 * doubles. NOTE: The datatype double is
	 * essentially the same as float, but with
	 * a much larger memory capacity; it is
	 * 64 bit whereas float is 32 bit. */
	return (a + b + c) / 3; 
}


int main() {
	int m; double s;
	m = max(43,3,23);
	s = ave(101.1, 23.2, 64.5);
	cout << s << "\n";
	cout << m << "\n";
	return 0;
}
