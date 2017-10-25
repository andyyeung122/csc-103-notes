/* Introducing vectors; more on functions. */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector> /* <--- new stuff */
using std::vector;
#include <cstdio>
#include <math.h>
/* TODO: write a function that takes a vector and searches
 * for a particular value x, returning true <==> x is found. */

vector<int> make_vector() {
	vector<int> v;
	for(int i = 1; i <= 100; i++) {
		if(i % 3 == 0) {
			v.push_back(i);
		} else {}
	} return v;
}		

bool is_present(int x, vector<int> v) {
	int val_to_check = x;
	vector<int> vector_to_check = v;
	for(size_t i; i < vector_to_check.size(); i++) {
		if(vector_to_check[i] == val_to_check) {
			return true;
		} else {}
	}
	return false;
}

# if 0
void binary_search(int x, vector<int> v) {
	/* performs binary search on a given vector. 
	 * The user specifies with integer is to be 
	 * searched. Does not return anything,
	 * instead prints out whether it is there 
	 * (and its index if it is), or if it not */
	
	/* the first attempt at finding will be 
	 * in the form of targeting the middle
	 * of the vector */

	/* but first let's instantiate some variables
	 * that will be used throughout the function */

	vector<int> original_vector = v;
	size_t search_vec_size = original_vector.size();
	int search_query = x;
	unsigned int guess; /* indices are always >0 */
	guess = (search_vec_size / 2) ;
	bool not_found = true;
	while(guess != 0 && guess != original_vector.size() - 1) {
		/* random guess in the middle of the 
		 * vector */ 
		if(original_vector[guess] > search_query) {
			cout << " i am at " << original_vector[guess] 
				<< " and this is more than " << search_query; 
			search_vec_size = guess + 1;
			guess = (search_vec_size / 2) ;
		} else if(original_vector[guess] < search_query) {
			cout << " i am at " << original_vector[guess] 
				<< " and this is less than " << search_query; 
			search_vec_size = (search_vec_size + guess) + 1;
			guess = (search_vec_size / 2);
		} else if(original_vector[guess] == search_query) {
			cout << "\n" << search_query << " found at index " 
				<< guess << "\n";
			not_found = false;
			break;
		} else {}
	}
	if(not_found) {
		cout << "\n" << search_query << " not found\n";
	} else {}
}
# endif

void binary_search_2(int x, vector<int> v) {
	vector<int> original_vector = v;
	int search_query = x;
	/* The aim of this approach is simply to store starting
	 * and ending points of smaller vectors (after each 
	 * iteration of the binary search) so that calculation
	 * involving their midpoints can be done easily. */
	vector<unsigned int> start_point;
	vector<unsigned int> end_point;
	float guess;
	bool not_found = true;

	start_point.push_back(0);
	end_point.push_back(original_vector.size() - 1);
	guess = (start_point.back() + end_point.back()) / 2;
	/* cout << guess */;
	# if 1 
	while((end_point.back() - start_point.back()) >= 1) {
		/* The guess will be taken every instance of the while
		 * loop starting from the middle of the original vector
		 * and will change in value depending on the latest
		 * values of end_point and start_point */
		//guess = (start_point.back() + end_point.back()) / 2;
		/* cout << start_point.back() << " " << end_point.back() 
			<< " " << guess << "\n"; */
		if(search_query < original_vector[guess]) {
			end_point.push_back(guess);
			cout << " \nat index " << guess << " and number " 
				<< original_vector[guess] << " and this is greater than " << search_query;
			cout << "\n" << start_point.back() 
				<< " " << end_point.back();
			guess = (start_point.back() + end_point.back()) / 2;
			cout << " \nnext index is " << guess;
		} else if(search_query > original_vector[guess]) {
			start_point.push_back(guess);
			/* guess = (start_point.back() + end_point.back()) / 2.0;
			cout << " ceil of " << guess; */
			guess = ceil((start_point.back() + end_point.back()) / 2.0);
			/* cout << " is " << guess << "\n"; */
			/* cout << " \nat index " << guess << " and number " 
				<< original_vector[guess] << " and this is less than " << search_query; */
		} else if(search_query == original_vector[guess]) {
			not_found = false;
			cout << "\n Found " << search_query << " at index "
				<< guess;
			break;	
		}
	}
	if(not_found) {
		cout << "\n" << search_query << " not found in vector";
	} else {}
	# endif
}



int main() {
	vector<int> vec = make_vector();
	for(size_t i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
	for(int i = -20; i <= 120; i++) {
		if(i == 4) {

		binary_search_2(i, vec);
		}

	}

	/*bool flag = is_present(3, vec);
	cout << "\n" << flag; */
	return 0;
}




#if 0 
 * NOTE: you should think carefully about how to pass the parameters,
 * especially for the vector.  (By value, reference, const reference?) */

int main()
{
	/* exercise: read list of integers and print in reverse order. */
	/* NOTE: vector itself isn't a datatype.  It is like a
	 * machine that creates datatypes: */
	// vector v; /* won't compile -- vector isn't a type */
	/* you have to say you want a vector of SOMETHING, like
	 * integers: */
	vector<int> v; /* each element of the vector will be an int. */
	int n;
	while (cin >> n) {
		/* here's how to add something to a vector: */
		v.push_back(n);
		/* there's also a pop_back() that removes the
		 * last element as well. */
	}
	/* now we just need to print everything out.  Would be nice
	 * to know the names of the elements!  They are v[0],v[1],...
	 * just like an array.  NOTE: you can get the total number
	 * of elements using v.size(), so the name of the very last
	 * one is always v[v.size()-1] */
	for (size_t i = 1; i <= v.size(); i++) {
		cout << v[v.size() - i] << " ";
	}
	cout << "\n";
	/* NOTE: size_t is an unsigned integer that is as large
	 * as a register.  (If you use int instead, you will get
	 * a compiler warning about comparing types with different
	 * signs...). */
	/* TODO: use a for loop with i-- instead to do
	 * the same thing. */

	#if 0
	/* TODO: figure out what is wrong with this version.  Note that we
	 * never use push back, but access elements directly. */
	int count = 0;
	while(cin >> s) {
		v[count] = s;
		count++;
	}
	/* NOTE: the above will compile, but it will break at *runtime* even
	 * on relatively small inputs.  For a hint, see capacity-test.cpp.  */
	#endif
	return 0;
}

/* TODO: write a *binary search* on a sorted vector.  The idea is to
 * kind of emulate the process you use to find a particular page in a book:
 * 1. open the book to some page in the middle.
 * 2. if the page number was too high, open to the middle of the pages to the
 *    left; if it was too low, open to the middle of the pages to the right
 * 3. continue as above until you found the right page.
 *
 * This might be a little challenging.  Ask questions if you get stuck.
 * */

/* TODO: write a function that takes a vector and places the elements
 * in sorted order.  Warning: this could be kind of challenging. */
#endif

