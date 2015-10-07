// Assignment 5
// Name / student number / study student 1 : Patrick Hilhorst / S4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / S4576586 / Mathematics

#include <iostream>
#include <fstream> // voor file I/O
#include <cassert> // voor assertion checking
#include <string>
#include <algorithm>

using namespace std;

enum Action { Encrypt, Decrypt };

int seed = 0;

void initialise_pseudo_random(int r) {
	//  pre-condition:
	assert(r > 0 && r <= 65536);
	/*  post-condition:
	seed has value r.*/
	seed = r;
}

int next_pseudo_random_number() {
	//  pre-condition:
	assert(seed > 0 && seed <= 65536);
	/*  post-condition:
	result value > 0 and result value <= 65536 and result value != seed at entry of function*/
	const int seed75 = seed * 75;
	int next = (seed75 & 65535) - (seed75 >> 16);
	if(next < 0)
		next += 65537;
	seed = next;
	return next;
}

template <typename T>
bool get_input(T &out_var) {
	cin >> out_var;
	if(!cin) {
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}
	return true;
}

char rotate(char a, int r, Action e) {
	//  Pre-condition:
	assert(r >= 0 && r <= 65536);
	/*  Post-condition:
	Result is char a rotated by r mod 128-32 places iff it is not a control character,
	Result is char a iff it is a control character. */
	char b;
	if(a < 32) {
		b = a;
	} else {
		if(e == Encrypt) {
			b = (a - 32 + (r % (128 - 32)) + (128 - 32)) % (128 - 32) + 32;
		} else if(e == Decrypt) {
			b = (a - 32 - (r % (128 - 32)) + (128 - 32)) % (128 - 32) + 32;
		} else {
			assert(false); // This should never happen
			b = -1;
		}
	}
	return b;
}

const int test_r[] = { 1, 42, 96, 65535 };

void test_rotate() {
	//  Pre-condition:
	assert(true);
	/*  Post-condition:
	For non-negative values the function emits for each ASCII display character a, a line of output containing: 
	the character a, 
	the value of rotate(a, r, Encrypt), and 
	the value of rotate(rotate(a, r, Encrypt), r, Decrypt). 
	
	The last value should always be equal to the first value, and the second value is always different 
	except when r is a multiple of (128-32). */
	int r;
	while(true) {
		cout << "Enter a value for r: ";
		if(get_input(r)) {
			if(r < 0) {
				break;
			}
			for(char a = 32; a < 127; a++) {
				cout << a << ' ' << rotate(a, r, Encrypt) << ' ' << rotate(rotate(a, r, Encrypt), r, Decrypt) << endl;
			}
		} else {
			// Something went wrong reading from stdin
			cout << "Malformed number!" << endl;
		}
	}
}

bool open_input_and_output_file(ifstream &infile, ofstream &outfile) {
	//  Pre-condition:
	assert(!infile.is_open() && !outfile.is_open());
	/*  Post-condition:
	Result is true if both files opened succesfully,
	result is false if opening both files failed. */
	string infile_name, outfile_name;
	do
		cout << "Enter infile name: ";
	while(!get_input(infile_name));

	do
		cout << "Enter outfile name: ";
	while(!get_input(outfile_name));

	infile.open(infile_name);
	outfile.open(outfile_name);

	if(infile && outfile) {
		cout << "Files opened succesfully" << endl;
		return true;
	}
	cout << "Error while opening files" << endl;
	infile.close();
	outfile.close();
	infile.clear();
	outfile.clear();
	return false;
}

void do_one_time_pad(Action mode, ifstream& infile, ofstream& outfile, int r) {
	initialise_pseudo_random(r);
	char current_char;
	char plain;
	while(infile) {
		infile.get(current_char);
		plain = rotate(current_char, next_pseudo_random_number(), mode);
		outfile.put(plain);
		//cout << plain;
	}
}

void one_time_pad() {
	Action mode;
	int mode_select = -1;

	do {
		cout << "Select a mode; 0 = Encrypt, 1 = Decrypt: ";
	} while(!get_input(mode_select) || mode_select < 0 || mode_select > 1);

	if(mode_select == 0)
		mode = Encrypt;
	else
		mode = Decrypt;


	ifstream infile;
	ofstream outfile;
	if(open_input_and_output_file(infile, outfile)) {
		int r;
		do
			cout << "Enter a value for r: ";
		while(!get_input(r));
		do_one_time_pad(mode, infile, outfile, r);
		cout << "Done!" << endl;
		infile.close();
		outfile.close();
	}
}

// Read the file into memory for speed:
string read_file(string filename) {
	ifstream infile;
	infile.open(filename);
	string return_string = "";
	char current_char;
	while(infile) {
		infile.get(current_char);
		//cout << current_char;
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
	for(int key = 1; key < 65535; key++) {
		initialise_pseudo_random(key);
		int num_spaces = 0;

		// It is not necessary to analyze the entire text. Analyzing ~1000 characters is sufficient.
		for(int i = 0; i < min(int(input_string.length()), 1000); i++)
		{
			if(rotate(input_string[i], next_pseudo_random_number(), Decrypt) == ' ') {
				num_spaces++;
			}
		}
		
		if(num_spaces > best_spaces) {
			cout << "Found new best key: " << key << ", with " << num_spaces << " spaces." << endl;
			best_spaces = num_spaces;
			best_key = key;
		}
	}
	cout << "The best key: " << best_key << endl;
	ifstream infile;
	ofstream outfile;
	infile.open("secret.txt");
	outfile.open("source.txt");
	do_one_time_pad(Decrypt, infile, outfile, best_key);
	infile.close();
	outfile.close();
}

int main() {
	int choice = -1;
	while(choice != 4) {
		cout
			<< "1: Test the rotation function" << endl
			<< "2: Encrypt or decrypt a file." << endl
			<< "3: Crack the secret code!" << endl
			<< "4: Quit." << endl
			<< "Your choice? ";
		if(get_input(choice)) {
			if(choice == 1)
				test_rotate();
			else if(choice == 2)
				one_time_pad();
			else if(choice == 3)
				secret();
			else if(choice == 4)
				// We don't need to break, because of the condition of the loop
				cout << "Bye!" << endl;
			else
				cout << "Come again?" << endl;
		} else {
			cout << "Malformed number!" << endl;
		}
	}
	return 0;
}
