#include "Robot.h"
#include <algorithm>
#include <string>

using namespace std;
/*
	Karel is a framework for manipulating with Karel the robot.
	Karel is a subclass of ROBOT from the library Robot.
	Last Modified:	September 16 2006, by Pieter Koopman, RU Nijmegen
	With some additions: September 12 2007, by Ger Paulussen & Peter Achten
	More additions: August 21 2013, by Peter Achten
*/


// =========================================================================



// here starts the part with code to be completed by the students

// Name / student number / study student 1 : Patrick Hilhorst / S4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / S4576586 / Mathematics

void turn_around() {
	turn_right();
	turn_right();
}

// turn_north makes Charles look north
void turn_north() {
	while(!north())
		turn_left();
}

void walk_to_wall() {
	while(!in_front_of_wall())
		step();
}

void go_to_north_west_corner() {
	turn_north();
	walk_to_wall();
	turn_left();
	walk_to_wall();
	turn_around();
}

void hansl_and_gretl() {
}

void start_cave() {
}

void rondje_om_de_kerk() {}

void go_to_middle_of_world() {
	go_to_north_west_corner();
	for(int i = 0; i <= (WereldBreedte / 2); i++)
		step();
	turn_right();
	for(int i = 0; i <= (WereldHoogte / 2); i++)
		step();

}

string input_string = "..............................................................................................................................................................*.............................................................*.*...................................................**......**............**.......................................*...*....**............**............................**........*.....*...**..........................................**........*...*.**....*.*.................................................*.....*.......*..................................................*...*............................................................**...........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................";

const int width = WereldBreedte - 2;
const int height = WereldHoogte - 2;
typedef bool World[width][height];

bool live_conditions[] = {
	false, // 0
	false, // 1
	true,  // 2
	true,  // 3
	false, // 4
	false, // 5
	false, // 6
	false  // 7
};

bool spawn_conditions[] = {
	false, // 0
	false, // 1
	false, // 2
	true,  // 3
	false, // 4
	false, // 5
	false, // 6
	false  // 7
};

void clear_world(World world) {
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			world[x][y] = false;
		}
	}
}

void draw_array(World world) {
	go_to_north_west_corner();
	turn_north();
	turn_right();
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			bool worldball = world[x][y];
			bool charlesball = on_ball();
			if(worldball && !charlesball) {
				put_ball();
			}
			if(!worldball && charlesball) {
				get_ball();
			}
			if(x < width - 1)
				step();
		}
		turn_right();
		step();
		turn_right();
		y++;
		for(int x = width - 1; x >= 0; x--) {
			bool worldball = world[x][y];
			bool charlesball = on_ball();
			if(worldball && !charlesball) {
				put_ball();
			}
			if(!worldball && charlesball) {
				get_ball();
			}
			if(x > 0)
				step();
		}
		if(y < height - 1) {
			turn_left();
			step();
			turn_left();
		}
	}
}

void iterate(World world, World new_world) {
	clear_world(new_world);
	for(int y = 1; y < height - 1; y++) {
		for(int x = 1; x < width - 1; x++) {
			int neighbours = 0;
			for(int dy = -1; dy <= 1; dy++) {
				for(int dx = -1; dx <= 1; dx++) {
					if(dx != 0 || dy != 0) {
						neighbours += world[x + dx][y + dy];
					}
				}
			}

			if((spawn_conditions[neighbours]) ||
			   (live_conditions[neighbours] && world[x][y])) {
				new_world[x][y] = true;
			}
		}
	}
}

// For testing purposes, you can define your own function here:
void test() {
	rust(0);
	World world, new_world;
	clear_world(world);
	clear_world(new_world);
	for(int y = 1; y < height - 1; y++) {
		for(int x = 1; x < width - 1; x++) {
			world[x][y] = input_string[y * width + x] == '*';
		}
	}
	while(true) {
		draw_array(world);
		iterate(world, new_world);
		swap(world, new_world);
	}
}

// end of part with code to be completed by students
// =========================================================================


void instant() {
	rest(0);
};

void quick() {
	rest(1);
};

void normal() {
	rest(dInit);
};

void slow() {
	rest(250);
};

void very_slow() {
	rest(1000);
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	Menu charles_menu((char*)"Charles");
	charles_menu.add((char*)"Clean", reset)
		.add((char*)"Stop", stop);

	Menu a1_menu((char*)"Assignment 2");
	a1_menu.add((char*)"Hansl and Gretl", hansl_and_gretl)
		.add((char*)"Cave", start_cave)
		.add((char*)"Bonus: rondje om de kerk...", rondje_om_de_kerk)
		.add((char*)"Test a function", test);

	Menu sn_menu((char*)"Velocity");
	sn_menu.add((char*)"Instant", instant)
		.add((char*)"Quick", quick)
		.add((char*)"Normal", normal)
		.add((char*)"Slow", slow)
		.add((char*)"Very slow", very_slow);

	try {
		karelsWereld().Run(charles_menu, WINARGS(hInstance, hPrevInstance, szCmdLine, iCmdShow));
	} catch(IllegaleActie dezeIllegaleActie) {
		dezeIllegaleActie.report();
	} catch(...) {
		makeAlert("Something went terribly wrong!");
	}

	return 0;
}
