// Pilot class header file
#include <iostream>
#include <string>
#include "plane_class.h"
#pragma once										// ensures the header file is only included once during compilation
using namespace std;								// use this so I do not have to type out 'std::' every time

class Pilot {

private:
	string name;
	unique_ptr<Plane> myPlane;

public:
	//Pilot(const string& name) : name(name), myPlane(make_unique<Plane>())										// pilot contstructor
	Pilot(const string& name, const string& from, const string& to) : name(name), myPlane(make_unique<Plane>(from, to))
	{
		cout << "The pilot's name is " << name << ". The memory address is: " << this;
		cout << ". The pilot is at the gate and ready to board the plane." << endl;
	}

	~Pilot()										// pilot destructor
	{
		cout << "The pilot's name is " << name << ". The pilot is out of the plane." << endl;
	}

	string getName() const								// get function
	{
		return name;
	}


	//std::unique_ptr<Plane> myPlane = std::make_unique<Plane>();						// pointer named myPlane to an object of plane class
};

