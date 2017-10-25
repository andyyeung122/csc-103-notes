#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

/* TODO: make sure you understand the above.  Maybe try to write it
 * over from scratch. */
int substr(string s1, string s2) {
	int length1 = s1.length();
	int length2 = s2.length();
	for(size_t start_point = 0; start_point <= length1 - length2;
			start_point++){
		bool found = true;
		for(size_t s_comp = start_point; s_comp < length2;
				s_comp++){ 
			if(s2[s_comp] != s1[start_point+s_comp]) {
				found = false;
				break;
			} else {}
		}
		if(found) {
			return start_point;
		} else {}
	}
	return -1;
}




/* TODO: make sure you have done all the exercises from lecture 09/ */

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int i = substr(s1, s2);
	if (i >= 0) {
		cout << "match found at " << i << "\n";
	} else {
		cout << "no match found.\n";
	}
	return 0;
}
