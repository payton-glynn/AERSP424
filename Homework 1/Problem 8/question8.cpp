#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "pilot_class.h"
#include "plane_class.h"

using namespace std;

int main() {
	Pilot* pilot_in_command = new Pilot("Alpha");
	Pilot* copilot = new Pilot("Bravo");

	Plane plane("SCE", "ORD");
	plane.setVel(425);
	double dt = 50 / 3600.0;
	int max_iter = 1200;

	pilot_in_command->myPlane = &plane;

	for (int iter = 0; iter <= max_iter; ++iter) {
		plane.operate(dt);

		if (iter == 0) {
			cout << "The plane " << pilot_in_command->myPlane << " is at SCE" << endl;
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << copilot->myPlane << endl;
			cout << endl;
		}

		if (plane.getAt_SCE()) {
			cout << "The plane " << &plane << " is at SCE" << endl;
			swap(pilot_in_command->myPlane, copilot->myPlane);
			cout << "Pilot " << pilot_in_command->getName() << " with certificate number " << pilot_in_command << " is in control of a plane: " << pilot_in_command->myPlane << endl;
			cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in control of a plane: " << copilot->myPlane << endl;
			cout << endl;
		}
	}

	delete pilot_in_command;
	delete copilot;

	return 0;
}
