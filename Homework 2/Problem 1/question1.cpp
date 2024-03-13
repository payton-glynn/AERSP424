#include <iostream>
#include <string>
#include <memory>

// Question 1.1

// abstract base class called Sensor
class Sensor
{
public:
	virtual void gatherData() = 0;		// virtual functions like this need the = 0 at the end
	virtual void processData() = 0;

	// DO I NEED A CONSTRUCTOR OR DESTRUCTOR??
};

// Question 1.2

// Velocity class derived from Sensor class
class Velocity : public Sensor
{
public:
	// implementation of gatherData
	virtual void gatherData() override
	{
		std::cout << "Gathering data from Velocity Sensor" << std::endl;
	}

	// implementation of processData
	virtual void processData() override
	{
		std::cout << "Processing data from Velocity Sensor" << std::endl;
	}
};

// Attitude class derived from Sensor class
class Attitude : public Sensor
{
public:
	// implementation of gatherData
	virtual void gatherData() override
	{
		std::cout << "Gathering data from Attitude Sensor" << std::endl;
	}

	// implementation of processData
	virtual void processData() override
	{
		std::cout << "Processing data from Attitude Sensor" << std::endl;
	}
};

// Heading class derived from Sensor class
class Heading : public Sensor
{
public:
	// implementation of gatherData
	virtual void gatherData() override
	{
		std::cout << "Gathering data from Heading Sensor" << std::endl;
	}

	// implementation of processData
	virtual void processData() override
	{
		std::cout << "Processing data from Heading Sensor" << std::endl;
	}
};

// Question 1.3

class SensorFactory		// using modern style pointers in this class 
{
public:
	static std::unique_ptr<Sensor> createSensor(const std::string& sensorName)	// static createSensor function 
	{
		// checks if the sensor name matches any of the three I chose to use
		if (sensorName == "Velocity")
		{
			return std::make_unique<Velocity>();
		}
		else if (sensorName == "Attitude")
		{
			return std::make_unique<Attitude>();
		}
		else if (sensorName == "Heading")
		{
			return std::make_unique<Heading>();
		}
		else   // returns a null pointer if the sensor name does not match any of the three I chose to use
		{
			return nullptr;
		}
	}
};

int main()
{
	std::cout << "Hello World" << std::endl;
	return 0;
}