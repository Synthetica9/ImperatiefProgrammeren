#include <iostream>
#include <fstream>
#include <cassert>
#include <windows.h>        // Sleep (msec)
#include "cursor.h"         // if you are developing on Windows

using namespace std;

enum Cell {Dead, Live};     // a cell is either Dead or Live

const char dead             = '.' ;               // the presentation of a dead cell (both on file and screen)
const char live             = '*' ;               // the presentation of a live cell (both on file and screen)
const int NrOfRows          = 40 ;                // the number of rows (height) of the universe (both on file and screen)
const int NrOfColumns       = 60 ;                // the number of columns (width) of the universe (both on file and screen)
const int Rows              = NrOfRows    + 2 ;   // the number of rows in a universe array, including the 'frame' of dead cells
const int Columns           = NrOfColumns + 2 ;   // the number of columns in a universe array, including the 'frame' of dead cells

const int MaxFilenameLength = 80 ;                // the maximum number of characters for a file name (including termination character)

const int Sleeptime         = 100 ;               // the pause time between animation-frames in msec

Cell token_to_Cell (char token)
{// Precondition:
    assert (token == dead || token == live) ;
/*  Postcondition:
    result is Dead in case of dead token, and result is Live in case of live token.
*/  if (token == dead)
        return Dead ;
    else
        return Live ;
}

char Cell_to_token (Cell cell)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    result is dead in case of Dead cell, and result is live in case of Live cell.
*/  if (cell == Dead)
        return dead ;
    else
        return live ;
}

bool enter_filename (char filename [MaxFilenameLength])
{// Precondition:
    assert ( MaxFilenameLength > 0 ) ;
/*  Postcondition:
    The result is true only if the user has entered a name that does not exceed MaxFilenameLength characters.
    In that case, filename contains this name. The newline character is replaced by the '\0' character.
    The result is false otherwise, and the content of filename must be considered to be corrupt, i.e. useless.
*/
}

bool read_universe_file (ifstream& inputfile, Cell universe [Rows][Columns])
{// Precondition:
    assert (inputfile.is_open() && NrOfRows > 0 && NrOfColumns > 0) ;
/*  Postcondition:
    The content of inputfile is read and copied to universe. The result is true only if the input file
    contains NrOfRows lines that each consist of NrOfColumns characters, terminated with a newline.
    In that case the universe is filled.
    The result is false otherwise, and the content of universe must be considered to be corrupt, i.e. useless.
*/
}

void show_universe (Cell universe [Rows][Columns])
{// Precondition:
    assert ( NrOfRows > 0 && NrOfColumns > 0 ) ;
/*  Postcondition:
    The cells of universe are printed row by row (below each other), cell by cell (next to each other).
    The outer dead cells are not printed.
*/
}

int main()
{
    return 0 ;
}
