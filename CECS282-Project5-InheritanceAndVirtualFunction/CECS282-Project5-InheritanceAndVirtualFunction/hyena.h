//============================================================================
// Name        : hyena.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class mammal which implement all the neccessary constructor and methods. 
//============================================================================
#ifndef HYENA_H_
#define HYENA_H_
#include <string>
#include "mammal.h"

class hyena:public mammal
{
public:
	hyena();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Initilize the animalType to "hyena".

	std::string talk();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return hyena's talk.

	std::string move();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return hyena's move.
};
#endif

