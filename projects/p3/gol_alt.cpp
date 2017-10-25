/*
 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Game of Life Wikipedia Page, fopen() fwrite() fread() documentation
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 5
 */

#include <iostream>
#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
#include <cstring>
using std::vector;
#include <string>
using std::string;
using std::cout;
using std::cin;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; /* if > 0, fast forward to this generation. */
string wfilename =  "/tmp/gol-world-current"; /* write state here */
FILE* fworld; /* handle to file wfilename. */
string initfilename = "/tmp/gol-world-current"; /* read initial state from here. */

/* Prototypes of function to use */
size_t nCount(size_t i, size_t j, const vector<vector<bool> >& g);
void update(vector<vector<bool> >&  v1, vector<vector<bool> >& v2);
vector<vector<bool> > initiate(const string& fileName);
void mainLoop();
void writeState(FILE* f, vector<vector<bool> > g);
/* Prototypes of debugging functions */
void checkDim(vector<vector<bool> > V);
void printGrid(vector<vector<bool> >& V);
#if 0
// neighbour counter
size_t nbrCount(size_t i, size_t j, const vector<vector<bool> >& g);
void update(); //transfer from old to new state
int initFromFile(const string& fname); // read initial state from file
void mainLoop(); // update state, write state, sleap, repeat ...
void dumpState(FILE* f);
#endif


char text[3] = ".O";

int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"seed",    required_argument, 0, 's'},
		{"world",   required_argument, 0, 'w'},
		{"fast-fw", required_argument, 0, 'f'},
		{"help",    no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case 's':
				initfilename = optarg;
				break;
			case 'w':
				wfilename = optarg;
				break;
			case 'f':
				max_gen = atoi(optarg);
				break;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	mainLoop();
	return 0;
}

void mainLoop() {
	/* update, write, sleep */
	vector<vector<bool> > v1, v2;
	v1 = initiate(initfilename);
	v2 = v1;
	if(max_gen == 0) {
		while(true) {
			fworld = fopen(wfilename.c_str(), "wb");
			writeState(fworld, v2);
			fclose(fworld);	
			update(v1, v2);
			sleep(1);
		}
	} else if(max_gen > 0) {
		for(unsigned int i = 0; i < max_gen; i++) {
			update(v1, v2);
		}
		fworld = fopen(wfilename.c_str(), "wb");
		writeState(fworld, v2);
		fclose(fworld);
	} else {}
}


void update(vector<vector<bool> >& v1, vector<vector<bool> >& v2) {
	size_t neighbours;
	size_t row, col; 
	size_t rows = v1.size(); size_t cols = v1.back().size();
	if(v1.size() != v2.size() || v2.back().size() != v2.back().size()) {
		cout << " v1 and v2 must agree in dimensions!\n";
		exit(1);
	}

 	for(row = 0; row < rows; row++) {
		for(col = 0; col < cols; col++) {
			neighbours = nCount(row, col, v1);
			if(v1[row][col] && neighbours < 2) {
				v2[row][col] = false;
			} else if((v1[row][col]) && (neighbours == 2 ||
					neighbours == 3)) {
				v2[row][col] = true;
			} else if(v1[row][col] && neighbours > 3) {
				v2[row][col] = false;
			} else if(!v1[row][col] && neighbours == 3) {
				v2[row][col] = true;
			} else {} 
		}
	}
	v1 = v2;
}

size_t nCount(size_t i, size_t j, const vector<vector<bool> >& g) {
	size_t count = 0;
	size_t row = i; size_t col = j;
	size_t rows = g.size(); size_t cols = g.back().size();
	bool present_right, present_left, present_up, present_down;
	present_right = g[row][((col+1)%cols)];
	present_left = g[row][(((col+cols)-1)%cols)];
	present_down = g[((row+1)%rows)][col];
	present_up = g[(((row+rows)-1)%rows)][col];

	bool present_rd, present_ru, present_ld, present_lu;
	present_rd = g[((row+1)%rows)][((col+1)%cols)];
	present_ru = g[(((row+rows)-1)%rows)][((col+1)%cols)];
	present_ld = g[((row+1)%rows)][(((col+cols)-1)%cols)];
	present_lu = g[(((row+rows)-1)%rows)][(((col+cols)-1)%cols)];

	count = count + (size_t)present_right + (size_t)present_left +
		(size_t)present_down + (size_t)present_up +
		(size_t)present_rd + (size_t)present_ru + 
		(size_t)present_ld + (size_t)present_lu;

	return count;
}


vector<vector<bool> > initiate(const string& fname) {
	FILE* f = fopen(initfilename.c_str(), "rb");
	vector<vector<bool> > V;
	V.push_back(vector<bool>());
	size_t current_row = 0;
	char c;

	while(fread(&c, 1, 1, f) != 0) {	
		if(c == '\n') {
			V.push_back(vector<bool>());
			current_row++;
		} else if(c == '.') {
			V[current_row].push_back(false);
		} else if(c == 'O') {
			V[current_row].push_back(true);
		}
	}
	V.pop_back();
	fclose(f);
	return V;
}

void writeState(FILE* f, vector<vector<bool> > V) {
	size_t row, col, rows, cols = 0;
	rows = V.size(); cols = V.back().size();
	for(row = 0; row < rows; row++) {
		for(col = 0; col < cols; col++) {
			char toWrite = text[V[row][col]];
			fwrite(&toWrite, 1, 1, f);
		}
		fwrite("\n", 1, 1, f);
	}	
}


//debugging functions
void checkDim(vector<vector<bool> > V) {	
	cout << "dimensions of matrix is " <<
		V.size() << " " << V.back().size();
}

void printGrid(vector<vector<bool> >& V) {
	size_t rows, columns;
	rows = V.size(); columns = V.back().size();
	cout << " rows = " << rows << "\n";
	cout << " columns = " << columns << "\n";
	for(size_t row = 0; row < rows; row++) {
		for(size_t col = 0; col < columns; col++) {
			cout << text[V[row][col]];
		}
		cout << "\n";
	}
}



	


