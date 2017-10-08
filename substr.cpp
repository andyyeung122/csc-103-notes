#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

int substr(const string& s1, const string& s2) {
	/* the purpose of this code is to check whether is a 
	 * string is a subset of another. we can check this 
	 * by nesting for loops. We are considering s2 to be
	 * the candidate for substr */
	size_t length1 = s1.length(); size_t length2 = s2.length();
	bool match;
	if(length2 > length1) {
		cout << "Please exit the code and enter the smaller "
			<< "string first!\n";
		return -1;
	} else {
		size_t limitInd = length1 - length2;
		for(size_t i = 0; i <= limitInd; i++) {
			match = true;
			for(size_t j = i; j < j + (length2 - 1); j++) {
				if(s2[j] != s1[j]) {
					match = false;
					break;
				}
			}
		}
	}

	if(match == true) {
		return 1;
	} else {
		return 0;
	}
}


int main() {
	string first = "naman";
	string second = "ama";
	int x = substr(first, second);
	if(x == 1) {
		cout << second << " IS a substring of " << first;
	} else if(x == 0) {
		cout << second << " IS NOT a substring of " << first;
	} else {}

}

