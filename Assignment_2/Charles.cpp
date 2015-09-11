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

// Name / student number / study student 1 :
// Name / student number / study student 2 :

void turn_around()
{
	turn_right();
	turn_right();
}

// turn_north makes Charles look north
void turn_north()
{
	while (!north())
		turn_left();
}

void walk_to_wall()
{
	while (!in_front_of_wall())
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


bool check_path ()
{
	bool returnvalue;
	if (!in_front_of_wall())
	{
		
		step();
		if (on_ball())
		{
			returnvalue = true;
		} else {
			returnvalue = false;
			turn_around();
			step();
		}
	} else
	{
		turn_around();
		returnvalue = false;
	}
	return returnvalue;
}

// give one or more comment lines about what will happen in this function
void follow_path ()
{
	while (1)
	{
		while (on_ball() && !in_front_of_wall())
			step();
		if (!on_ball())
		{
			turn_around();
			step();
			
		}
		turn_left();
		if (!check_path())
		{
			if (!check_path())
			{
				break;
				//We are at the end of the line here.
			}
		}
		
	}

	
}

// give one or more comment lines about what will happen in this function
void hansl_and_gretl ()
{
	make_path_with_balls() ;
	follow_path () ;
}

// give one or more comment lines about what will happen in this function
// note that you are allowed to add formal parameters to fill_cave_with_balls if that is necessary for your solution
void fill_cave_with_balls ()
{
    // give your own code completion
	step();
	while (!in_front_of_wall())
	{
		turn_right();
		while (!in_front_of_wall())
		{
			put_ball();
			step();
		}
		put_ball();
		turn_around();
		walk_to_wall();
		turn_right();
		step();
	}
	turn_right();
	walk_to_wall();
	turn_right();
}

// give one or more comment lines about what will happen in this function
void cave ()
{
	// if necessary for your solution, you are allowed to give actual parameters to fill_cave_with_balls
	fill_cave_with_balls () ;
	fill_cave_with_balls () ;
}

// give one or more comment lines about what will happen in this function
void start_cave ()
{
    make_cave () ;
    cave () ;
}

// give one or more comment lines about what will happen in this function
void rondje_om_de_kerk ()
{
	make_church();
	while (!on_ball()) {
		step();
	}
	turn_right();
	walk_to_wall();
	// A count resulted in 20 corners on the church 
	for (char i = 0; i < 20; i++) {
		while (in_front_of_wall()) {
			turn_left();
			if (in_front_of_wall())
			{
				i++;
			} else
			{
				step();
				turn_right();
			}

		}
		step();
		turn_right();
	}
	go_to_north_west_corner();
}

// For testing purposes, you can define your own function here:
void test ()
{
    // enter your Charles code here
}

// end of part with code to be completed by students
// =========================================================================


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
	sn_menu.add ((char*)"Quick", quick)
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
