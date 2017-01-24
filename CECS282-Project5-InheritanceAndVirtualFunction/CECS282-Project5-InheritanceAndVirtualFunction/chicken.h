//============================================================================
// Name        : chicken.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class bird which implement all the neccessary constructor and methods. 
//============================================================================
#ifndef CHICKEN_H_
#define CHICKEN_H_
#include <string>
#include "bird.h"
class chicken:public bird
{
public:
	chicken();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Initilize the animalType to "chicken".

	std::string talk();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return chicken's talk.

	std::string move();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return chicken's move.
};
#endif
