// pilot class header file
#include <iostream>
#include <string>
#pragma once										// ensures the header file is only included once during compilation
using namespace std;								// use this so I do not have to type out 'std::' every time

class Pilot {

private:
	string name;

public:
	Pilot()											// pilot contstructor
	{
		cout << "The pilot's name is " << name << ". The memory address is: " << this;
		cout << ". The pilot is at the gate and ready to board the plane." << endl;
	}

	~Pilot()										// pilot destructor
	{
		cout << "The pilot's name is " << name << ". The pilot is out of the plane." << endl;
	}

	string getName()								// get function
	{
		return name;
	}

	plane* myPlane;
};

