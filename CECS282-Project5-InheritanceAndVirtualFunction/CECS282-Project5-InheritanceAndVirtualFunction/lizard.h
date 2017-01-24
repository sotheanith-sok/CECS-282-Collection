//============================================================================
// Name        : lizard.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class repitle which implement all the neccessary constructor and methods. 
//============================================================================
#ifndef LIZARD_H_
#define LIZARD_H_
#include <string>
#include "repitle.h"
class lizard:public repitle
{
public:
	lizard();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Initilize the animalType to "lizard".

	std::string talk();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return lizard's talk.

	std::string move();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return lizard's move.
};
#endif
