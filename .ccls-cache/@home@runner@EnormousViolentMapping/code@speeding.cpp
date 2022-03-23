/*
	This code contains a function that calculates the amount of time (in minutes) saved
	by speeding rather than traveling the speed limit given the same distance.

	Results are printed with one decimal point.
*/
#include <iostream>
#include <iomanip>


float timeSaved(float speedLim, float speedAvg, float dist) 
{
	float time1 = dist / speedLim; // time traveling while going the speed limit
	float time2 = dist / speedAvg; // time traveling while speeding

	return (time1 - time2) * 60;
}

int main() 
{
	std::cout << std::fixed;
	std::cout << std::setprecision(1) << timeSaved(60, 60, 20) << std::endl;
	std::cout << std::setprecision(1) << timeSaved(60, 65, 25) << std::endl;
	std::cout << std::setprecision(1) << timeSaved(70, 92, 50) << std::endl;
	std::cout << std::setprecision(1) << timeSaved(70, 92, 20) << std::endl;
	std::cout << std::setprecision(1) << timeSaved(80, 90, 4000) << std::endl;
	return 0;
}