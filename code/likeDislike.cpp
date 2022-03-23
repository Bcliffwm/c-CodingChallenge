/*
	The purpose of this program is to compare, pairwise, string elements of a vector and return a specified outcome depending on a certain set of rules. The rules were inspired by YouTube's like and dislike
	buttons. 

	This program assumes a binary of string choices. Including more than two options of strings to the function may yield unintended results.
*/
#include <iostream>
#include <vector>

std::string likeOrDislike(std::vector<std::string> myVec) 
{
	std::string state = "Nothing";
	int sameCount = 0;
	if (myVec.size() == 0) 
	{
		return state;
	}
	else 
	{
		if (myVec.size() == 1)
		{
			state = myVec[0];
		}
		for (int i = 0; i < myVec.size() - 1; i++) 
		{
			if (myVec[i] == myVec[ i + 1 ] && sameCount % 2 != 0) 
			{
				state = myVec[i + 1];
				sameCount += 1;
			}
			else if (myVec[i] == myVec[ i + 1 ] && sameCount % 2 == 0) 
			{
				state = "Nothing";
				sameCount += 1;
			}
			else if(myVec[i] != myVec[ i + 1 ])
			{
				state = myVec[ i + 1 ];
			}
			else 
			{
				state = "Something went wrong";
			}
		}
		return state;
	}
}

int main() 
{
	std::cout << likeOrDislike({}) << std::endl; // Nothing
	std::cout << likeOrDislike({ "Like" }) << std::endl; // Like
	std::cout << likeOrDislike({ "Dislike", "Dislike"}) << std::endl; // Nothing
	std::cout << likeOrDislike({ "Like", "Dislike", "Dislike" }) << std::endl; // Nothing
	std::cout << likeOrDislike({ "Like", "Dislike", "Like" }) << std::endl; // Like
	std::cout << likeOrDislike({"Dislike", "Like"}) << std::endl; // Like
	std::cout << likeOrDislike({ "Dislike", "Dislike", "Dislike" }) << std::endl; // Dislike
	
	return 0;
}