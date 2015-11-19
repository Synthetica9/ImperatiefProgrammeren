// Name / student number / study student 1 : Patrick Hilhorst / s4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / s4576586 / Mathematics

/*********************************************************************
*   Voorbeeldraamwerk voor opdracht 1 IPC015.
*   Inhoud:
*   - de type definities voor de muziek DB;
*   - ordeningsrelaties op Track;
*   - inlezen van Nummers.txt bestand;
*   - functies en datastructuren uit hoorcollege #1 IPC015:
*   - sorteer-algoritmen insertion_sort, selection_sort, bubble_sort
*     (gebaseerd op arrays)
*   - main die Nummers.txt inleest en een sorteer-algoritme aanroept.
**********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <chrono>

/* The OPTIONAL_REF is to be able to quickly change between having references and having pass-by value, for performance
 * testing purposes. On my machine, with my compiler (Arch, CLion internal compiler, default settings), I get the
 * following results (these results are in no way accurate, it's only one run, etc etc.):
 *
 * | Algorithm | Pass-by-reference | Pass-by-value |
 * |-----------|-------------------|---------------|
 * | Insertion | 761.581 ms        | 13345.6 ms    |
 * | Selection | 337.453 ms        | 3127.27 ms    |
 * | Bubble    | 0.373419 ms       | 2.73061 ms    |
 */
#define OPTIONAL_REF &

using namespace std;


/*********************************************************************
*   MuziekDB type definities en globale array liedjes:
**********************************************************************/
struct Length {
    int minutes;                            // #minuten  (0..)
    int seconds;                            // #seconden (0..59)
};
struct Track {
    string artist;                          // naam van uitvoerende artiest
    string cd;                              // titel van cd
    int year;                            // jaar van uitgave
    int track;                            // nummer van track
    string title;                           // titel van track
    string tags;                            // tags van track
    Length time;                            // lengte van track
    string country;                         // land van artiest
};

typedef Track El;
typedef vector<Track> MuziekDB;


/************************************************************************
*   Ordenings-relaties op Track:
*      definieer zelf < en == voor Length en Track, dan volgen
*      de overige ordeningen (>, <=, >=, >) daar vanzelf uit.
************************************************************************/

bool operator<(const Length &a, const Length &b) {
    return a.minutes < b.minutes ? true : a.seconds < b.seconds;
}

bool operator==(const Length &a, const Length &b) {
    return a.minutes == b.minutes && a.seconds == b.seconds;
}

//	afgeleide ordeningen op Length waarden:
bool operator>(const Length &a, const Length &b) {
    return b < a;
}

bool operator<=(const Length &a, const Length &b) {
    return !(b < a);
}

bool operator>=(const Length &a, const Length &b) {
    return b <= a;
}

bool operator<(const Track &a, const Track &b) {
    if (a.artist < b.artist)
        return true;
    else if (a.cd < b.cd)
        return true;
    else if (a.year < b.year)
        return true;
    else if (a.track < b.track)
        return true;
    else
        return a.time < b.time;
}

bool operator==(const Track &a, const Track &b) {
    return a.artist == b.artist &&
           a.cd == b.cd &&
           a.year == b.year &&
           a.track == b.track &&
           a.time == b.time;
}

//	afgeleide ordeningen op Track waarden:
bool operator>(const Track &a, const Track &b) {
    return b < a;
}

bool operator<=(const Track &a, const Track &b) {
    return !(b < a);
}

bool operator>=(const Track &a, const Track &b) {
    return b <= a;
}


/************************************************************************
*   Inlezen van Nummers.txt bestand:
************************************************************************/
istream &operator>>(istream &in, Length &lengte) {// Preconditie:
    assert (true);
/*  Postconditie:
    de waarde van lengte is ingelezen uit in: eerst minuten, daarna ':', daarna seconden.
*/
    char colon;
    in >> lengte.minutes >> colon >> lengte.seconds;
    return in;
}

