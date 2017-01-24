//============================================================================
// Name        : eagle.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class bird which implement all the neccessary constructor and methods. 
//============================================================================

#include "eagle.h"

//Precondition:
//	_None.
//Postcondition:
//	_Initilize the animalType to "eagle".
eagle::eagle()
{
	animalType = new std::string("eagle");
	count++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return eagle's talk.
std::string eagle::talk()
{
	return "call";
}

//Precondition:
//	_None.
//Postcondition:
//	_Return eagle's move.
std::string eagle::move()
{
	return "fly";
}


