// Plane class header file
#include <iostream>
#include <string>
#include <map>
#pragma once										// ensures the header file is only included once during compilation
using namespace std;								// use this so I do not have to type out 'std::' every time

class Plane {										// creating a class named plane

private:											// not needed because a class is normally private										
													// private members can only be accessed within the class
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	string origin;
	string destination;

	// container from question 2
	std::map<std::string, std::map<std::string, double>> flight_length;


public:												// public members can be accessed from outside the class
	Plane(const string& from, const string& to) : origin(from), destination(to), pos(0.0), vel(0.0), at_SCE(0)		// constructor function
	{
		flight_length["SCE"]["PHL"] = 160;			// State College to Philadelphia
		flight_length["SCE"]["ORD"] = 640;			// State College to Chicago
		flight_length["SCE"]["EWR"] = 220;			// State College to Newark

		distance = flight_length[from][to];			// sets the value of distance variable to the distance between the airports

		cout << "Plane Created at " << this << endl;			// printing out the memory address where the plane object is stored
	}

	~Plane()										// destructor function that prints out "Plane Destroyed"
	{
		cout << "Plane Destroyed" << endl;
	}

	void operate(double dt)							// void function because it is not meant to return anything
	{												// run through the logic provided by the flowchart
		if (pos < distance)
		{											
			pos += vel * dt;
			at_SCE = 0;
		}
		else
		{
			if (destination == "SCE")
			{
				at_SCE = 1;
				// swap value of origin and destination
				string temp1 = origin;
				origin = destination;
				destination = temp1;
				pos = 0.0;

			}
			else
			{
				// swap value of origin and destination
				string temp2 = origin;
				origin = destination;
				destination = temp2;
				pos = 0.0;

			}
		}
	}

	// Get functions
	double getPos() 
	{
		return pos;
	}

	double getVel() 
	{
		return vel;
	}

	string getOrigin() 
	{
		return origin;
	}

	string getDestination() 
	{
		return destination;
	}

	bool getAt_SCE() 
	{
		return at_SCE;
	}

	// Set function
	void setVel(double new_vel)
	{
		vel = new_vel;					// allows velocity to get updated every iteration
	}
};