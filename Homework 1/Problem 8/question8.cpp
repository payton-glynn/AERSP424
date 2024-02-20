// Rewriting question 7 to use the modern c++ style pointers

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "pilot_class.h"
#include "plane_class.h"

using namespace std;

int main() {
	std::unique_ptr<Pilot> pilot_in_command = std::make_unique<Pilot>("Alpha");				// using modern c++ style pointers
	std::unique_ptr<Pilot> copilot = std::make_unique<Pilot>("Bravo");						// using modern c++ style pointers

	std::unique_ptr<Plane> plane = std::make_unique<Plane>("SCE", "ORD");
	//Plane plane("SCE", "ORD");
	plane->setVel(425);
	double dt = 50 / 3600.0;
	int max_iter = 1200;

	pilot_in_command->myPlane = plane.get();

	for (int iter = 0; iter <= max_iter; ++iter) {
		plane->operate(dt);

		if (iter == 0) {
			cout << "The plane " << pilot_in_command->myPlane << " is at SCE" << endl;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command.get() << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot.get() << " is in control of a plane: " << copilot->myPlane << endl;
			cout << endl;
		}

		if (plane->getAt_SCE()) {
			cout << "The plane " << pilot_in_command->myPlane << " is at SCE" << endl;
			std::swap(pilot_in_command->myPlane, copilot->myPlane);
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command.get() << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot.get() << " is in control of a plane: " << copilot->myPlane << endl;
			cout << endl;
		}
	}

	return 0;
}

