/*
  This code contains a function that takes strings and encodes each 
  letter (case-sensitive). The function is sensitive to any non-letter
  characters that may appear in the string.
*/
#include <iostream>

char letterCheck(char letter) 
{
	int targetNum, sumRemain;
	if (int(letter) >= 65 && int(letter) <= 90) 
	{
		targetNum = 155;
		sumRemain = targetNum - int(letter);
		return char(sumRemain);
	}
	else if (int(letter) >= 97 && int(letter) <= 122) 
	{
		targetNum = 219;
		sumRemain = targetNum - int(letter);
		return char(sumRemain);
	}
	else 
	{
		return letter;
	}
}

std::string atbash(std::string str) 
{
	std::string encoded;
	for (int i = 0; i < str.length(); i++) 
	{
		encoded += letterCheck(str[i]);
		//std::cout << letterCheck(str[i]);
	}
	return encoded;
}

void printString(std::string str) 
{
	for (int i = 0; i < str.length(); i++) 
	{
		std::cout << str[i];
	}

	std::cout << "\n";
}


int main()
{
	std::string string1 = atbash("apple");
	std::string string2 = atbash("Hello world!");
	std::string string3 = atbash("Christmas is the 25th of December");
	
	printString(string1);
	printString(string2);
	printString(string3);
	return 0;
}