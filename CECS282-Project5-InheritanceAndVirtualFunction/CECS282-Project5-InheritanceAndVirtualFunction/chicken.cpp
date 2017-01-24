//============================================================================
// Name        : chicken.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class bird which implement all the neccessary constructor and methods. 
//============================================================================

#include "chicken.h"

//Precondition:
//	_None.
//Postcondition:
//	_Initilize the animalType to "chicken".
chicken::chicken()
{
	animalType = new std::string("chicken");
	count++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return chicken's talk.
std::string chicken::talk()
{
	return "crow";
}

//Precondition:
//	_None.
//Postcondition:
//	_Return chicken's move.
std::string chicken::move()
{
	return "walk";
}


