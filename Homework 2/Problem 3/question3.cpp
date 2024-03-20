// Question 3

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>



std::mutex m;		
int aircraft_in_pattern = 0;
int aircraft_limit = 3;
bool ATC_awake = false;			// initially sets the ATC to not be talking to an aircraft


// using printf instead of std::cout. Using std::cout mixes up the outputs.
void operate(int aircraft_ID)
{

	if (ATC_awake == false)
	{
		{
			std::unique_lock<std::mutex> lock(m);
			ATC_awake = true;		// ATC is now awake and talking
		}

		printf("Aircraft # %d requesting landing. \n", aircraft_ID);

		if (aircraft_in_pattern < aircraft_limit)		// will run if there is open room for an aircraft in the pattern
		{
			std::unique_lock<std::mutex> lock(m);
			++aircraft_in_pattern;		// adds one to aircraft in the pattern
			printf("Aircraft # %d is cleared to land. \n", aircraft_ID);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			printf("Runway is now free. \n");
			--aircraft_in_pattern;		// subtracts one to aircraft in pattern because the aircraft has now landed
		}
		else          // runs if there are too many aircraft in the pattern
		{
			printf("Approach pattern full. Aircraft # %d redirected to another airport. \n", aircraft_ID);
			printf("Aircraft # %d flying to another airport. \n", aircraft_ID);
		}

	}
	

	//if ( 1 )		// conditions to land
	//{
	//printf("Aircraft # %d requesting landing. \n", aircraft_ID);
	//printf("Aircraft # %d is cleared to land. \n", aircraft_ID);
	//printf("Runway is now free.");
	//}
	//else 		// conditions to redirect
	//{
	//	printf("Aircraft # %d requesting to land. \n", aircraft_ID);
	//	printf("Approach pattern full. Aircraft # %d redirected to another airport. \n", aircraft_ID);
	//	printf("Aircraft # %d flying to another airport. \n", aircraft_ID);
	//}
}


int main()
{


	//int ID = 1;
	//while (ID < 11)
	//{
	//	std::thread aircraft(operate,ID);
	//	++ID;
	//}

	return 0;
}

