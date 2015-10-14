// Name / student number / study student 1 : Patrick Hilhorst / s4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / s4576586 / Mathematics

#include <iostream>
#include <fstream>
#include <cassert>
#include <windows.h> // Sleep (msec)

#include "cursor.h" // if you are developing on Windows


using namespace std;

enum Cell { Dead, Live }; // a cell is either Dead or Live

const char dead = '.'; // the presentation of a dead cell (both on file and screen)
const char live = '*'; // the presentation of a live cell (both on file and screen)
const int NrOfRows = 40; // the number of rows (height) of the universe (both on file and screen)
const int NrOfColumns = 60; // the number of columns (width) of the universe (both on file and screen)
const int Rows = NrOfRows + 2; // the number of rows in a universe array, including the 'frame' of dead cells
const int Columns = NrOfColumns + 2; // the number of columns in a universe array, including the 'frame' of dead cells

const int MaxFilenameLength = 80; // the maximum number of characters for a file name (including termination character)

int Sleeptime = 20; // the pause time between animation-frames in msec

typedef Cell Universe[Rows][Columns];

const int search_radius = 1;

bool survive[] = {
	false, // 0
	false, // 1
	true,  // 2
	true,  // 3
	false, // 4
	false, // 5
	false, // 6
	false  // 7
};

bool birth[] = {
	false, // 0
	false, // 1
	false, // 2
	true,  // 3
	false, // 4
	false, // 5
	false, // 6
	false  // 7
};

Cell token_to_Cell(char token) {
	// Precondition:
	assert(token == dead || token == live);
	/*  Postcondition:
	result is Dead in case of dead token, and result is Live in case of live token.
	*/
	if(token == dead)
		return Dead;
	else
		return Live;
}

char Cell_to_token(Cell cell) {
	// Precondition:
	assert(true);
	/*  Postcondition:
	result is dead in case of Dead cell, and result is live in case of Live cell.
	*/
	if(cell == Dead)
		return dead;
	else
		return live;
}

bool enter_filename(char filename[MaxFilenameLength]) {
	// Precondition:
	assert(MaxFilenameLength > 0);
	/*  Postcondition:
	The result is true only if the user has entered a name that does not exceed MaxFilenameLength characters.
	In that case, filename contains this name. The newline character is replaced by the '\0' character.
	The result is false otherwise, and the content of filename must be considered to be corrupt, i.e. useless.
	*/
	int i = -1;
	do
		cin.get(filename[++i]);
	while(i < MaxFilenameLength && filename[i] != '\n');
	filename[i] = '\0';
	return i < MaxFilenameLength;
}

template <typename T>
bool read_universe_file(T&& inputfile, Universe universe) {
	// Precondition:
	assert(inputfile.is_open() && NrOfRows > 0 && NrOfColumns > 0);
	/*  Postcondition:
	The content of inputfile is read and copied to universe. The result is true only if the input file
	contains NrOfRows lines that each consist of NrOfColumns characters, terminated with a newline.
	In that case the universe is filled.
	The result is false otherwise, and the content of universe must be considered to be corrupt, i.e. useless.
	*/

	bool reached_newline;
	char current_token;
	bool read_char;
	for(int y = 0; y < Rows; y++) {
		reached_newline = false;
		for(int x = 0; x < Columns; x++) {
			if(x != 0 && y != 0 && y != Rows - 1 && !reached_newline) {
				inputfile.get(current_token);
				read_char = true;
				if(current_token == '\n')
					reached_newline = true;
			} else {
				read_char = false;
			}

			if(!reached_newline && read_char) {
				universe[y][x] = token_to_Cell(current_token);
			} else {
				universe[y][x] = Dead;
			}
		}
		if(!reached_newline && y != 0 && y != Rows - 1) {
			inputfile.close();
			inputfile.clear();
			return false;
		}
	}
	// Check if we are at the end of the file, and return true if we are
	bool end_of_file = !inputfile.get(current_token);
	inputfile.close();
	inputfile.clear();
	return end_of_file;
}

template <typename T>
void write_universe_file(T&& outfile, Universe universe) {
	for(int y = 0; y < NrOfRows; y++) {
		for(int x = 0; x < NrOfColumns; x++) {
			outfile.put(Cell_to_token(universe[y + 1][x + 1]));
		}
		outfile.put('\n');
	}
	outfile.close();
	outfile.clear();
}

void show_universe(Universe universe) {
	// Precondition:
	assert(NrOfRows > 0 && NrOfColumns > 0);
	/*  Postcondition:
	The cells of universe are printed row by row (below each other), cell by cell (next to each other).
	The outer dead cells are not printed.
	*/

	for(int y = 1; y < Rows - 1; y++) {
		for(int x = 1; x < Columns - 1; x++)
			cout << Cell_to_token(universe[y][x]);
		cout << endl;
	}
}

void empty_universe(Universe universe) {
	// Precondition:
	assert(NrOfRows > 0 && NrOfColumns > 0);
	/* All cells in the universe are in the state Dead
	*/
	for(int y = 0; y < Rows; y++) {
		for(int x = 0; x < Columns; x++) {
			universe[y][x] = Dead;
		}
	}
}

