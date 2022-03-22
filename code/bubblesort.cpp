#include <iostream>
#include <vector>

void swap(int& a, int& b) 
{
	int temp = b;
	b = a;
	a = temp;
}

void printVec(std::vector<int> vec) 
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

std::vector<int> bubbleSort(std::vector<int> vec, int n) 
{
	// n equals the length of the vector passed
	int indx = n - 1;
	int repeat = 1;
	while (indx >= 0) 
	{
		for (int i = 0; i < indx; i++) 
		{
			if (vec[i] > vec[i + 1]) 
			{
				swap(vec[i], vec[i + 1]);
			}
		}
			
		indx -= 1;
	}
	return vec;
}

int main() 
{
	std::vector<int> myVec = { 23, 15, 34, 17, -28 };
	int myLen = myVec.size();
	std::vector<int> myNewVec = bubbleSort(myVec, myLen);
	printVec(myNewVec);
	return 0;
}