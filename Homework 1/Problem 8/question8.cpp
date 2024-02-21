// changing to modern style pointers
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

	std::unique_ptr<int> nullPtr = nullptr;
	std::unique_ptr<Plane> myPlane;
	myPlane.reset(&plane);

	pilot_in_command->myPlane.reset(&plane);

	for (int iter = 0; iter <= max_iter; ++iter) {
		plane.operate(dt);

		if (iter == 0) {
			cout << "The plane " << &plane << " is at SCE" << endl;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << nullPtr << endl;
			cout << endl;
		}

		if (plane.getAt_SCE()) {
			cout << "The plane " << &plane << " is at SCE" << endl;
			swap(copilot->myPlane, pilot_in_command->myPlane);
			swap(pilot_in_command, copilot);
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << nullPtr << endl;
			cout << endl;
		}
	}

	return 0;
}
