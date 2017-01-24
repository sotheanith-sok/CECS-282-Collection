//============================================================================
// Name        : lion.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class mammal which implement all the neccessary constructor and methods. 
//============================================================================
#ifndef LION_H_
#define LION_H_
#include <string>
#include "mammal.h"
class lion:public mammal
{
public:
	lion();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Initilize the animalType to "lion".

	std::string talk();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return lion's talk.

	std::string move();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return lion's move.
};
#endif

