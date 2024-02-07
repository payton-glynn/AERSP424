#include <iostream>
using namespace std;

int main()
{
	// start by initializing variables and their data type
	int empty_weight;					// aircraft empty weight (pounds)
	int empty_weight_moment;			// aircraft empty weight moment (pound-inches)
	int front_occupants;				// number of front seat occupants 
	int front_occupant_1;				// weight of first front seat passenger (pounds)
	int front_occupant_2;				// weight of second front seat passenger (pounds)
	int front_moment_arm;				// front seat moment arm (inches)
	int rear_occupants;					// number of rear seat occupants
	int rear_occupant_1;				// weight of first rear seat passenger (pounds)
	int rear_occupant_2;				// weight of second rear seat passenger (pounds)
	int rear_moment_arm;				// rear seat moment arm (inches)
	float usable_fuel;					// amount of usable fuel (gallons)
	int usable_fuel_weight_per_gal;		// usable fuel weight per gallon (pounds)
	int fuel_moment_arm;				// fuel tank moment arm (inches)
	int bag_weight;						// baggage weight (pounds)
	int bag_moment_arm;					// baggage area moment arm (inches)

	// allow the user to input aircraft characteristics
	cout << "Enter airplane empty weight (pounds): ";
	cin >> empty_weight;
	cout << "Enter airplane empty-weight moment (pound-inches): ";
	cin >> empty_weight_moment;
	cout << "Enter number of front seat passengers: ";
	cin >> front_occupants;
	cout << "Enter weight of first front seat passenger (pounds): ";
	cin >> front_occupant_1;
	cout << "Enter weight of second front seat passenger (pounds): ";
	cin >> front_occupant_2;
	cout << "Enter front seat moment arm (inches): ";
	cin >> front_moment_arm;
	cout << "Enter number of rear seat passengers: ";
	cin >> rear_occupants;
	cout << "Enter weight of first rear seat passenger (pounds): ";
	cin >> rear_occupant_1;
	cout << "Enter weight of second rear seat passenger (pounds): ";
	cin >> rear_occupant_2;
	cout << "Enter rear seat moment arm (inches): ";
	cin >> rear_moment_arm;
	cout << "Enter amount of usable fuel (gallons): ";
	cin >> usable_fuel;
	cout << "Enter usable fuel weight per gallon (pounds): ";
	cin >> usable_fuel_weight_per_gal;
	cout << "Enter fuel tank moment arm (inches): ";
	cin >> fuel_moment_arm;
	cout << "Enter baggage weight (pounds): ";
	cin >> bag_weight;
	cout << "Enter baggage moment arm (inches): ";
	cin >> bag_moment_arm;

	float usable_fuel_weight = usable_fuel * usable_fuel_weight_per_gal;		// weight of all the fuel (pounds)

	// find the total weight of aircraft
	double weight = empty_weight + front_occupant_1 + front_occupant_2 + rear_occupant_1 + rear_occupant_2 + usable_fuel_weight + bag_weight;
	
	// find how much fuel needs to be drained to be under the max weight limit
	while ( weight > 2950 )
	{
		usable_fuel -= 0.01;
		usable_fuel_weight = usable_fuel * usable_fuel_weight_per_gal;
		weight = empty_weight + front_occupant_1 + front_occupant_2 + rear_occupant_1 + rear_occupant_2 + usable_fuel_weight + bag_weight;
	}

	// find CG of aircraft
	double CG = (empty_weight_moment + ((front_occupant_1 + front_occupant_2) * front_moment_arm) + ((rear_occupant_1 + rear_occupant_2) * rear_moment_arm) + (usable_fuel_weight * fuel_moment_arm) + (bag_weight * bag_moment_arm)) / weight;
	
	// find how much fuel needs to be drained/added to meet CG requirements
	// begin with cases that need to subtract fuel
	if (CG < 82.1 && fuel_moment_arm < 82.1 && fuel_moment_arm < CG || CG > 84.7 && fuel_moment_arm > 84.7 && fuel_moment_arm > CG)		
	{
		while (CG < 82.1)
		{
			usable_fuel -= 0.01;
			usable_fuel_weight = usable_fuel * usable_fuel_weight_per_gal;
			weight = empty_weight + front_occupant_1 + front_occupant_2 + rear_occupant_1 + rear_occupant_2 + usable_fuel_weight + bag_weight;
			CG = (empty_weight_moment + ((front_occupant_1 + front_occupant_2) * front_moment_arm) + ((rear_occupant_1 + rear_occupant_2) * rear_moment_arm) + (usable_fuel_weight * fuel_moment_arm) + (bag_weight * bag_moment_arm)) / weight;
		}
		cout << "The amount of fuel drained is: " << 44 - usable_fuel << endl;
	}
	// cases that need to add fuel
	if (CG < 82.1 && fuel_moment_arm > 82.1 || CG > 84.7 && fuel_moment_arm < 84.7)
	{
		while (CG > 84.7)
		{
			usable_fuel += 0.01;
			usable_fuel_weight = usable_fuel * usable_fuel_weight_per_gal;
			weight = empty_weight + front_occupant_1 + front_occupant_2 + rear_occupant_1 + rear_occupant_2 + usable_fuel_weight + bag_weight;
			CG = (empty_weight_moment + ((front_occupant_1 + front_occupant_2) * front_moment_arm) + ((rear_occupant_1 + rear_occupant_2) * rear_moment_arm) + (usable_fuel_weight * fuel_moment_arm) + (bag_weight * bag_moment_arm)) / weight;
		}
		cout << "The amount of fuel added is: " << usable_fuel - 44 << endl;
	}

	cout << "Total aircraft gross weight is: " << weight << " pounds" << endl;
	cout << "The aircraft center of gravity is: " << CG << " inches" << endl;

	return 0;
}

// SCENARIOS 
// CG in front of fore limit AND fuel moment arm in front fore limit AND fuel in front of CG		DRAIN FUEL
// CG behind aft limit AND fuel moment arm behind aft limit AND fuel behind CG						DRAIN FUEL
// 
// CG in front of fore limit AND fuel moment arm within limit				ADD FUEL
// CG in front of fore limit AND fuel moment arm behind aft limit			ADD FUEL
// CG behind aft limit AND fuel moment arm in front of fore limit			ADD FUEL
// CG behind aft limit AND fuel moment arm in within limit					ADD FUEL

// GETS COMPLICATED WHEN CG PASSES OVER THE FUEL LOCATION