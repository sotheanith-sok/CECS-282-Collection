//============================================================================
// Name        : lion.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class mammal which implement all the neccessary constructor and methods. 
//============================================================================

#include "lion.h"

//Precondition:
//	_None.
//Postcondition:
//	_Initilize the animalType to "lion".
lion::lion()
{
	animalType = new std::string("lion");
	count++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return lion's talk.
std::string lion::talk()
{
	return "roar";
}

//Precondition:
//	_None.
//Postcondition:
//	_Return lion's move.
std::string lion::move()
{
	return "run";
}


