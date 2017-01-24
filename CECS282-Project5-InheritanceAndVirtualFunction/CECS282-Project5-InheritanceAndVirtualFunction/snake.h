//============================================================================
// Name        : snake.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class repitle which implement all the neccessary constructor and methods. 
//============================================================================
#ifndef SNAKE_H_
#define SNAKE_H_
#include <string>
#include "repitle.h"
class snake:public repitle
{
public:
	snake();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Initilize the animalType to "snake".

	std::string talk();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return snake's talk.

	std::string move();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return snake's move.
};
#endif

