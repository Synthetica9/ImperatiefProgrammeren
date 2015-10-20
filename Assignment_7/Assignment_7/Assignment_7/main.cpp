// Name / student number / study student 1 : Patrick Hilhorst / s4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / s4576586 / Mathematics

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const char Space = ' ';

bool in_alphabet(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'';
}

// To avoid recognizing "'" as a single-letter word:
bool in_pure_alphabet(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void read_words(string* words, string file) {
	string current_word;
	int count = 0;
	for(int i = 0; i < file.length(); i++) {
		char current_char = file[i];
		if(in_alphabet(current_char)) {
			current_word += current_char;
		} else if(current_char == '-') {
			if(!in_alphabet(file[i + 1])) {
				words[count] = current_word;
				current_word = string();
				count++;
				i++;
			}
		} else {
			words[count] = current_word;
			current_word = string();
			count++;
			while(!in_pure_alphabet(file[++i])) {}
			i--;
		}
	}
}

char next(ifstream& infile, string& output) {
	if(!infile) {
		return 'a';
	}
	char c = infile.get();
	output += c;
	return c;
}

int count_words(string filename, string& output) {
	int words = 2;
	ifstream infile;
	infile.open(filename);
	while(infile) {
		char current_char = next(infile, output);
		if(in_alphabet(current_char)) {

		} else if(current_char == '-') {
			words += !in_alphabet(next(infile, output));
		} else {
			words++;
			while(!in_pure_alphabet(next(infile, output))) {}
			words += !in_pure_alphabet(next(infile, output));
		}
	}
	return words;
}

string* split_string(string s, int& count) {
	string* output;

	count = 1;
	for(int i = 0; i < s.length(); i++) {
		count += s[i] == ' ';
	}

	output = new string[count];

	int n = 0;
	string current_word;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ') {
			output[n] = current_word;
			current_word = string();
			n++;
		} else {
			current_word += s[i];
		}
	}
	output[count - 1] = current_word;

	return output;
}

void find_words(string* buffer, int word_count, bool display, int context) {
	string search_string;
	cin.ignore(1, ' ');
	getline(cin, search_string);
	int count = 0;
	string* query = split_string(search_string, count);

	int occurances = 0;
	for(int i = 0; i < word_count - count + 1; i++) {
		bool match = true;
		for(int j = 0; j < count; j++) {
			if(query[j] != buffer[i + j]) {
				match = false;
				j = count;
			}
		}
		if(match) {
			occurances++;
			if(display) {
				cout << i << "\t: ";
				for(int n = max(0, context - i); n < context; n++) {
					cout << buffer[i + n - context] << ' ';
				}
				cout << buffer[i];
				for(int n = 0; n < min(context, word_count - i - 1); n++) {
					cout << ' ' << buffer[i + n + 1];
				}
				cout << endl;
			}
		}
	}
	cout << "Found " << occurances << " occurances." << endl;
}

int main() {
	string* buffer = nullptr;
	int word_count = 0;
	while(true) {
		string command_name;
		cout << ">>> ";
		cin >> command_name;
		if(command_name == "stop") {
			delete[] buffer;
			exit(0);
		} else if(command_name == "enter") {
			string filename, file;
			cin.ignore(1, ' ');
			getline(cin, filename);
			cout << "[" << filename << "]: ";
			word_count = count_words(filename, file);
			cout << word_count << endl;
			buffer = new string[word_count];
			read_words(buffer, file);
			cout << "Read " << word_count << " words. " << endl;
		} else if(command_name == "count" || command_name == "where" || command_name == "context") {
			int context = 0;
			if(command_name == "context") {
				cin >> context;
			}
			find_words(buffer, word_count, command_name != "count", context);
		} else if(command_name == "content") {
			for(int i = 0; i < word_count; i++) {
				cout << buffer[i] << " ";
			}
		} else {
			cin.ignore(10000, '\n');
		}
	}
}