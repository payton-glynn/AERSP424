#include <iostream>
#include <string>
#include <map>
#include "plane_class.h"						// allow access to the plane class in this .cpp file

int main()
{
	plane obj("SCE","ORD");						// instantiate plane class
	obj.setVel(410);							// flight speed (miles per hour)
	double dt = 44;								// time step (seconds)
	dt = dt / 3600;								// convert time step to hours

	return 0;
}