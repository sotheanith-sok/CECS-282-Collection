#pragma once
#include <vector>
//============================================================================
// Name        : STL_Containers.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This a header contains all signature of function used to test the STL Container by performing some function.
//============================================================================

class STL_Containers
{
public:
	static void generateRandomNumbers(std::vector<int>& v);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Generate 10000 randoms number between 1 and 100 and put it into a vector.

	static void printSortedVector(std::vector<int> v);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Print all value in a vector in sorted order.

	static int calculateSumOfVector(std::vector<int>& v);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Calculate the sum of all values in a vector then return the sum.

	static double calculateAverageOfVector(std::vector<int>& v);
	//Precondition:
	//	_None.
	//Postcondition:
	//	__Calculate the average of all values in a vector then return the average.

	static void printFrequency(std::vector<int>& v);
	//Precondition:
	//	_None.
	//Postcondition:
	//	__Print the frequency of all values in a listed order.
};

