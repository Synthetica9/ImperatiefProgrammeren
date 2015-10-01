#include <iostream>
#include <fstream>          // voor file I/O
#include <cassert>          // voor assertion checking

using namespace std;

enum Action {Encrypt, Decrypt};

int seed = 0 ;
void initialise_pseudo_random (int r)
{
//  pre-condition:
    assert (r > 0 && r <= 65536) ;
/*  post-condition:
    seed has value r.
*/
    seed = r ;
}

int next_pseudo_random_number ()
{
//  pre-condition:
    assert (seed > 0 && seed <= 65536) ;
/*  post-condition:
    result value > 0 and result value <= 65536 and result value != seed at entry of function
*/
    const int seed75 = seed * 75 ;
    int next = (seed75 & 65535) - (seed75 >> 16) ;
    if (next < 0)
        next += 65537 ;
    seed = next ;
    return next ;
}

char rotate (char a, int r, Action e)
{
//  Pre-conditie:
    // vul hier je pre-conditie in
//  Post-conditie:
    // vul hier je post-conditie in

}

void test_rotate ()
{
//  Pre-conditie:
    // vul hier je pre-conditie in
//  Post-conditie:
    // vul hier je post-conditie in
}

bool open_input_and_output_file (ifstream& infile, ofstream& outfile)
{
//  Pre-conditie:
    // vul hier je pre-conditie in
//  Post-conditie:
    // vul hier je post-conditie in
}

int main ()
{
}
