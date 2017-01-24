//============================================================================
// Name        : bear.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class mammal which implement all the neccessary constructor and methods. 
//============================================================================
#include "bear.h"

//Precondition:
//	_None.
//Postcondition:
//	_Initilize the animalType to "bear".
bear::bear()
{
	animalType = new std::string("bear");
	count++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return bear's talk.
std::string bear::talk()
{
	return "growl";
}

//Precondition:
//	_None.
//Postcondition:
//	_Return bear's move.
std::string bear::move()
{
	return "walk";
}

