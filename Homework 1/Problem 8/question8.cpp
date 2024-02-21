// Rewriting question 7 to use the modern c++ style pointers
/*
#include <iostream>
#include <string>
#include <map>
#include <memory>
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

	pilot_in_command->myPlane = std::move(plane);

	for (int iter = 0; iter <= max_iter; ++iter) {
		pilot_in_command->myPlane->operate(dt);

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


#include <iostream>
#include <string>
#include <memory> // Include memory header for smart pointers
#include "pilot_class.h"
#include "plane_class.h"

using namespace std;

int main() {
	//std::unique_ptr<Pilot> pilot_in_command = std::make_unique<Pilot>("Alpha");
	//std::unique_ptr<Pilot> copilot = std::make_unique<Pilot>("Bravo");

	std::unique_ptr<Pilot> pilot_in_command = std::make_unique<Pilot>("Alpha", "SCE", "ORD");
	std::unique_ptr<Pilot> copilot = std::make_unique<Pilot>("Bravo", "SCE", "ORD");


	std::unique_ptr<Plane> plane = std::make_unique<Plane>("SCE", "ORD");
	plane->setVel(425);
	double dt = 50 / 3600.0;
	int max_iter = 1200;

	pilot_in_command.myPlane = std::move(plane); // Use std::move to transfer ownership

	for (int iter = 0; iter <= max_iter; ++iter) {
		pilot_in_command->myPlane->operate(dt);

		if (iter == 0) {
			cout << "The plane " << pilot_in_command->myPlane << " is at " << pilot_in_command->myPlane->getOrigin() << endl;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command.get() << " is in control of a plane: " << pilot_in_command->myPlane->getDestination() << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot.get() << " is in control of a plane: " << copilot->myPlane->getDestination() << endl;
			cout << endl;
		}

		if (pilot_in_command->myPlane->getAt_SCE()) {
			cout << "The plane " << pilot_in_command->myPlane << " is at " << pilot_in_command->myPlane->getOrigin() << endl;
			std::swap(pilot_in_command->myPlane, copilot->myPlane);
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command.get() << " is in control of a plane: " << pilot_in_command->myPlane->getDestination() << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot.get() << " is in control of a plane: " << copilot->myPlane->getDestination() << endl;
			cout << endl;
		}
	}

	return 0;
}
*/

// copied over from question 7
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include "pilot_class.h"
#include "plane_class.h"

using namespace std;

int main() {
	std::unique_ptr<Pilot> pilot_in_command = std::make_unique<Pilot>("Alpha");
	std::unique_ptr<Pilot> copilot = std::make_unique<Pilot>("Bravo");

	Plane plane("SCE", "ORD");
	plane.setVel(425);
	double dt = 50 / 3600.0;
	int max_iter = 1200;

	//pilot_in_command->myPlane = &plane;

	for (int iter = 0; iter <= max_iter; ++iter) {
		plane.operate(dt);

		if (iter == 0) {
			cout << "The plane " << &plane << " is at SCE" << endl;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << &plane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << ptr << endl;
			cout << endl;
		}

		if (plane.getAt_SCE()) {
			cout << "The plane " << &plane << " is at SCE" << endl;
			//swap(&plane, ptr);
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << &plane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << ptr << endl;
			cout << endl;
		}
	}

	return 0;
}