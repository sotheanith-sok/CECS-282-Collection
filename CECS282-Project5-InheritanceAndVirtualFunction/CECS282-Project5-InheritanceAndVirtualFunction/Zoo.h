//============================================================================
// Name        : Zoo.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This static methods' header contains all signatures used in main.
//============================================================================
#ifndef ZOO_H_
#define ZOO_H_
#include "Animal.h"

class Zoo
{
public:
	static void initialize(Animal** zoo);
	//Precondition:
	//	_Zoo must be an pointers array of size 10.
	//Postcondition:
	//	_Initilize pointers array with some values.

	static int menuAndChoice(Animal** zoo);
	//Precondition:
	//	_Zoo must be an pointer array of size 10.
	//Postcondition:
	//	_Return user's choice for a given menu.

	static void displayZooCages(Animal** zoo);
	//Precondition:
	//	_Zoo must be an pointer array of size 10.
	//Postcondition:
	//	_Print out all cage's number and cage's content.

	static void add(Animal** zoo);
	//Precondition:
	//	_Zoo must be an pointer array of size 10.
	//Postcondition:
	//	_Add an animal to an empty cage.

	static void remove(Animal** zoo);
	//Precondition:
	//	_Zoo must be an pointer array of size 10.
	//Postcondition:
	//	_Remove an animal from an ocupied cage.

	static void displayAllAnimals(Animal** zoo);
	//Precondition:
	//	_Zoo must be an pointer array of size 10.
	//Postcondition:
	//	_Print out all the animal's cage nubmer and animal's details.

	static void displayAnimalCount(Animal** zoo);
	//Precondition:
	//	_Zoo must be an pointer array of size 10.
	//Postcondition:
	//	_Print out the number of Animal's object existed.

};
#endif