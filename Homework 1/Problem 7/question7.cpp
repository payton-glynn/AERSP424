/*
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "pilot_class.h"
#include "plane_class.h"
using namespace std;

// USE SWAP COMMAND TO CHANGE WHO IS THE MAIN PILOT

int main()
{
	int* zero_ptr = nullptr;					// allows a memory address of all zeros

	Pilot *pilot_in_command = new Pilot("Alpha");		// input the  pilot in command
	Pilot *copilot = new Pilot("Bravo");				// input the copilot


	Plane plane("SCE", "ORD");					// instantiate plane class to go from state college to chicago
	plane.setVel(425);							// flight speed (miles per hour)
	double dt = 50;								// time step (seconds)
	dt = dt / 3600;								// convert time step to hours
	int max_iter = 1200;						// maximum number of iterations
	
	pilot_in_command->myPlane = &plane;			// assigns plane to the pilot in command

	for (int iter = 0; iter <= max_iter; ++iter)
	{
		plane.operate(dt);

		if (iter == 0)							// the plane initially starts at SCE, so print out these statements
		{
			cout << "The plane " << (*pilot_in_command).myPlane << " is at SCE" << endl;
			cout << "Pilot " << (*pilot_in_command).getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << (*copilot).getName() << " with certificate number " << copilot << " is in control of a plane: " << zero_ptr << endl;
			cout << endl;
		}

		
		if ( plane.getAt_SCE())					// checks to see if the plane is at SCE airport
		{
			cout << "The plane " << (*pilot_in_command).myPlane << " is at SCE" << endl;
			swap(pilot_in_command->myPlane, zero_ptr);
			cout << "Pilot " << (*pilot_in_command).getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << endl;
		} 
	}

	return 0;
}



#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "pilot_class.h"
#include "plane_class.h"

using namespace std;

int main() {
	Pilot* pilot_in_command = new Pilot("Alpha");
	Pilot* copilot = new Pilot("Bravo");

	Plane plane("SCE", "ORD");
	plane.setVel(425);
	double dt = 50 / 3600.0;
	int max_iter = 1200;

	pilot_in_command->myPlane = &plane;

	for (int iter = 0; iter <= max_iter; ++iter) {
		plane.operate(dt);

		if (iter == 0) {
			cout << "The plane " << pilot_in_command->myPlane << " is at SCE" << endl;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << "nullptr" << endl;
			cout << endl;
		}

		if (plane.getAt_SCE()) {
			cout << "The plane " << pilot_in_command->myPlane << " is at SCE" << endl;
			pilot_in_command->myPlane = nullptr;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << endl;
		}
	}

	delete pilot_in_command;
	delete copilot;

	return 0;
}
*/


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "pilot_class.h"
#include "plane_class.h"

using namespace std;

int main() {
	Pilot* pilot_in_command = new Pilot("Alpha");
	Pilot* copilot = new Pilot("Bravo");

	Plane plane("SCE", "ORD");
	plane.setVel(425);
	double dt = 50 / 3600.0;
	int max_iter = 1200;

	pilot_in_command->myPlane = &plane;

	for (int iter = 0; iter <= max_iter; ++iter) {
		plane.operate(dt);

		if (iter == 0) {
			cout << "The plane " << pilot_in_command->myPlane << " is at SCE" << endl;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << copilot->myPlane << endl;
			cout << endl;
		}

		if (plane.getAt_SCE()) {
			cout << "The plane " << &plane << " is at SCE" << endl;
			swap(pilot_in_command->myPlane, copilot->myPlane);
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << copilot->myPlane << endl;
			cout << endl;
		}
	}

	delete pilot_in_command;
	delete copilot;

	return 0;
}
