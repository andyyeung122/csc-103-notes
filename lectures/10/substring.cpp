#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

int substr(const string& s1, const string& s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	/* go through all possible starting points and check
	 * for a match at each one: */
	for (int i = 0; i <= l2 - l1; i++) {
		/* check for match starting at i: */
		bool match = true;
		for (int j = 0; j < l1; j++) {
			if (s1[j] != s2[i+j]) {
				match = false;
				break;
			}
		}
		/* if (j == l1) return i; */
		if (match) return i;
	}
	return -1;
}

/* TODO: make sure you understand the above.  Maybe try to write it
 * over from scratch. */

/* TODO: make sure you have done all the exercises from lecture 09/ */

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int i = substr(s1,s2);
	if (i >= 0) {
		cout << "match found at " << i << "\n";
	} else {
		cout << "no match found.\n";
	}
	return 0;
}