template <typename T>
T open_file() {
	// Precondition:
	assert(True);
	/* Asks a user for the file, and returns an open file 
	(can be both ifstream and ofstream)
	*/
	T file;
	char filename[MaxFilenameLength];
	do {
		if (!file) {
			cout << "Couldn't open file!" << endl;
			file.clear();
			cin.clear();
		}
		cout << "Enter a filename: ";
		if (enter_filename(filename))
			file.open(filename);
		else
			cout << "Invalid filename!" << endl;
	} while (!file);
	return file;
}

void render_universe(Universe universe) {
	// Precondition:
	assert(NrOfRows > 0 && NrOfColumns > 0 && Sleeptime >= 0);
	/* Post-condtion
	Renders an universe to the screen, over what was already there, 
	and overwrites what was already there.*/
	set_cursor_position(0, 0);
	show_universe(universe);
	Sleep(Sleeptime);
}

void iter_universe(Universe old_universe, Universe new_universe) {
	assert(NrOfRows > 0 && NrOfColumns > 0);
	/*Post-condition:
	new_universe is now old_universe iterated by one step, 
	according to the life rules in survive and birth.
	*/
	for(int y = 0; y < NrOfRows; y++) {
		for(int x = 0; x < NrOfColumns; x++) {
			int neighbour = 0;
			for(int dy = 0; dy <= 2; dy++) {
				for(int dx = 0; dx <= 2; dx++) {
					if(!(dx == 1 && dy == 1))
						neighbour += old_universe[y + dy][x + dx] == Live;
				}
			}

			if ((birth[neighbour] && old_universe[y + 1][x + 1] == Dead) ||
				(survive[neighbour] && old_universe[y + 1][x + 1] == Live))
				new_universe[y + 1][x + 1] = Live;
			else
				new_universe[y + 1][x + 1] = Dead;
		}
	}
}

template <typename T>
bool get_input(T &out_var) {
	// Pre-condition:
	assert(true);
	/* Post-condition:
	-	out_var contains the value inputted on stdin by the user
	-	return is true when the read was successful, false otherwise.
	*/
	cin >> out_var;
	if(!cin) {
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}
	cin.ignore(1000, '\n');
	return true;
}

template <typename T>
void prompt(T &out_var, char const * prompt_text) {
	// Pre-condtion:
	assert(true);
	/* Post-condition:
	out_var contains a valid value for type T, inputted by the user
	*/
	do {
		cout << prompt_text;
	} while (!get_input(out_var));
}

void set_life_rules() {
	// Pre-condition
	assert(true);
	/*Post-condition:
	The user is prompted to select a set of rules for birth and survival of cells
	birth and survive are updated to reflect this choice*/
	bool B[] = { false, false, false, false, false, false, false, false };
	bool S[] = { false, false, false, false, false, false, false, false };
	cout
		<< "Presets: " << endl
		<< "1. \t Life (B3/S23)" << endl
		<< "2. \t Highlife (B36/S23)" << endl
		<< "3. \t Seeds (B2/S)" << endl
		<< "4. \t 2x2 (B36/S125)" << endl
		<< "5. \t Maze (B3/S12345)" << endl;
	int choice;
	prompt(choice, "Your choice? ");
	switch (choice) {
		case 1:
			B[3] = true;
			S[2] = true;
			S[3] = true;
			break;
		case 2:
			B[3] = true;
			B[6] = true;
			S[2] = true;
			S[3] = true;
			break;
		case 3:
			B[2] = true;
			break;
		case 4:
			B[3] = true;
			B[6] = true;
			S[1] = true;
			S[2] = true;
			S[5] = true;
			break;
		case 5:
			B[3] = true;
			S[1] = true;
			S[2] = true;
			S[3] = true;
			S[4] = true;
			S[5] = true;
			break;
	}
	for (int i = 0; i < 8; i++) {
		birth[i] = B[i];
		survive[i] = S[i];
	}
}

void run_universe(Universe& universe, int iterations) {
	Universe tmp_universe;
	for (int i = 0; i < iterations; i++) {
		render_universe(universe);
		iter_universe(universe, tmp_universe);
		swap(universe, tmp_universe);
	}
}

void run_universe() {
	Universe universe;
	int iterations;
	int input = -1;

	empty_universe(universe);

	while (input != 6) {
		render_universe(universe);
		cout
			<< "1. \t Start execution" << endl
			<< "2. \t Change execution speed" << endl
			<< "3. \t Change life rules" << endl
			<< "4. \t Load universe file" << endl
			<< "5. \t Write current universe to file" << endl
			<< "6. \t Quit" << endl;
		prompt(input, "Your choice: ");
		switch (input) {
			case 1:
				prompt(iterations, "Enter a number of iterations to run: ");
				run_universe(universe, iterations);
				break;
			case 2:
				prompt(Sleeptime, "Enter sleep time (ms): "); 
				break;
			case 3:
				set_life_rules(); 
				break;
			case 4: 
				read_universe_file(open_file<ifstream>(), universe);
				break;
			case 5:
				write_universe_file(open_file<ofstream>(), universe);
				break;
			case 6:
				return;
		}
	}
}

int main() {
	run_universe();
	return 0;
}
