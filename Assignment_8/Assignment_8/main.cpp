// Name / student number / study student 1 : Patrick Hilhorst / s4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / s4576586 / Mathematics

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;

struct Length
{
	int minutes;							// #minuten  (0..)
	int seconds;							// #seconden (0..59)
};

struct Track
{
	string artist;                          // naam van uitvoerende artiest
	string cd;                              // titel van cd
	int    year;                            // jaar van uitgave
	int    track;							// nummer van track
	string title;                           // titel van track
	string tags;                            // tags van track
	Length time;							// lengte van track
	string country;                         // land van artiest
};

struct TrackDisplay
{
	bool showArtist;						// toont artist als true
	bool showAlbum;							// toont cd titel als true
	bool showYear;							// toont year als true
	bool showTrack;							// toont track nr als true
	bool showTitle;							// toont track titel als true
	bool showTags;                          // toont tags als true
	bool showLength;						// toont track lengte als true
	bool showCountry;                       // toont country als true
};

bool match(string sub, string source) {// Preconditie:
	assert(true);
	/*  Postconditie:
		Resultaat is true alleen als sub een letterlijke (case-sensitive) deelstring is van source.
	*/
	return source.find(sub) != string::npos;
}

ostream& operator<< (ostream& out, const Length lengte) {// Preconditie:
	assert(true);
	/*  Postconditie:
		de waarde van lengte is getoond via out in de vorm: minuten, ':', seconden (tenminste 2 digits)
	*/
}

istream& operator>> (istream& in, Length& lengte) {// Preconditie:
	assert(true);
	/*  Postconditie:
		de waarde van lengte is ingelezen uit in: eerst minuten, daarna ':', daarna seconden.
	*/
}

Length operator+ (const Length& a, const Length& b) {// Preconditie:
	assert(0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60);
	/*  Postconditie:
		Resultaat is de som van a en b.
	*/
}

void show_track(Track lied, TrackDisplay lt) {// Preconditie:
	assert(true);
	/*  Postconditie:
		alleen die members van lied zijn getoond waarvan de corresponderende member in lt de waarde true heeft.
	*/
}

istream& operator>> (istream& in, Track& track) {// Preconditie:
	assert(true);
	/*  Postconditie:
		De inhoud van de eerstvolgende 8 regels uit in zijn gelezen en omgezet naar de corresponderende members in track.
		De daaropvolgende (lege) regel uit in is ook gelezen.
	*/
}

const int MAX_NR_OF_TRACKS = 5000;
typedef Track MusicDB[MAX_NR_OF_TRACKS];

int main() {// Preconditie:
	assert(true);
	/*  Postconditie:
		De muziekdatabase "Nummers.txt" is (indien aanwezig en correct geformatteerd) ingelezen.
		De gebruiker is in staat geweest database queries te stellen en heeft de antwoorden op deze
		queries gezien.
	*/
	return 0;
}