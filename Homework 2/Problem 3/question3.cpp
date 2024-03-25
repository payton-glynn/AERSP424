// Question 3

// DOUBLECHECK THIS BECAUSE I AM GETTING DIFFERENT ANSWERS EVERY TIME

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

	if (ATC_awake == false)		// ATC is sleping and not talking to a pilot
	{
		// wake up ATC through pilot establishing communication
		{
			std::unique_lock<std::mutex> lock(m);
			ATC_awake = true;		// ATC is now awake and talking
		}

		printf("Aircraft # %d requesting landing. \n", aircraft_ID);

		if (aircraft_in_pattern < aircraft_limit)		// will run if there is open room for an aircraft in the pattern
		{
			++aircraft_in_pattern;		// adds one to aircraft in the pattern
			std::unique_lock<std::mutex> lock(m);
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
		ATC_awake = false;		// put the ATC back to sleep after they finish talking to the pilot
	}
	else		// ATC is awake and talking to a pilot
	{
		printf("Aircraft # %d requesting landing. \n", aircraft_ID);

		if (aircraft_in_pattern >= aircraft_limit)		// will run if there is open room for an aircraft in the pattern, even if ATC is talking to a pilot
		{
			printf("Approach pattern full. Aircraft # %d redirected to another airport. \n", aircraft_ID);
			printf("Aircraft # %d flying to another airport. \n", aircraft_ID);
		}
		else          // runs if there are too many aircraft in the pattern and ATC is talking to a pilot
		{
			++aircraft_in_pattern;		// adds one to aircraft in the pattern
			std::unique_lock<std::mutex> lock(m);
			printf("Aircraft # %d is cleared to land. \n", aircraft_ID);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			printf("Runway is now free. \n");
			--aircraft_in_pattern;		// subtracts one to aircraft in pattern because the aircraft has now landed
		}
		ATC_awake = false;		// put the ATC back to sleep after they finish talking to the pilot
	}
}


int main()
{
	auto start = std::chrono::high_resolution_clock::now();		// records the start time

	std::thread airplanes[10];		// creates an array to hold the 10 airplane threads

	// creates 10 threads, one for each airplane
	for (int i = 0; i < 10; ++i)
	{ 
		airplanes[i] = std::thread(operate, i + 1);
	}

	// joining all threads together
	for (int i = 0; i < 10; ++i)
	{
		airplanes[i].join();
	}

	auto end = std::chrono::high_resolution_clock::now();	// records the end time

	std::chrono::duration<double> elapsed = end - start;	// calculates the time elapsed
	std::cout << "Duration: " << elapsed.count() << " seconds" << std::endl;	// outputs the elapsed time

	return 0;
}
