#include <iostream>
#include <string>
#include <map>
#include "plane_class.h"						// allow access to the Plane class in this .cpp file

int main()
{
	Plane plane("SCE","ORD");					// instantiate plane class to go from state college to chicago
	plane.setVel(425);							// flight speed (miles per hour)
	double dt = 50;								// time step (seconds)
	dt = dt / 3600;								// convert time step to hours
	int max_iter = 1200;						// maximum number of iterations
	
	for (int iter = 0; iter <= max_iter; ++iter)
	{
		if (iter == 0)
		{
			plane.operate(dt * 0);
			std::cout << "Time: " << dt * 0 * iter << ", " << "Position: " << plane.getPos() << " miles." << std::endl;
		}
		else {

			plane.operate(dt);
			std::cout << "Time: " << dt * 3600 * iter << ", " << "Position: " << plane.getPos() << " miles." << std::endl;
		}
	}

	return 0;
}