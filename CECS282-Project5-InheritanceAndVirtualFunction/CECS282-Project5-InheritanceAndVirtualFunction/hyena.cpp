// Name        : hyena.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class mammal which implement all the neccessary constructor and methods. 
//============================================================================

#include "hyena.h"

//Precondition:
//	_None.
//Postcondition:
//	_Initilize the animalType to "hyena".
hyena::hyena()
{
	animalType = new std::string("hyena");
	count++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return hyena's talk.
std::string hyena::talk()
{
	return "howl";
}

//Precondition:
//	_None.
//Postcondition:
//	_Return hyena's move.
std::string hyena::move()
{
	return "run";
}


