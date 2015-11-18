#include <iostream>
#include <assert.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;
// Name / student number / study student 1 : Patrick Hilhorst / s4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / s4576586 / Mathematics


const char connector = '-';
const int max_nr_of_words = 100000;
string words[max_nr_of_words];
int words_len = 0;

bool in_alphabet(char c) {
	// Pre-condition:
	//	assert(c > 0);
	// Post condition
	// Return is true iff char c is a member of the alphabet or equal to a single apostrophe
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'';
}

string read_word(ifstream &infile) {
	// Pre-condtion:
	assert(infile.is_open() && infile);
	// Post-condition:
	// Returns the next word in infile, according to the definition in the assignment, in the bonus.
	// infile is still open, further than it was before, and might have encountered an error 
	// (not guaranteed, but it is not guarranteed that it hasn't either)
	string word;
	char current_char = '\0';
	do {
		infile.get(current_char);
	} while (!in_alphabet(current_char) && infile);

	while (infile) {
		if (!in_alphabet(current_char)) {
			if (current_char == connector) {
				char next_char;
				infile.get(next_char);
				if (!in_alphabet(next_char)) {
					return word;
				}
				word += current_char += next_char;
			} else {
				return word;
			}
		}
		word += current_char; // This is already a sensible value
		infile.get(current_char);
	};
	return word;
}


bool read_file(string filename) {
	// Pre-condition:
	assert(true);
	// Post-condition
	// Return is true iff the file was successfully read.
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
	// Pre-condition:
	assert(words_len <= max_nr_of_words);
	// Post-condition:
	// The entire content of the array containing the words in displayed in cout.
	cout << "Showing " << words_len << " words" << endl;
	for (int i = 0; i < words_len; i++)
		cout << words[i] << ' ';
	cout << endl;
}

void display_context(int start_word_index, int end_word_index, int context) {
	// Pre-condition:
	assert(start_word_index <= end_word_index && context >= 0 && start_word_index >= 0 && end_word_index < words_len);
	// Post-condition:
	// The context of the word specified by start_word_index and end_word_index is output to cout.
	for (int j = max(0, start_word_index - context + 1); j <= min(end_word_index + context, words_len - 1); j++)
		cout << words[j] << ' ';
	cout << endl << endl;
}

void display_match(bool show_occurances, int show_context, int start_word_index, int end_word_index) {
	// Pre-condition:
	assert(start_word_index <= end_word_index && show_context >= 0 && start_word_index >= 0 && end_word_index < words_len);
	// Post-condition:
	// The occurance, specified by start_word_index and end_word_index is shown to screen iff show_occurances

	if (show_occurances)
		cout << "Found occurance at " << end_word_index << endl;

	// Show context, if context > 0;
	if (show_context > 0)
		display_context(start_word_index, end_word_index, show_context);
}

void show_summary(int occurances) {
	// Pre-condition:
	assert(words_len > 0 && occurances >= 0);
	// Post-condition:
	// A quick summary of the amount of occurances is shown to screen.
	if (occurances == 0)
		cout << endl << "Did not find any occurances!" << endl;
	else
		cout
			<< endl
			<< "Found " << occurances << " occurances." << endl
			<< "This represents " << float(occurances * 100) / words_len << "% of words" << endl;
}

void count_occurances(string to_find, bool show_occurances, int show_context) {
	// Pre-condition
	assert(to_find.length() > 0 && show_context >= 0);
	// Post-condition
	// Shows the count of to_find, and shows the occurances and the context if asked for
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
	// Pre-condition:
	assert(cin);
	// Post-condition:
	// Tries to read a file into memory and reports the status to the user.
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

void complain_and_tidy() {
	// Pre-condition:
	assert(true);
	// Post-condition:
	// Cin is cleared and the user is notified.
	cout << "Invalid command!" << endl;
	cin.ignore(1000, '\n');
	cin.clear();
}

void do_search(const string &command_name) {
	// Pre-condition:
	assert(command_name.length() > 0);
	// Post-condtion:
	// One of the 3 search commands is executed
	int context = 0;

	if (command_name == "context")
	// We need to read an int first.
		cin >> context;

	if (cin) {
		// Succesfully executed cin >> context, or didn't at all
		cin.ignore(1, ' ');
		string to_find;
		getline(cin, to_find);

		count_occurances(to_find, command_name != "count", context);
	} else
		complain_and_tidy();
}

void execute_command(const string &command_name) {
	// Pre-condition:
	assert(true);
	// Post-condtion:
	// One of the commands is executed
	if (command_name == "enter")
		do_enter();
	else if (words_len == 0) {
		cout << "Please enter a file first" << endl;
		complain_and_tidy();
	} else if (command_name == "content")
	// Show the content of the read file
		show_words();
	else if (command_name == "stop" || command_name == "exit" ||
		command_name == "quit" || command_name == "\x04") {// \x04 = ctrl-d
		cout << "Bye!" << endl;
		exit(0);
	} else if (command_name == "count" || command_name == "context" || command_name == "where")
		do_search(command_name);
	else
		complain_and_tidy();
}

void get_command() {
	// Pre-condition:
	assert(true);
	// Post-condtion:
	// The user is prompted for a command, this command is then executed
	string command_name;
	cout << ">>> ";
	cin >> command_name; // Reads until the space

	execute_command(command_name);
}

int main() {
	while (true)
		get_command();
}
