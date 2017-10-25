#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int user_input;
	int pot_to_average = 0;
	for(int i = 0; i < 5; i++) {
		cout << "PLEASE ENTER A VALUE TO AVERAGE\n"; 
		cin >> user_input;
		pot_to_average += user_input;
	}

	cout << "THE AVERAGE OF THE FIVE NUMBERS IS " 
			<< pot_to_average/5.0 << "\n";
	return 0;
}

/* TODO: test this program.  Try typing the input manually, but also
 * try this:
 * $ echo 2 3 5 | ./average */
/* TODO: extend this program to take the average of 5 integers,
 * and do so *ONLY USING TWO VARIABLES TOTAL*. */
