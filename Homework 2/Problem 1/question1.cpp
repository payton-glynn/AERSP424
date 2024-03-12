#include <iostream>

// abstract base class called Sensor
class Sensor
{
public:
	virtual void gatherData() = 0;		// virtual functions like this need the =0 at the end
	virtual void processData() = 0;

	// DO I NEED A DESTRUCTOR??
};

int main()
{
	std::cout << "Hello World" << std::endl;
	return 0;
}