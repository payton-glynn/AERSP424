// Question 3

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;		// create a mutex named m that will lock if three aircraft are in the traffic pattern
std::condition_variable cv;
int aircraft_in_pattern = 0;
bool ATC_awake = false;


// using printf instead of std::cout. Using std::cout mixes up the outputs.
void operate(int aircraft_ID)
{
	std::unique_lock<std::mutex> lock(m);

	while (aircraft_in_pattern >= 3 && ATC_awake)
	{
		cv.wait(lock);
	}

	if (!ATC_awake)
	{
		//printf("Aircraft # %d woke up the ATC. \n", aircraft_ID);
		ATC_awake = true;
	}

	if (aircraft_in_pattern < 3)
	{
		++aircraft_in_pattern;
		printf("Aircraft # %d entering traffic pattern. \n", aircraft_ID);
	}
	else
	{
		printf("Aircraft # %d redirected to another airport. \n", aircraft_ID);
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));

	--aircraft_in_pattern;
	if (aircraft_in_pattern == 0)
	{
		ATC_awake = false;
		//printf("ATC fell asleep. \n");
	}

	cv.notify_all();

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
	std::thread aircraft_threads[10];

	for (int i = 0; i < 10; ++i)
	{
		aircraft_threads[i] = std::thread(operate, i + 1);
	}

	for (int i = 0; i < 10; ++i)
	{
		aircraft_threads[i].join();
	}

	//int ID = 1;
	//while (ID < 11)
	//{
	//	std::thread aircraft(operate,ID);
	//	++ID;
	//}

	return 0;
}

