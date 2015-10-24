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

string time_to_string(int time) {
	assert(time >= 0 && time < 100);
	/*	Postconditie:
		Resultaat is een string van twee cijfers die time decimaal weergeven.
	*/
	string output;
	if(!time) {
		return "00";
	}
	if(time < 10) {
		output = "0";
	}
	output += to_string(time);
	return output;
}

ostream& operator<< (ostream& out, const Length lengte) {// Preconditie:
	assert(true);
	/*  Postconditie:
		de waarde van lengte is getoond via out in de vorm: minuten, ':', seconden (tenminste 2 digits)
	*/
	out << time_to_string(lengte.minutes) << ":" << time_to_string(lengte.seconds);
	return out;
}

istream& operator>> (istream& in, Length& lengte) {// Preconditie:
	assert(in);
	/*  Postconditie:
		de waarde van lengte is ingelezen uit in: eerst minuten, daarna ':', daarna seconden.
	*/
	lengte.minutes = 0;
	char current_char = '0';
	while(current_char != ':') {
		lengte.minutes *= 10;
		lengte.minutes += current_char - '0';
		in.get(current_char);
	}
	in >> lengte.seconds;
	in.ignore(1000, '\n');
	return in;
}

Length operator+ (const Length& a, const Length& b) {// Preconditie:
	assert(0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60);
	/*  Postconditie:
		Resultaat is de som van a en b.
	*/
	Length output = Length();
	output.seconds = (a.seconds + b.seconds) % 60;
	output.minutes = (a.seconds + b.seconds) / 60 + a.minutes + b.minutes;
	return output;
}

void show_track(Track lied, TrackDisplay lt) {// Preconditie:
	assert(true);
	/*  Postconditie:
		alleen die members van lied zijn getoond waarvan de corresponderende member in lt de waarde true heeft.
	*/
	if(lt.showArtist)
		cout << lied.artist << ", ";
	if(lt.showAlbum)
		cout << lied.cd << ", ";
	if(lt.showYear)
		cout << lied.year << ", ";
	if(lt.showTrack)
		cout << lied.track << ", ";
	if(lt.showTitle)
		cout << lied.title << ", ";
	if(lt.showTags)
		cout << "[" << lied.tags << "], ";
	if(lt.showLength)
		cout << lied.time << ", ";
	if(lt.showCountry)
		cout << lied.country << ", ";
	cout << "\b\b " << endl;
}

istream& operator>> (istream& in, Track& track) {// Preconditie:
	assert(in);
	/*  Postconditie:
		De inhoud van de eerstvolgende 8 regels uit in zijn gelezen en omgezet naar de corresponderende members in track.
		De daaropvolgende (lege) regel uit in is ook gelezen.
	*/
	getline(in, track.artist);
	if(in) {
		getline(in, track.cd);
		in >> track.year;
		in.ignore(1000, '\n');
		in >> track.track;
		in.ignore(1000, '\n');
		getline(in, track.title);
		getline(in, track.tags);
		in >> track.time;
		getline(in, track.country);
		in.ignore(1000, '\n');
	}

	return in;
}

const int MAX_NR_OF_TRACKS = 5000;
typedef Track MusicDB[MAX_NR_OF_TRACKS];

void read_database(ifstream& file, MusicDB& database) {
	assert(file);
	/*	Postconditie:
		Elke 9 regels uit file worden omgezet naar een nummer in database. De overige elementen in database worden leeg gemaakt.
	*/
	int i;
	for(i = 0; file; i++) {
		Track track;
		file >> track;
		database[i] = track;
	}
	cout << "Read " << --i << " entries." << endl;
	for(; i < MAX_NR_OF_TRACKS; i++) {
		database[i] = Track();
	}
}

int main() {// Preconditie:
	assert(true);
	/*  Postconditie:
		De muziekdatabase "Nummers.txt" is (indien aanwezig en correct geformatteerd) ingelezen.
		De gebruiker is in staat geweest database queries te stellen en heeft de antwoorden op deze
		queries gezien.
	*/
	ifstream file;
	file.open("Nummers.txt");
	MusicDB database;
	read_database(file, database);
	file.clear();
	file.close();

	string command = "";
	while(command != "stop") {
		cout << ">>> ";
		cin >> command;
		string arg;
		int matchcount = 0;
		if(command == "track" || command == "tag" || command == "artist" || command == "artist?" || command == "cds" || command == "cd?" || command == "tracks") {
			cin.ignore(1, ' ');
			getline(cin, arg);
			string last_hit = "";
			for(int i = 0; i < MAX_NR_OF_TRACKS; i++) {
				if(command == "track" || command == "tag") {
					if(match(arg, command == "track" ? database[i].title : database[i].tags)) {
						show_track(database[i], {true, true, true, true, true, true, true, command == "track"});
						matchcount++;
					}
				} else if(command == "artist" || command == "artist?") {
					if(database[i].artist != last_hit && match(arg, command == "artist" ? database[i].artist : database[i].cd)) {
						show_track(database[i], {true, command == "artist?"});
						matchcount++;
						last_hit = database[i].artist;
					}
				} else if(command == "cds" || command == "cd?") {
					if(database[i].cd != last_hit && match(arg, command == "cds" ? database[i].artist : database[i].title)) {
						show_track(database[i], {true, true, true});
						matchcount++;
						last_hit = database[i].cd;
					}
				} else {
					if(database[i].cd != last_hit && match(arg, database[i].cd)) {
						show_track(database[i], {true, true});
						matchcount++;
						last_hit = database[i].cd;

						for(int j = i; j < MAX_NR_OF_TRACKS; j++) {
							if(database[j].cd != last_hit) {
								j = MAX_NR_OF_TRACKS;
							} else  if(database[j].track < 10) {
								cout << "->";
								show_track(database[j], {false, false, false, true, true, true, true, true});
							}
						}
						for(int j = i; j < MAX_NR_OF_TRACKS; j++) {
							if(database[j].cd != last_hit) {
								j = MAX_NR_OF_TRACKS;
							} else if(database[j].track >= 10) {
								cout << "->";
								show_track(database[j], {false, false, false, true, true, true, true, true});
							}
						}
					}
				}
			}
			cout << "Found " << matchcount << " matches." << endl;
		} else if(command == "#cds") {
			string last_hit = "";
			for(int i = 0; i < MAX_NR_OF_TRACKS; i++) {
				if(database[i].cd != last_hit) {
					matchcount++;
					last_hit = database[i].cd;
				}
			}
			cout << "Found " << matchcount << " CDs." << endl;
		} else if(command == "time") {
			Length total = {0,0};

			for(int i = 0; i < MAX_NR_OF_TRACKS; i++) {
				total = total + database[i].time;
			}
			cout << "Total time: " << total << endl;
		}
	}
	return 0;
}