ostream &operator<<(ostream &out, const Length lengte) {
    out << lengte.minutes << ':';
    if (lengte.seconds < 10)
        out << '0';
    out << lengte.seconds;
    return out;
}

istream &operator>>(istream &infile, Track &track) {
    string dummy;
    getline(infile, track.artist);       // artist
    getline(infile, track.cd);           // cd
    infile >> track.year;              // year
    getline(infile, dummy);            // verwijder t/m newline
    infile >> track.track;             // track nr
    getline(infile, dummy);            // verwijder t/m newline
    getline(infile, track.title);        // track title
    getline(infile, track.tags);         // track tags
    infile >> track.time;              // track time
    getline(infile, dummy);            // verwijder t/m newline
    getline(infile, track.country);      // country
    getline(infile, dummy);            // verwijder t/m newline
    return infile;
}

ostream &operator<<(ostream &out, const Track track) {
    out << track.artist << " " << track.cd << " [" << track.track << "] (" << track.time << ")";
    return out;
}

MuziekDB lees_liedjes(ifstream &infile) {
    Track tmp;
    MuziekDB liedjes;
    do {
        infile >> tmp;
        liedjes.push_back(tmp);
    }
    while (infile);
    return liedjes;
}

MuziekDB lees_bestand(string bestandnaam) {
    ifstream nummersDBS(bestandnaam.c_str());
    if (!nummersDBS) {
        cout << "Kon '" << bestandnaam << "' niet openen." << endl;
        exit(-1);
    }
    cout << "Lees '" << bestandnaam << "' in." << endl;
//	nummersDBS.close(); RAII?
    return lees_liedjes(nummersDBS);
}

void toon_MuziekDB(MuziekDB liedjes) {
    int i = 0;
    for (Track liedje : liedjes)
        cout << ++i << ". " << liedjes[i] << endl;
}

/************************************************************************
*   functies en datastructuren uit hoorcollege #1 IPC015:
************************************************************************/
struct Slice {
    int from;    // 0    <= from
    int to;    // from <= to
};

Slice mkSlice(int from, int to) {
//	pre-condition:
    assert (0 <= from && from <= to);
    Slice s = {from, to};
    return s;
}

bool valid_slice(Slice s) {
    return 0 <= s.from && s.from <= s.to;
}

bool is_sorted(MuziekDB OPTIONAL_REF array, Slice s) {
//	pre-condition:
    assert (valid_slice(s));    // ...and s.to < size of array
//	post-condition:
//	result is true if	array[s.from]   <= array[s.from+1]
//						array[s.from+1] <= array[s.from+2]
//						...
//						array[s.to-1]   <= array[s.to]
    bool sorted = true;
    for (int i = s.from; i < s.to && sorted; i++)
        if (array[i] > array[i + 1])
            sorted = false;
    return sorted;
}

int find_position(MuziekDB OPTIONAL_REF array, Slice s, El y) {
//	pre-condition:
    assert (valid_slice(s));
    assert ( is_sorted(array, s));    // ...and s.to < size of array
//	post-condition: s.from <= re1sult <= s.to+1
    for (int i = s.from; i <= s.to; i++)
        if (y <= array[i])
            return i;
    return s.to + 1;
}

void shift_right(MuziekDB OPTIONAL_REF array, Slice s) {
//	pre-condition:
    assert (valid_slice(s));    // ... and s.to < size (array) - 1
//	post-condition:  array[s.from+1]	= 	old array[s.from]
//			    	 array[s.from+2]	= 	old array[s.from+1]
//						...
//			    	 array[s.to+1]		= 	old array[s.to]
    for (int i = s.to + 1; i > s.from; i--)
        array[i] = array[i - 1];
}

void insert(MuziekDB OPTIONAL_REF array, int &length, El y) {
    const int pos = find_position(array, mkSlice(0, length - 1), y);
    if (pos < length)
        shift_right(array, mkSlice(pos, length - 1));
    array[pos] = y;
    length++;
}

