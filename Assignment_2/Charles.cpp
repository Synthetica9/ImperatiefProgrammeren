#include "Robot.h"
/*
	Karel is a framework for manipulating with Karel the robot.
	Karel is a subclass of ROBOT from the library Robot.
	Last Modified:	September 16 2006, by Pieter Koopman, RU Nijmegen
	With some additions: September 12 2007, by Ger Paulussen & Peter Achten
	More additions: August 21 2013, by Peter Achten
*/


// =========================================================================

// make_church creates a Church-like shape of walls
void make_church ()
{
    const int lane   = 2 + rand () % (WereldHoogte / 5) ;
    const int street = 2 + rand () % (WereldBreedte / 5) ;
    const int width  = 3 + rand () % (WereldBreedte / 2) ;
    const int height = 2 + rand () % (WereldHoogte / 3) ;
    place_rectangle (street,lane,width,height) ;
    place_rectangle (street + 2,lane + height, 2 + width / 3, 2 + height / 3) ;
    place_walls (street + 3 + width / 6,lane + height + height / 3 + 3,4,false) ;
    place_walls (street + 2 + width / 6,lane + height + height / 3 + 5,2,true) ;
    create_ball (street, WereldHoogte - 2) ;
}


// here starts the part with code to be completed by the students

// Name / student number / study student 1 : Patrick Hilhorst / S4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / S4576586 / Mathematics

void turn_around()
{
	turn_right();
	turn_right();
}

// turn_north makes Charles look north
void turn_north()
{
	while(!north())
		turn_left();
}

void walk_to_wall()
{
	while(!in_front_of_wall())
		step();
}

void go_to_north_west_corner()
{
	turn_north();
	walk_to_wall();
	turn_left();
	walk_to_wall();
	turn_around();
}

bool check_path() // Checks whether the path leads the way Charles is facing. If not, Charles will turn around.
{
	bool return_value;
	if(!in_front_of_wall()) // The path cannot lead to a wall
	{
		step(); // Move one step ahead
		if(on_ball()) // and check whether the path continues
		{
			return_value = true;
		}
		else // otherwise, turn around and return to the path corner
		{
			return_value = false;
			turn_around();
			step();
		}
	}
	else
	{
		turn_around();
		return_value = false;
	}
	return return_value;
}

void follow_path()
{
	while(true)
	{
		while(on_ball() && !in_front_of_wall()) // Walk along the line of balls
		{
			step();
		}
		if(!on_ball()) // Move one back, which places Charles on a corner, facing backwards
		{
			turn_around();
			step();
		}
		turn_left();
		if(!check_path()) // Check whether the path continues to the right, if not:
		{
			if(!check_path()) // Check whether the path continues to the left, if not:
			{
				break;
				// We are at the end of the line
			}
		}
	}
}

void hansl_and_gretl()
{
	reset();
	make_path_with_balls();
	follow_path();
}

void fill_cave_with_balls()
{
	step();
	while(!in_front_of_wall()) // While not in front of the right (or left) boundary
	{
		turn_right();
		while(!in_front_of_wall()) // Put balls until the cave wall is met
		{
			put_ball();
			step();
		}
		put_ball();
		turn_around(); // Return to the top (or bottom)
		walk_to_wall();
		turn_right();
		step(); // Move to the next column
	}
	turn_right(); // Move to the bottom (or top)
	walk_to_wall();
	turn_right();
}

void cave()
{
	fill_cave_with_balls(); // Fill the top and move to the bottom
	fill_cave_with_balls(); // Fill the bottom and return
}

void start_cave()
{
	reset();
	make_cave();
	cave();
}

void rondje_om_de_kerk()
{
	reset();
	make_church();
	while(!on_ball()) // Walk to the ball marking the starting position of the church
	{
		step();
	}
	turn_right();
	walk_to_wall();

	put_ball(); // Mark the start of the church perimeter

	turn_left();
	step(); // Move one step ahead to avoid starting on top of the ball
	turn_right();

	while(!on_ball()) // Perimeter-walking algorithm loops until the starting ball is found
	{
		while(in_front_of_wall())
		{
			turn_left();
			if(!in_front_of_wall())
			{
				step();
				turn_right();
			}
		}
		step();
		turn_right();
	}

	get_ball(); // Pick up the ball and return
	go_to_north_west_corner();
}

// For testing purposes, you can define your own function here:
void test()
{
	for (int i = 0; i <= (WereldBreedte / 2); i++)
		step();
	turn_right();
	for (int i = 0; i <= (WereldHoogte / 2); i++)
		step();
	while(!in_front_of_wall())
	{
		step();
		if (on_ball())
		{
			get_ball();
			turn_left();
		}
		else
		{
			put_ball();
			turn_right();
		}
	}

}

// end of part with code to be completed by students
// =========================================================================


void instant() { rest(0); };
void quick  () { rest(    1); };
void normal () { rest(dInit); };
void slow   () { rest(  250); };
void very_slow  () { rest( 1000); };

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    Menu charles_menu ((char*)"Charles") ;
    charles_menu.add ((char*)"Clean", reset)
                .add ((char*)"Stop",  stop) ;

	Menu a1_menu ((char*)"Assignment 2");
	a1_menu.add ((char*)"Hansl and Gretl", hansl_and_gretl )
		   .add ((char*)"Cave", start_cave )
		   .add ((char*)"Bonus: rondje om de kerk...", rondje_om_de_kerk )
	       .add ((char*)"Test a function",test);

	Menu sn_menu ((char*)"Velocity");
	sn_menu.add((char*)"Instant", instant)
		   .add ((char*)"Quick", quick)
		   .add ((char*)"Normal",normal)
		   .add ((char*)"Slow",slow)
		   .add ((char*)"Very slow",very_slow);

	try
	{
		karelsWereld().Run (charles_menu,WINARGS(hInstance, hPrevInstance, szCmdLine, iCmdShow));
	}
	catch (IllegaleActie dezeIllegaleActie )
	{
		dezeIllegaleActie.report ();
	}
	catch (...)
	{
		makeAlert ("Something went terribly wrong!");
	}

	return 0;
}
