// plane class header file
#include <iostream>
#include <string>
#include <map>
#pragma once										// ensures the header file is only included once during compilation
using namespace std;								// use this so I do not have to type out 'std::' every time

class plane {										// creating a class named plane

private:											// not needed because a class is normally private										// private members can only be accessed within the class
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	string origin;
	string destination;

	// container from question 2
	std::map<std::string, std::map<std::string, double>> flight_length;


public:												// public members can be accessed from outside the class
	plane(const string& from, const string& to) : origin(from), destination(to), pos(0.0), vel(0.0), at_SCE(0)		// constructor function
	{
		flight_length["SCE"]["PHL"] = 160;			// State College to Philadelphia
		flight_length["SCE"]["ORD"] = 640;			// State College to Chicago
		flight_length["SCE"]["EWR"] = 220;			// State College to Newark

		distance = flight_length[from][to];			// sets the value of distance variable to the distance between the airports

		cout << "Plane Created at " << this << endl;			// printing out the memory address where the plane object is stored
	}

	~plane()										// destructor function that prints out "Plane Destroyed"
	{
		cout << "Plane Destroyed" << endl;
	}

	void operate(double dt)							// void function because it is not meant to return anything
	{
		if (pos < distance)
		{
			pos += vel * dt;
			at_SCE = 0;
		}
		else
		{
			destination == "SCE"
		}
	}

	// Get functions
	double getPos() const
	{
		return pos;
	}

	double getVel() const
	{
		return vel;
	}

	string getOrigin() const
	{
		return origin;
	}

	string getDestination() const
	{
		return destination;
	}

	bool getAt_SCE() const
	{
		return at_SCE;
	}

	// Set function
	void setVel(double vel)
	{
		// DO I NEED ANYTHING HERE?
	}
};