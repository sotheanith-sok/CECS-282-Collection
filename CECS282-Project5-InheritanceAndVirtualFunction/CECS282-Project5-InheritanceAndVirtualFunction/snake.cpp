//============================================================================
// Name        : snake.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is a concrete class from class repitle which implement all the neccessary constructor and methods. 
//============================================================================

#include "snake.h"

//Precondition:
//	_None.
//Postcondition:
//	_Initilize the animalType to "snake".
snake::snake()
{
	animalType = new std::string("snake");
	count++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return snake's talk.
std::string snake::talk()
{
	return "hisses";
}

//Precondition:
//	_None.
//Postcondition:
//	_Return snake's move.
std::string snake::move()
{
	return "crawl";
}

