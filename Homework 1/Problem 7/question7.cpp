#include <iostream>
#include <string>
#include <map>
#include "pilot_class.h"
#include "plane_class.h"
using namespace std;

// USE SWAP COMMAND TO CHANGE WHO IS THE MAIN PILOT

int main()
{
	Pilot *pilot_in_command = new Pilot("Alpha");		// input the  pilot in command
	Pilot *copilot = new Pilot("Bravo");				// input the copilot

	

	plane obj("SCE", "ORD");					// instantiate plane class to go from state college to chicago
	obj.setVel(410);							// flight speed (miles per hour)
	double dt = 15;								// time step (seconds)
	dt = dt / 3600;								// convert time step to hours
	int max_iter = 1500;						// maximum number of iterations
	
	pilot_in_command->myPlane = &obj;			// assigns plane to the pilot in command

	for (int iter = 0; iter <= max_iter; ++iter)
	{
		obj.operate(dt);

		if ( obj.getAt_SCE())					// checks to see if the plane is at SCE airport
		{
			cout << "The plane " << (*pilot_in_command).myPlane << " is at SCE" << endl;
			cout << "Pilot " << (*pilot_in_command).getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
		}
	}

	return 0;
}









/*
int main()
{
	plane obj("SCE","ORD");						// instantiate plane class to go from state college to chicago
	obj.setVel(410);							// flight speed (miles per hour)
	double dt = 15;								// time step (seconds)
	dt = dt / 3600;								// convert time step to hours
	int max_iter = 1500;						// maximum number of iterations

	for (int iter = 0; iter <= max_iter; ++iter)
	{
		obj.operate(dt);
			std::cout << "Time: " << dt*3600*iter << ", " << "Position: " << obj.getPos() << " miles." << std::endl;
	}

	return 0;
}
*/