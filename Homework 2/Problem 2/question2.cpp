// Question 2

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


std::mutex m1, m2, m3, m4, m5;	// create a mutex for each of the 5 tools


void operate(int id, int tool_1, int tool_2)
{
	if (tool_1 == 1 && tool_2 == 5)		// logic for robot 1
	{
		std::lock(m1, m5);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m1.unlock();
		m5.unlock();
	}

	if (tool_1 == 1 && tool_2 == 2)		// logic for robot 2
	{
		std::lock(m1, m2);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m1.unlock();
		m2.unlock();
	}

	if (tool_1 == 2 && tool_2 == 3)		// logic for robot 3
	{
		std::lock(m2, m3);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m2.unlock();
		m3.unlock();
	}

	if (tool_1 == 3 && tool_2 == 4)		// logic for robot 4
	{
		std::lock(m3, m4);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
		m3.unlock();
		m4.unlock();
	}

	if (tool_1 == 4 && tool_2 == 5)		// logic for robot 5
	{
		std::lock(m4, m5);
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

	// robot ids
	int id1 = 1, id2 = 2, id3 = 3, id4 = 4, id5 = 5;
	

	int tool1 = 1, tool2 = 2, tool3 = 3, tool4 = 4, tool5 = 5;		// numbering every tool

	// create a thread for every robot
	std::thread robot1(operate, id1, tool1, tool5);
	std::thread robot2(operate, id2, tool1, tool2);
	std::thread robot3(operate, id3, tool2, tool3);
	std::thread robot4(operate, id4, tool3, tool4);
	std::thread robot5(operate, id5, tool4, tool5);

	robot1.join();
	robot2.join();
	robot3.join();
	robot4.join();
	robot5.join();

	return 0;
}






//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include "time.h"
//
//std::mutex m0;
//std::mutex m1;
//std::mutex m2;
//std::mutex m3;
//std::mutex m4;
//
//
//void createRobot(int id, int toola, int toolb)
//{
//    // robot 0
//    // if the robot that reaches this thread uses either tools 0 or 4, this if statement will run
//    if (toola == 0 && toolb == 4)
//    {
//        // locks the resource of tools 0 and 4
//        std::lock(m0, m4);
//        std::cout << "Robot " << id << " is collecting data." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//        std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
//        m0.unlock();
//        m4.unlock();
//    }
//
//    // robot 1
//    // if the robot that reaches this thread uses either tools 0 or 1, this if statement will run
//    if (toola == 0 && toolb == 1)
//    {
//        // locks the resource of tools 0 and 1
//        std::lock(m0, m1);
//        std::cout << "Robot " << id << " is collecting data." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//        std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
//        m0.unlock();
//        m1.unlock();
//    }
//
//    // robot 2
//    // if the robot that reaches this thread uses either tools 1 or 2, this if statement will run
//    if (toola == 1 && toolb == 2)
//    {
//
//        // locks the resource of tools 1 and 2
//        std::lock(m1, m2);
//        std::cout << "Robot " << id << " is collecting data." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//        std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
//        m1.unlock();
//        m2.unlock();
//
//    }
//
//
//    // robot 3
//    // if the robot that reaches this thread uses either tools 2 or 3, this if statement will run
//    if (toola == 2 && toolb == 3)
//    {
//        // locks the resource of tools 2 and 3
//        std::lock(m2, m3);
//        std::cout << "Robot " << id << " is collecting data." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//        std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
//        m2.unlock();
//        m3.unlock();
//    }
//
//    // robot 4
//    // if the robot that reaches this thread uses either tools 3 or 4, this if statement will run
//    if (toola == 3 && toolb == 4)
//    {
//        // locks the resource of tools 3 and 4
//        std::lock(m3, m4);
//        std::cout << "Robot " << id << " is collecting data." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(5));
//        std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;
//        m3.unlock();
//        m4.unlock();
//    }
//
//
//}
//
//int main()
//{
//    clock_t totalTime = clock(); // keeps track of total time
//
//    // declaration of tools
//    int tool0 = 0;
//    int tool1 = 1;
//    int tool2 = 2;
//    int tool3 = 3;
//    int tool4 = 4;
//
//    // creates threads for each robot, passes in robot id and tools used
//    std::thread robot0(createRobot, 0, tool0, tool4);
//    std::thread robot1(createRobot, 1, tool0, tool1);
//    std::thread robot2(createRobot, 2, tool1, tool2);
//    std::thread robot3(createRobot, 3, tool2, tool3);
//    std::thread robot4(createRobot, 4, tool3, tool4);
//
//    // attaches robots to main thread
//    robot0.join();
//    robot1.join();
//    robot2.join();
//    robot3.join();
//    robot4.join();
//
//    std::cout << "Duration: " << (double)(clock() - totalTime) / 1000 << " seconds" << std::endl; // prints out time
//
//    return 0;
//}