/************************************************************************
*   array-based sorteer-algoritmen uit hoorcollege #1 IPC015:
************************************************************************/
//	array-based insertion sort:
void insertion_sort(MuziekDB OPTIONAL_REF array) {
    int length = int(array.size());
    int sorted = 1;
    while (sorted < length) {
        insert(array, sorted, array[sorted]);
    }
}

//	array-based selection sort:
int smallest_value_at(MuziekDB OPTIONAL_REF array, Slice s) {
//	pre-condition:
    assert (valid_slice(s));    // ... and s.to < size (s)
//	Post-condition: s.from <= result <= s.to and array[result] is
//	the minimum value of array[s.from] .. array[s.to]
    int smallest_at = s.from;
    for (int index = s.from + 1; index <= s.to; index++)
        if (array[index] < array[smallest_at])
            smallest_at = index;
    return smallest_at;
}

void selection_sort(MuziekDB OPTIONAL_REF array) {
    int length = array.size();
    for (int unsorted = 0; unsorted < length; unsorted++) {
        const int k = smallest_value_at(array, mkSlice(unsorted, length - 1));
        swap(array[unsorted], array[k]);
    }
}

////	array-based bubble sort:
//bool bubble(MuziekDB & array, Slice s) {
////	pre-condition:
//    assert (valid_slice(s));    // ... and s.to < size(array)
////	Post-condition:
////	maximum of array[s.from]..array[s.to] is at array[s.to]
////	if result is true then sorted( array, s )
//    bool is_sorted = true;
//    for (int i = s.from; i < s.to; i++)
//        if (array[i] > array[i + 1]) {
//            iter_swap(array.begin() + i, array.begin() + i + 1);
//            is_sorted = false;
//        }
//    return is_sorted;
//}

//void bubble_sort(MuziekDB OPTIONAL_REF array) {
//    int length = array.size();
//    while (!bubble(array, mkSlice(0, length - 1)))
//        length--;
//}

MuziekDB bubble_sort(MuziekDB OPTIONAL_REF array){
    int swapcount;
    int total_swaps = 0;
    do {
        swapcount = 0;
        int i = 0;
        for (int i = 0; i < array.size() - 1; i++){
            if (array[i] > array[i+1]){
//              cout << "Swapping: " << endl;
//              cout << array[i] << array[i+1];
                iter_swap(array.begin() + i, array.begin() + i + 1);
                swapcount ++;
            }
        }
        total_swaps += swapcount;
    } while (swapcount > 0);
    cout << total_swaps << endl;
    return array;
}


/************************************************************************
*   de hoofdstructuur van het programma:
*       - lees bestand in
*       - sorteer bestand met insertion_sort / selection_sort / bubble_sort
*                          en 'normale' volgorde van Tracks
*                          en oplopend naar track-lengte
************************************************************************/
enum Sorteermethode {
    Insertion, Selection, Bubble, AantalMethoden
};
string sorteermethode[] = {"insertion", "selection", "bubble"};

Sorteermethode selecteer() {
    cout << "Kies een sorteermethode: " << endl;
    for (int m = 0; m < AantalMethoden; m++)
        cout << m + 1 << ": " << sorteermethode[m] << " sort" << endl;
    int keuze;
    cin >> keuze;
    return static_cast<Sorteermethode>(keuze - 1);
}

int main() {
    MuziekDB liedjes = lees_bestand("Nummers.txt");
    Sorteermethode m = selecteer();
    cout << "Sorteren bestand met " << sorteermethode[m] << " sort" << endl;
    chrono::steady_clock clock;
    chrono::time_point<chrono::steady_clock> time_before = clock.now();
    switch (m) {
        case Insertion:
            insertion_sort(liedjes);
            break;
        case Selection:
            selection_sort(liedjes);
            break;
        case Bubble:
            bubble_sort(liedjes);
            break;
        default:
            cout << "Huh?" << endl;
    }
    chrono::time_point<chrono::steady_clock> time_after = clock.now();
    auto diff = time_after - time_before;

    cout << "Bestand gesorteerd." << endl;
    toon_MuziekDB(liedjes);
    cout << "Sort took " << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}
