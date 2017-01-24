//============================================================================
// Name        : bear.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class mammal which implement all the neccessary constructor and methods. 
//============================================================================
#ifndef BEAR_H_
#define BEAR_H_
#include <string>
#include "mammal.h"

class bear:public mammal
{
public:
	bear();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Initilize the animalType to "bear".
	
	std::string talk();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return bear's talk.

	std::string move();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return bear's move.

};
#endif

