#include <iostream>
#include <assert.h>
#include <string>
#include <regex>
#include <fstream>
#include <set>
using namespace std;

// Name / student number / study student 1 : Patrick Hilhorst / s4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / s4576586 / Mathematics


// "{'" + "', '".join(string.ascii_letters) + "'}"
const set<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
						    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
						    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
						    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
						    '\''};
const char connector = '-';

// From slides (adapted to a template):
template < typename T, typename U >
int sequential_search(T array, int from, int to, U search_value) {   
	// pre-condition:
	assert(0 <= from && 0 <= to);
	//  post-condition: 
	//  if from > to:	result value = to+1
	//  if search_value is not an element of array[from] .. array[to]:
	//		result value = to+1
	//  otherwise:	result value is the index of the first occurrence of 
	//		search_value in array[from] .. array[to]
	//		hence: from <= result value <= to
	if (from > to)
		return to + 1;
	int  position = from;
	while (position <= to && array[position] != search_value)
		position++;
	return  position;
}

string read_word(ifstream& infile) {
	string word;
	char current_char = '\0';
	do {
		infile.get(current_char);
	} while (alphabet.count(current_char) == 0);
	
	while (true) {
		word += current_char; // This is already a sensible value
		if (alphabet.count(current_char) == 0) {
			if (current_char == connector) {
				char next_char;
				infile.get(next_char);
				if (alphabet.count(next_char) == 0) {
					return word;
				}
				word += current_char += next_char;
			}
		}
	};
}

void get_command() {
	string command_name;
	cout << ">>> ";
	cin >> command_name; // Reads until the space
	cin.ignore(1, ' '); // Dumps the space between the arguments

	vector<string> current_content;

	string command_args;
	getline(cin, command_args);

	if (command_name == "enter") {
		// Read a file
		cout << "Reading file \"" << command_args << '"' << endl;

	} else if (command_name == "content") {
		// Show the content of the read file
	} else if (command_name == "stop") {
		cout << "Bye!" << endl;
		exit(0);
	} else {
		cout << "Invalid command!" << endl;
	}
}

int main() {
	while (true)
		get_command();
}