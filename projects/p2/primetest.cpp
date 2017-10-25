/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: None
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath> /* This will be used to access the sqrt function
					explanation is provided later in the code */

int main()
{
	/* We will use the while loop so that users can 
	 * continually enter positive integers for primetest.
	 * while(cin >> user_input) is a useful technique 
	 * (disregarding the fact that it cannot be stopped 
	 * without the user actively doing so) because it can
	 * check whether a given input is actually a positive 
	 * integer. If not, then the coindition is false and 
	 * the loop will break. */
	unsigned long user_input; /* unsigned forces the input to
								 be a positive integer, while
								 long can allow for larger memory
								 allocation, hence larger number */
	while(cin >> user_input) {
		int is_prime = 1;
		for(int i = 1;i <= sqrt(user_input); i++) { 
			/* sqrt(user_input) is used because of a very 
			 * good reason. Imagine all the factors of a number
			 * such as 16. We have (other than 1 and 30),
			 * 2, 3, 5, 6, 10, 15. Notice how before the 
			 * integer value of sqrt(30), which is 5 (int() 
			 * rounds down like floor) we have numbers 2, 3, 5. 
			 * If any number from this set n, such that 30 % n 
			 * == 0, we have that it is not prime. We do not 
			 * have to check for the other factors since the first
			 * 3 numbers are their pairs. Hence if 30 % 2 == 0
			 * then 30 % 15 == 0 MUST be true. */
			if(user_input % i == 0 && (i != 1)) {
				is_prime = 0;
				break;
			}	
		} 
		cout << is_prime << "\n";
	}
	return 0;
}
