#include <iostream>

// abstract base class called Sensor
class Sensor
{
public:
	virtual void gatherData() = 0;		// virtual functions like this need the = 0 at the end
	virtual void processData() = 0;

	// DO I NEED A CONSTRUCTOR OR DESTRUCTOR??
};


// Velocity class derived from Sensor class
class Velocity : public Sensor
{
public:
	// implementation of gatherData
	virtual void gatherData() override
	{
		std::cout << "Gathering data from Velocity Sensor" << std::endl;	// DO I NEED TO WRITE THE VELOCITY NAME DIFFERENTLY, OR IS IT OKAY HARDCODED?
	}

	// implementation of processData
	virtual void processData() override
	{
		std::cout << "Processing data from Velocity Sensor" << std::endl;	// DO I NEED TO WRITE THE VELOCITY NAME DIFFERENTLY, OR IS IT OKAY HARDCODED?
	}
};

// Attitude class derived from Sensor class
class Attitude : public Sensor
{
public:
	// implementation of gatherData
	virtual void gatherData() override
	{
		std::cout << "Gathering data from Attitude Sensor" << std::endl;	// DO I NEED TO WRITE THE ATTITUDE NAME DIFFERENTLY, OR IS IT OKAY HARDCODED?
	}

	// implementation of processData
	virtual void processData() override
	{
		std::cout << "Processing data from Attitude Sensor" << std::endl;	// DO I NEED TO WRITE THE ATTITUDE NAME DIFFERENTLY, OR IS IT OKAY HARDCODED?
	}
};

// Heading class derived from Sensor class
class Heading : public Sensor
{
public:
	// implementation of gatherData
	virtual void gatherData() override
	{
		std::cout << "Gathering data from Heading Sensor" << std::endl;	// DO I NEED TO WRITE THE HEADING NAME DIFFERENTLY, OR IS IT OKAY HARDCODED?
	}

	// implementation of processData
	virtual void processData() override
	{
		std::cout << "Processing data from Heading Sensor" << std::endl;	// DO I NEED TO WRITE THE HEADING NAME DIFFERENTLY, OR IS IT OKAY HARDCODED?
	}
};



int main()
{
	std::cout << "Hello World" << std::endl;
	return 0;
}