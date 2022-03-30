#include <iostream>
#include <math.h>

int stringToInteger(std::string str) 
{
	int temp = 0;
	for (int i = 0; i < str.length(); i++) 
	{
		temp = temp * 10 + (str[i] - '0');
	}
	return temp;
}

bool willHit(std::string equation, std::pair<int, int> position) 
{
	bool hit = false;
	// Retrieving only the right-hand side of equation
	equation = equation.substr(4);
	int coefficient, constant;
	int x = position.first;
	int y = position.second;
	
	//Retrieving coefficient value from equation
	if (equation[0] == '-') 
	{
		coefficient = (int)(equation[1]-48) * -1;
	}
	else
	{
		coefficient = (int)(equation[0]-48);
	}

	//Formatting string - easier to identify numbers in shorter string
	equation = equation.substr(equation.find('x')+2);
	//Removing all spaces
	equation.erase(remove(equation.begin(), equation.end(), ' '), equation.end());
	
	if (equation[0] == '-') 
	{
		equation = equation.substr(equation.find('-') + 1);
		constant = stringToInteger(equation) * -1;
	}
	else 
	{
		equation = equation.substr(equation.find('+') + 1);
		constant = stringToInteger(equation);
	}
	if (y == (coefficient * x) + constant) 
	{
		hit = true;
	}
	return hit;
}


int main()
{
	std::cout << willHit("y = 2x - 5", { 0, 0 }) << std::endl;
	std::cout << willHit("y = -4x + 6", { 1, 2 }) << std::endl;
	std::cout << willHit("y = -4x + 6", { 2, 2 }) << std::endl;
	std::cout << willHit("y = 3x - 8", { 4, 4 }) << std::endl;
	std::cout << willHit("y = 2x + 6", { 3, 2 }) << std::endl;
	std::cout << willHit("y = -3x + 15", { 5, 0 }) << std::endl;
	return 0;
}