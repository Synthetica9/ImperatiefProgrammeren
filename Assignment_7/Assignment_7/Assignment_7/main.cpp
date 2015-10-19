#include <iostream>
#include <assert.h>
#include <string>
#include <fstream>
#include <set>
#include <cstdlib>
#include <algorithm>

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
const char spacer = ' ';

string read_word(ifstream& infile) {
	string word;
	char current_char = '\0';
	do {
		infile.get(current_char);
	} while (alphabet.count(current_char) == 0 && infile);
	
	while (infile) {
		if (alphabet.count(current_char) == 0) {
			if (current_char == connector) {
				char next_char;
				infile.get(next_char);
				if (alphabet.count(next_char) == 0) {
					return word;
				}
				word += current_char += next_char;
			}
			else {
				return word;
			}
		}
		word += current_char; // This is already a sensible value
		infile.get(current_char);
	};
	return word;
}

void complain() {
	cout << "Invalid command!" << endl;
}

string read_file(string filename) {
	ifstream infile;
	infile.open(filename);
	string file_content;
	if (infile) {
		int words_len;
		for (words_len = 0; infile; words_len++) {
			file_content += read_word(infile);
			file_content += spacer;
		}
		cout << "Read " << --words_len << " words!" << endl;
		return file_content;
	}
	cout << "Error reading file (Check your filename?)";
	return string();
}


void count_occurances(string to_find, string find_in, bool show_occurances, uint32_t show_context) {
	uint64_t last_index = 1;
	int counted = 0;
	do {
		last_index = find_in.find(to_find + " ", last_index) + 1;
		if (last_index != 0) { // Returnvalue of -1
			if (show_occurances) {
//				cout << last_index << ": ";
				// +1 as a correction to 0-indexing
				cout << count(find_in.c_str(), find_in.c_str() + last_index, ' ') + 1 << ": ";
				int start_context_index = last_index - 1;
				int end_context_index = last_index + to_find.length();
				for (int i = 0; i < show_context; i++) {
					while (start_context_index > 0 && find_in[--start_context_index] != spacer);
					while (end_context_index < find_in.length() && find_in[++end_context_index] != spacer);
				}
				for (int string_index = start_context_index + 1; string_index < end_context_index; string_index++) {
					cout << find_in[string_index];
				}
				cout << endl;
			}
			counted++;
		}
	} while (last_index != 0);
	cout << "Found a total number of " << counted << "." << endl;
}

string do_enter() {
	cin.ignore(1, ' '); // Dumps the space between the arguments
	string command_args;
	getline(cin, command_args);
	// Read a file
	cout << "Reading file \"" << command_args << '"' << endl;
	return read_file(command_args);
}

void get_command() {
	string file_content;
	while (true) {
		string command_name;
		cout << ">>> ";
		cin >> command_name; // Reads until the space

		if (command_name == "content") {
			cout << file_content << endl;
		}
		else if (command_name == "stop" || command_name == "exit" ||
			command_name == "quit" || command_name == "\x04") { // \x04 = ctrl-d
			cout << "Bye!" << endl;
			exit(0);
		}
		else if (command_name == "enter") {
			file_content = do_enter();
		}
		else if (command_name == "count" || command_name == "context" || command_name == "where") {
			int context = 0;

			if (command_name == "context") {
				// We need to read an int first.
				cin >> context;
			}

			if (cin) {
				// Succesfully executed cin >> context, or didn't at all
				string to_find;
				getline(cin, to_find);
				count_occurances(to_find, file_content, command_name != "count", context);
//				count_occurances(to_find, command_name != "count", context);
			}
			else {
				complain();
				cin.ignore(1000, '\n');
				cin.clear();
			}


		}
		else {
			complain();
			cin.ignore(1000, '\n');
			cin.clear();
			if (int(command_name.length()) == 1) {
				cout << int(command_name[0]) << endl;
			}
		}
	}
	
	
}

int main() {
	get_command();
}