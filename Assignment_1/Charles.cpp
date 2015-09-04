#include "Robot.h"
/*
Karel is a framework for manipulating with Karel the robot.
Karel is a subclass of ROBOT from the library Robot.
Last Modified:	September 16 2006, by Pieter Koopman, RU Nijmegen
With some additions: September 12 2007, by Ger Paulussen & Peter Achten
More additions: August 21 2013, by Peter Achten
*/


// =========================================================================

// Here are the examples that have been explained during the lecture
void take_3_steps()
{
	step();
	step();
	step();
}

void swap_ball()
{
	if (on_ball())
		get_ball();
	else
		put_ball();
	step();
}

// put_a_ball_somewhere adds a single ball to Charles' world on a random location
void put_a_ball_somewhere()
{
	int lane = 1 + rand() % (WereldHoogte - 2);
	int street = 1 + rand() % (WereldBreedte - 2);
	create_ball(street, lane);
}

// make_church creates a Church-like shape of walls
void make_church()
{
	place_rectangle(10, 10, 20, 8);
	place_rectangle(10, 18, 4, 4);
	place_walls(12, 22, 4, false);
	place_walls(11, 25, 2, true);
}

// make_block creates an arbitrary block inside Charles' world and places a ball
// on the 'north' most lane at the 'west' most street corner.
void make_block()
{
	const int left = rand() % (WereldBreedte / 3) + 5;
	const int bottom = rand() % (WereldHoogte / 4) + 5;
	const int width = rand() % (WereldBreedte / 2) + 5;
	const int height = rand() % (WereldHoogte / 2) + 2;
	place_rectangle(left, bottom, width, height);
	create_ball(left, WereldHoogte - 2);
}
// turn_north makes Charles look north
void turn_north()
{
	while (!north())
		turn_left();
}

void turn_around()
{
	turn_left();
	turn_left();
}
// walk_to_wall makes Charles walk ahead and stop immediately before the wall
void walk_to_wall()
{
	while (!in_front_of_wall())
		step();
}

// go_to_north_west_corner makes Charles move to north-west corner and look to the east
// it is assumed that that there are only the exterior walls
void go_to_north_west_corner()
{
	turn_north();
	walk_to_wall();
	turn_left();
	walk_to_wall();
	turn_around();
}

// sweep_lane makes Charles walk ahead until it is on top of a ball or immediately before a wall
void sweep_lane()
{
	while (!on_ball() && !in_front_of_wall())
		step();
}

// go_down_east_if_not_on_ball moves Charles one lane to the south if he is not on a ball.
// it is assumed that Charles is facing east and is not on the southernmost lane
void go_down_east_if_not_on_ball()
{
	if (!on_ball())
	{
		turn_right();
		step();
		turn_right();
	}
}

// go_down_west_if_not_on_ball moves Charles one lane to the south if he is not on a ball.
// it is assumed that Charles is facing west and is not on the southernmost lane
void go_down_west_if_not_on_ball()
{
	if (!on_ball())
	{
		turn_left();
		step();
		turn_left();
	}
}

// sweep_lanes makes Charles move to the east and find the ball, followed by
// going on lane south and moving to the west to find the ball.
// Assumptions: Charles is standing at the north-west corner and is looking east, there are only the exterior walls, and a ball is present.
// Result:      Charles is standing on the ball
void sweep_lanes()
{
	while (!on_ball())
	{
		sweep_lane();
		go_down_east_if_not_on_ball();
		sweep_lane();
		go_down_west_if_not_on_ball();
	}
}

// This example has been discussed during the lecture
// The effect of this function is that Charles will search for a ball in its universe.
// Assumptions: Charles is standing on its base position, there are only the exterior walls, and a ball is present.
// Result:      Charles is standing on the ball.
void find_ball()
{
	sweep_lanes();
}

// here starts the part with code to be completed by the students

