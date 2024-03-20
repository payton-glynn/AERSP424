// Question 2

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


std::mutex m1, m2, m3, m4, m5;	// create a mutex for each of the 5 tools

// call the function that runs everything operate
void operate(int id, int tool_1, int tool_2)		// inputs to operate or the robot id, tool_1 and tool_2
{
	if (tool_1 == 1 && tool_2 == 5)		// logic for robot 1
	{
		std::lock(m1, m5);		// locks mutex m1 and m5 simultaneously
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m1.unlock();
		m5.unlock();
	}

	if (tool_1 == 1 && tool_2 == 2)		// logic for robot 2
	{
		std::lock(m1, m2);		// locks mutex m1 and m2 simultaneously
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m1.unlock();
		m2.unlock();
	}

	if (tool_1 == 2 && tool_2 == 3)		// logic for robot 3
	{
		std::lock(m2, m3);		// locks mutex m2 and m3 simultaneously
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m2.unlock();
		m3.unlock();
	}

	if (tool_1 == 3 && tool_2 == 4)		// logic for robot 4
	{
		std::lock(m3, m4);		// locks mutex m3 and m4 simultaneously
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m3.unlock();
		m4.unlock();
	}

	if (tool_1 == 4 && tool_2 == 5)		// logic for robot 5
	{
		std::lock(m4, m5);		// locks mutex m4 and m5 simultaneously
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m4.unlock();
		m5.unlock();
	}
}

int main()
{

	// robot ids to differentiate them
	int id1 = 1, id2 = 2, id3 = 3, id4 = 4, id5 = 5;
	

	int tool1 = 1, tool2 = 2, tool3 = 3, tool4 = 4, tool5 = 5;		// numbering every tool

	auto start = std::chrono::high_resolution_clock::now();		// records the start time

	// create a thread for every robot
		// I determined which tools each robot uses by the numbering system I used and how they are oriented in a circle
	std::thread robot1(operate, id1, tool1, tool5);
	std::thread robot2(operate, id2, tool1, tool2);
	std::thread robot3(operate, id3, tool2, tool3);
	std::thread robot4(operate, id4, tool3, tool4);
	std::thread robot5(operate, id5, tool4, tool5);

	// join all the threads together
	robot1.join();
	robot2.join();
	robot3.join();
	robot4.join();
	robot5.join();

	auto end = std::chrono::high_resolution_clock::now();	// records the end time

	std::chrono::duration<double> elapsed = end - start;	// calculates the time elapsed
	std::cout << "Duration: " << elapsed.count() << " seconds" << std::endl;	// outputs the elapsed time

	return 0;
}


