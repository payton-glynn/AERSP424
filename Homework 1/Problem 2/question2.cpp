#include <iostream>
#include <map>
#include <string>


int main()
{
	std::map<std::string, std::map<std::string, double>> flight_length;
	flight_length["SCE"]["PHL"] = 160;
	flight_length["SCE"]["ORD"] = 640;
	flight_length["SCE"]["EWR"] = 220;

	return 0;
}