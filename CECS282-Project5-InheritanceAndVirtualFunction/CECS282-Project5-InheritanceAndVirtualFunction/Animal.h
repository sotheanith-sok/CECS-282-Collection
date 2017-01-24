//============================================================================
// Name        : Animal.h
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This is an abstract class contains: virtual destructor, count of all object created from Animal, operator<< overload,...etc. 
//============================================================================
#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
class Animal
{
public:
	virtual std::string talk() = 0;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Virtual method used to initilize how the Animal's talk.
	
	virtual std::string move() = 0;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Virtual method used to initilize how the Animal's move.
	
	virtual ~Animal() = 0;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Virtual destructor used to deallocated the memory used to initilize variable.
	
	std::string getAnimalType();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the name of this animal.

	int getCount();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the number of this object existed.

	friend std::ostream& operator<<(std::ostream& os, Animal& obj);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return os contains animalType, animal's talk, animal's move.
protected:
	std::string *animalType = NULL;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_This pointer pointed to a animalType string.

	static int count;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_This varaible created on the number of Animal existed.
	
};
#endif