// Name / student number / study student 1 :
// Name / student number / study student 2 :

// give one or more comment lines about what will happen in this function
void clean_string_with_balls()
{
	make_string_with_balls();
	int i = 0;
	while (i < 4) { //because for loops are *for*bidden /terrible
					//	for (int i = 0; i < 4; i++) {// 4 walls to clear
		while (!in_front_of_wall()) {
			step();
			get_ball();
		};
		turn_right();
		i++;
	}
}


void clear_line()
{
	while (on_ball()) {
		get_ball();
		step();
	}
	turn_around();
	walk_to_wall();
}

void get_balls_until_wall()
{
	while (!in_front_of_wall())
	{
		step();
		if (on_ball())
			get_ball();

	}
}
// give one or more comment lines about what will happen in this function
void clean_chaos_with_balls()
{
	make_chaos_with_balls();
	//	walk_to_wall();
	//	turn_right();
	//	while (on_ball()) {
	//		turn_right();
	//		clear_line();
	//		turn_right();
	//		step();
	//	}
	while (true)
	{
		get_balls_until_wall();
		turn_right();
		step();
		if (!on_ball()) {
			break;
		}
		turn_right();
		while (on_ball()) {
			get_ball();
			step();
		}
		turn_left();
		step();
		if (on_ball())
		{
			turn_right();
			while (on_ball()) {
				step();
			}
			turn_around();
		}
		else {
			turn_left();
		}
	}
	go_to_north_west_corner();

}

// this is the initial set-up for the tracing Charles assignment
void tracing_Charles()
{
	reset();
	create_ball(WereldBreedte - 5, WereldHoogte - 3);
	steps(WereldBreedte - 5);
}

// give one or more comment lines about what will happen in this function
void around_the_block()
{
	make_block();
	while (!on_ball()) {
		step();
	}
	turn_right();
	walk_to_wall();
	for (int i = 0; i < 4; i++) {
		while (in_front_of_wall()) {
			turn_left();
			step();
			turn_right();
		}
		step();
		turn_right();
	}
	go_to_north_west_corner();
}

// Charles searches for the ball and remains there
void search_the_ball()
{
	put_a_ball_somewhere();
	find_ball();
}

// For testing purposes, you can define your own function here:
void test()
{
	// enter your Charles code here

}

// end of part with code to be completed by students
// =========================================================================

void instant() { rest(0); };
void quick() { rest(1); };
void normal() { rest(dInit); };
void slow() { rest(250); };
void very_slow() { rest(1000); };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	Menu charles_menu((char*)"Charles");
	charles_menu.add((char*)"Clean", reset)
		.add((char*)"Stop", stop);

	Menu l1_menu((char*)"Examples Lecture 1");
	l1_menu.add((char*)"Steps", take_3_steps)
		.add((char*)"Swap ball", swap_ball)
		.add((char*)"Find ball", search_the_ball);

	Menu a1_menu((char*)"Assignment 1");
	a1_menu.add((char*)"Balls: a string...", clean_string_with_balls)
		.add((char*)"Balls: chaos...", clean_chaos_with_balls)
		.add((char*)"Balls: tracing Charles...", tracing_Charles)
		.add((char*)"Bonus: around the block...", around_the_block)
		.add((char*)"Test a function", test);

	Menu sn_menu((char*)"Velocity");
	sn_menu.add((char*)"Instant", instant)
		.add((char*)"Quick", quick)
		.add((char*)"Normal", normal)
		.add((char*)"Slow", slow)
		.add((char*)"Very slow", very_slow);

	try
	{
		karelsWereld().Run(charles_menu, WINARGS(hInstance, hPrevInstance, szCmdLine, iCmdShow));
	}
	catch (IllegaleActie dezeIllegaleActie)
	{
		dezeIllegaleActie.report();
	}
	catch (...)
	{
		makeAlert("Something went terribly wrong!");
	}

	return 0;
}
