// plane class header file
#include <string>
#include <map>
#pragma once			// ensures the header file is only included once during compilation
using namespace std;	// us this so I do not have to type out 'std::' every time

class plane {			// creating a class named plane
public:					// public members can be accessed from outside the class

private:				// private members can only be accessed within the class
	double pos;			
	double vel;
	double distance;
	bool at_SCE;
	string origin;
	string destination;
	/*
	std::map<std::string, std::map<std::string, double>> flight_length;
	flight_length["SCE"]["PHL"] = 160;			// container from question 2
	*/

};