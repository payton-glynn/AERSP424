// plane class header file
#include <iostream>
#include <string>
#include <map>
#pragma once										// ensures the header file is only included once during compilation
using namespace std;								// us this so I do not have to type out 'std::' every time

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
	plane(const string& from, const string& to)		// constructor function
	{
			// DOES THE CONSTRUCTOR NEED ANYTHING HERE?
		flight_length["SCE"]["PHL"] = 160;
	}

	~plane()										// destructor function
	{				
	}

	void operate(double dt)							// void function because it is not meant to return anything
	{
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