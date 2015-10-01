#include <iostream>
#include <fstream> // voor file I/O
#include <cassert> // voor assertion checking
#include <string>

using namespace std;

enum Action {Encrypt, Decrypt};

int seed = 0;

void initialise_pseudo_random(int r) {
	//  pre-condition:
	assert (r > 0 && r <= 65536) ;
	/*  post-condition:
    seed has value r.
*/
	seed = r ;
}

int next_pseudo_random_number() {
	//  pre-condition:
	assert (seed > 0 && seed <= 65536) ;
	/*  post-condition:
    result value > 0 and result value <= 65536 and result value != seed at entry of function
*/
	const int seed75 = seed * 75;
	int next = (seed75 & 65535) - (seed75 >> 16);
	if (next < 0)
		next += 65537 ;
	seed = next ;
	return next ;
}

char rotate(char a, int r, Action e) {
	//  Pre-condition:
//	assert(r > 0 && r <= 65536 && a >= 0);
	assert(r > 0);
	assert(r <= 65536);
//	assert(a > 0);
	//  Post-condition:
	// char a is rotated by r mod 128-32 places,
	// char a is a control character iff it were one initially
	char b;
	if (a < 32) {
		b = a;
	} else {
		if (e == Encrypt) {
			b = (a - 32 + (r % (128 - 32)) + (128 - 32)) % (128 - 32) + 32;
		} else if (e == Decrypt) {
			b = (a - 32 - (r % (128 - 32)) + (128 - 32)) % (128 - 32) + 32;
		} else {
			assert(false); // This shouldn't ever happen
			b = -1;
		}
	}
	return b;
}

const int test_r[] = { 1, 42, 96, 65535 };
void test_rotate() {
	//  Pre-conditie:
	assert(true);
	//  Post-conditie:
	// vul hier je post-conditie in
	int r;
	while (true) {
		cout << "Enter a value for r: ";
		cin >> r;
		if (r < 0) {
			break;
		}
		for (char a = 0; a < 127; a++) {
			cout << a << ' ' << rotate(a, r, Encrypt) << ' ' << rotate(rotate(a, r, Encrypt), r, Decrypt) << endl;
		}
	}
}

bool open_input_and_output_file(ifstream &infile, ofstream &outfile) {
	//  Pre-conditie:
	assert(!infile.is_open() && !outfile.is_open());
	//  Post-conditie:
	// The two files will be open if the output is True.
	// if the output is False, something went wrong and the output files aren't open
	string infile_name, outfile_name;
	cout << "Enter infile name: ";
	cin >> infile_name;
	cout << "Enter outfile name: ";
	cin >> outfile_name;

	infile.open(infile_name);
	outfile.open(outfile_name);

	bool status;

	if (infile && outfile) {
		cout << "Files opened succesfully" << endl;
		status = true;
	} else {
		cout << "Error while opening files" << endl;
		status = false;
		infile.close();
		outfile.close();
		infile.clear();
		outfile.clear();
	}
	return status;
}

void do_one_time_pad(Action mode, ifstream& infile, ofstream& outfile, int r) {
	initialise_pseudo_random(r);
	char current_char;
	
	while (infile) {
		infile.get(current_char);
		outfile.put(rotate(current_char, next_pseudo_random_number(), mode));
		cout << current_char;
	}
}

void one_time_pad() {
	Action mode;
	int mode_select = -1;
	
	do {
		cout << "Select a mode; 0 = Encrypt, 1 = Decrypt: ";
		cin >> mode_select;
	} while (mode_select != 0 && mode_select != 1);

	if (mode_select == 0)
		mode = Encrypt;
	else if (mode_select == 1)
		mode = Decrypt;
	else
		//fuck 
		assert(false);


	ifstream infile;
	ofstream outfile;
	open_input_and_output_file(infile, outfile);
	int r;
	cout << "Enter a value for r: ";
	cin >> r;
	do_one_time_pad(mode, infile, outfile, r);
	infile.close();
	outfile.close();
}

// Read the file into memory for speed:
string read_file(string filename) {
	ifstream infile;
	infile.open(filename);
	string return_string = "";
	char current_char;
	while (infile) {
		infile.get(current_char);
//		cout << current_char;
		return_string += current_char;
	}
	infile.close();
	cout << "Read " << return_string.length() << " chars." << endl;
	return return_string;
}


void secret() {

	// We'll hunt for spaces, because they are the most common characters in most texts
	int best_key = 0;
	int best_spaces = 0;
	string input_string = read_file("secret.txt");
	for (int key = 1; key < 65535; key++) {
		initialise_pseudo_random(key);
//		cout << key << endl;
		int num_spaces = 0;
		char plain;
		for (char& a : input_string) {
			plain = rotate(a, next_pseudo_random_number(), Decrypt);
//			cout << plain;
			if (plain == ' ') {
				num_spaces++;
			}
		}
		if (num_spaces > best_spaces){
			cout << "Found new best key: " << key  << ", with " << num_spaces << " spaces." << endl;
			best_spaces = num_spaces;
			best_key = key;
		}
	}
	cout << best_key;
}

int main() {
	one_time_pad();
//	secret();
	return 0;
}
