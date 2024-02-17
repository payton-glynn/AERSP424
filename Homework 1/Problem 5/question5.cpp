#include <iostream>
#include <string>
#include <map>
#include "plane_class.h"						// allow access to the plane class in this .cpp file

int main()
{
	plane obj("SCE","ORD");						// instantiate plane class to go from state college to chicago
	obj.setVel(410);							// flight speed (miles per hour)
	double dt = 15;								// time step (seconds)
	dt = dt / 3600;								// convert time step to hours
	int max_iter = 1500;						// maximum number of iterations

	for (int iter = 1; iter <= max_iter; ++iter)
	{
		obj.operate(dt);
			std::cout << "Time: " << dt*3600*iter << ", " << "Position: " << obj.getPos() << " miles." << std::endl;
	}

	return 0;
}