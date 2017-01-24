//============================================================================
// Name        : lizard.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class repitle which implement all the neccessary constructor and methods. 
//============================================================================

#include "lizard.h"

//Precondition:
//	_None.
//Postcondition:
//	_Initilize the animalType to "lizard".
lizard::lizard()
{
	animalType = new std::string("lizard");
	count++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return lizard's talk.
std::string lizard::talk()
{
	return "cry";
}

//Precondition:
//	_None.
//Postcondition:
//	_Return lizard's move.
std::string lizard::move()
{
	return "crawl";
}


