#include <iostream>
using namespace std;
#include <vector>
using std::swap;

int main() {
	/* get the second largest number in a series
	 * of stdin-provided integers */
	int s_l, l, n;
	cin >> l;
	int check = 0;
	while(cin >> n) {		
		if(n > l) {
			int temp = l;
			l = n;
			s_l = temp;
		} else if(check == 0 && n < l) {
			s_l = n;
		} else if(check != 0 && n > s_l && n < l) {
			s_l = n;
		}
		
	}
	cout << "\nLargest is " << l << endl;
	cout << "Second largest is " << s_l << endl;
	return 0;
}


