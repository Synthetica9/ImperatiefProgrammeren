#include <iostream>
#include <assert.h>
#include <string>
#include <fstream>
#include <set>
#include <cstdlib>

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
const int max_nr_of_words = 100000;
string words[max_nr_of_words];
int words_len = 0;

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

bool read_file(string filename) {
	ifstream infile;
	infile.open(filename);
	if (infile) {
		for (words_len = 0; words_len < max_nr_of_words && infile; words_len++) {
			string current_word = read_word(infile);
			words[words_len] = current_word;
		}
		cout << "Read " << --words_len << " words!" << endl;
		return words_len < max_nr_of_words;
	}
	return false;
}

void show_words() {
	cout << "Showing " << words_len << " words" << endl;
	for (int i = 0; i < words_len; i++) {
		cout << words[i] << ' ';
	}
	cout << endl;
}

void display_context(int start_word_index, int end_word_index, int context) {
	{
		for (int j = start_word_index - context + 1; j <= end_word_index + context; j++)
			cout << words[j] << ' ';
		cout << endl << endl;
	}
}

void display_match(bool show_occurances, int show_context, int start_word_index, int end_word_index) {
	if (show_occurances)
		cout << "Found occurance at " << end_word_index << endl;

	// Show context, if context > 0;
	if (show_context > 0)
		display_context(start_word_index, end_word_index, show_context);
}

void show_summary(int occurances) {
	cout
		<< endl
		<< "Found " << occurances << " occurances." << endl
		<< "This represents " << occurances / words_len * 100 << "% of words" << endl;
}

void count_occurances(string to_find, bool show_occurances, int show_context) {
	int occurances = 0, to_find_index = 0, start_word_index = 0;
	cout << "Looking for string with length " << to_find.length() << endl;
	for (int i = 0; i < words_len; i++) {
		for (char c : words[i]) {
			if (to_find[to_find_index++] != c || to_find_index > to_find.length()) {
				to_find_index = -1;
				// Gets incremented to 0 directly outside the loop
				start_word_index = i;
				break;
			}
		}
		if (to_find_index == int(to_find.length())) {
			// Found a match
			occurances++;
			to_find_index = -1;
			display_match(show_occurances, show_context, start_word_index, i);
			
		}
		to_find_index++;
		// Account for the space. 

	}
	show_summary(occurances);
}

void do_enter() {
	cin.ignore(1, ' '); // Dumps the space between the arguments
	string command_args;
	getline(cin, command_args);
	// Read a file
	cout << "Reading file \"" << command_args << '"' << endl;
	cout <<
		(read_file(command_args)
			 ? "Succesfully read a file!"
			 : "Error reading file! (check your filename?)")
		<< endl;
}

void get_command() {
	string command_name;
	cout << ">>> ";
	cin >> command_name; // Reads until the space
	
	if (command_name == "content") {
		// Show the content of the read file
		show_words();
	}
	else if (command_name == "stop" || command_name == "exit" || 
			 command_name == "quit" || command_name == "\x04") { // \x04 = ctrl-d
		cout << "Bye!" << endl;
		exit(0);
	}
	else if (command_name == "enter") {
		do_enter();
	} else if (command_name == "count" || command_name == "context" || command_name == "where") {
		int context = 0;
		
		if (command_name == "context") {
			// We need to read an int first.
			cin >> context;
		}

		if (cin) {
			// Succesfully executed cin >> context, or didn't at all
			cin.ignore(1, ' ');
			string to_find;
			getline(cin, to_find);

			count_occurances(to_find, command_name != "count", context);
		} else {
			complain();
			cin.ignore(1000, '\n');
			cin.clear();
		}
		

	} else {
		complain();
		cin.ignore(1000, '\n');
		cin.clear();
		if (int(command_name.length()) == 1) {
			cout << int(command_name[0]) << endl;
		}
	}
	
}

int main() {
	while (true)
		get_command();
}