#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Question 1.1

// abstract base class called Sensor
class Sensor
{
public:
	virtual void gatherData() = 0;		// virtual functions like this need the = 0 at the end
	virtual void processData() = 0;
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
			return std::make_unique<Velocity>();	// allocates heap memory for velocity sensor
		}
		else if (sensorName == "Attitude")
		{
			return std::make_unique<Attitude>();	// allocates heap memory for attitude sensor
		}
		else if (sensorName == "Heading")
		{
			return std::make_unique<Heading>();		// allocates heap memory for heading sensor
		}
		else   // returns a null pointer if the sensor name does not match any of the three I chose to use
		{
			return nullptr;
		}
	}
};

// Question 1.4

class AerospaceControlSystem
{
private: 
	std::vector<std::unique_ptr<Sensor>> sensors;	// this stores the sensors in a vector of unique pointers

public:
	void addSensor(std::unique_ptr<Sensor> sensor)	// addSensor function that recieves pointer to sensor class
	{
		sensors.push_back(std::move(sensor));	// moves the sensor into the vector of sensors
	}

	void monitorAndAdjust()
	{
		for (const auto& sensor : sensors)	// iterates through all sensors
		{
			sensor->gatherData();	// calls gatherData		
			sensor->processData();	// calls processData
			std::cout << "Adjusting controls based on sensor data" << std::endl;
		}
	}
};

int main()
{
	AerospaceControlSystem ctrlSys;		// instantiate an object from the AerospaceControlSystem class called ctrlSys

	// invoke the addSensor function three different times
	ctrlSys.addSensor(SensorFactory::createSensor("Velocity"));
	ctrlSys.addSensor(SensorFactory::createSensor("Attitude"));
	ctrlSys.addSensor(SensorFactory::createSensor("Heading"));

	// invoke the monitorAndAdjust function once 
	ctrlSys.monitorAndAdjust();

	return 0;
}