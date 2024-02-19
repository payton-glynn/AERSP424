// Plane class header file
#include <iostream>
#include <string>
#include <map>
#pragma once										// ensures the header file is only included once during compilation
using namespace std;								// use this so I do not have to type out 'std::' every time

class Plane {										// creating a class named Plane

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
	Plane(const string& from, const string& to)		// constructor function
	{
		flight_length["SCE"]["PHL"] = 160;
	}

	~Plane()										// destructor function
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
	}
};