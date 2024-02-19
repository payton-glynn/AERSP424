#include <iostream>
#include <string>
#include <map>
#include "pilot_class.h"
#include "plane_class.h"
using namespace std;



int main()
{
	plane obj("SCE", "ORD");					// instantiate plane class to go from state college to chicago
	obj.setVel(410);							// flight speed (miles per hour)
	double dt = 15;								// time step (seconds)
	dt = dt / 3600;								// convert time step to hours
	int max_iter = 1500;						// maximum number of iterations

	Pilot pilot;
	pilot.getName();
	cout << pilot.myPlane << endl;

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