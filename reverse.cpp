#include <iostream>
using namespace std;
#include <set>
using std::set;
#include <vector>
using std::vector;

void reverse(string& s);
set<int> intersection(set<int>& A, set<int>& B);
bool insert_to_vector(vector<int>& A, int x);
void merge(const vector<int>& V1, const vector<int>& V2, vector<int>& result);
void circularShift(string& s, size_t n);


void reverse(string& s) {
	char temp;
	size_t length = s.length();
	for(size_t i = 0; i < length/2; i++) {
		temp = s[i];
		s[i] = s[length - (i + 1)];
		s[length - (i + 1)] = temp;
	}
}

set<int> intersection(set<int>& A, set<int>& B) {
	set<int> intersection;
	set<int> smaller_set;
	set<int> bigger_set;
	if(A.size() >= B.size()) {
		smaller_set = B;
		bigger_set = A;
	} else {
		smaller_set = A;
		bigger_set = B;
	}
	for(set<int>::iterator i = smaller_set.begin(); 
			i != smaller_set.end();	i++) {
		int candidate = *i;
		for(set<int>::iterator j = bigger_set.begin();
				j != bigger_set.end(); j++) {
			if(candidate == *j) {
				intersection.insert(candidate);
			} else {}
		}
	}
	return intersection;
}

bool insert_to_vector(vector<int>& A, int x) {
	bool can_add = true;
	for(size_t i = 0; i < A.size(); i++) {
		if(x == A[i]) {
			can_add = false;
		} else {}
	}
	return can_add;
}

void merge(vector<int>& V1, vector<int>& V2, vector<int>& result) {
	size_t len2 = V2.size();
	for(size_t i = 0; i < len2; i++) {
		V1.push_back(V2[i]);
	} // we now have a merged, unsorted vector
	// now to sort!
	size_t len1 = V1.size();
	int min;
	size_t i_s;
	for(size_t j = 0; j < len1 - 1; j++) {
		min = V1[j];
		for(size_t k = j; k < len1; k++) {
			if(V1[k] < min) {
				min = V1[k];
				i_s = k;
			} else {}
		}
		int temp = V1[j];
		V1[j] = min;
		V1[i_s] = temp;
	}
	result = V1;
}

void circularShift(string& s, size_t n) {
	/* Wrap around the ends of the string using
	 * modular method */
	size_t len = s.length();
	for(size_t i = 0; i < len - n; i++) {
		std::swap(s[i+n], s[i]);	
	}
}


int main() {
	string S;
	cin >> S;
	cout << S << " before reverse." << endl;
	reverse(S);
	cout << S << " after reverse." << endl;

	set<int> a = {1, 5, 0, 1, -1, 100, 101};
	set<int> b = {0, 5, 1, 101, 102};
	set<int> inter = intersection(a, b);
	for(set<int>::iterator i = inter.begin(); 
			i != inter.end(); i++) {
		cout << " " << *i;
	}
	cout << endl;

	vector<int> V = {1,2,3,4,5,6,7,8,9,10};
	int to_add = -1;
	bool can_add = insert_to_vector(V, to_add);
	cout << can_add << endl;

	vector<int> a1 = {0, 99, -1, 3, 4};
	vector<int> a2 = {-1, 100, 101, -34};
	vector<int> r = {0};
	merge(a1, a2, r);
	for(size_t j = 0; j < r.size(); j++) {
		cout << " " << r[j];
	}
	cout << endl;

	string to_circulate;
	cin >> to_circulate;
	cout << " Before circulating:\t" << to_circulate << endl;
	circularShift(to_circulate, 4);
	cout << " After circulating:\t" << to_circulate << endl;

	return 0;
}
