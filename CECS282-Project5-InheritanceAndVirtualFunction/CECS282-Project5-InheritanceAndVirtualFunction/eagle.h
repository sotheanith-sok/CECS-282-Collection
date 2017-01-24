//============================================================================
// Name        : eagle.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class bird which implement all the neccessary constructor and methods. 
//============================================================================
#ifndef EAGLE_H_
#define EAGLE_H_
#include <string>
#include "bird.h"
class eagle:public bird
{
public:
	eagle();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Initilize the animalType to "eagle".

	std::string talk();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return eagle's talk.

	std::string move();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return eagle's move.
};
#endif

