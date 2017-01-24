//============================================================================
// Name        : Zoo.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This cpp contains main and implementation of helpful methods.
//============================================================================

#include "Zoo.h"
#include "lizard.h"
#include "snake.h"
#include "eagle.h"
#include "chicken.h"
#include "bear.h"
#include "hyena.h"
#include "lion.h"
#include <iostream>
#include <iomanip>
int main() {
	Animal* zoo[10] = { NULL };
	Zoo::initialize(zoo);
	bool done = 0;
	int choice = 0;
	while (!done) {
		choice=Zoo::menuAndChoice(zoo);
		switch (choice) {
		case 1:
			Zoo::add(zoo);
			break;
		case 2:
			Zoo::remove(zoo);
			break;
		case 3:
			Zoo::displayAllAnimals(zoo);
			break;
		case 4:
			Zoo::displayAnimalCount(zoo);
			break;
		case 5:
			std::cout << "-Exiting-" << std::endl;
			done = 1;
			break;
		default:
			std::cout << "-Invalid Input-" << std::endl;
			break;
		}
	}
	return 0;
}

//Precondition:
//	_Zoo must be an pointers array of size 10.
//Postcondition:
//	_Initilize pointers array with some values.
void Zoo::initialize(Animal ** zoo)
{
	*(zoo + 0) = new snake;
	*(zoo + 4) = new eagle;
	*(zoo + 5) = new bear;
	*(zoo + 8) = new lion;
	*(zoo + 9) = new hyena;
}

//Precondition:
//	_Zoo must be an pointer array of size 10.
//Postcondition:
//	_Return user's choice for a given menu.
int Zoo::menuAndChoice(Animal ** zoo)
{	
	Zoo::displayZooCages(zoo);
	int choice = 0;
	bool good = 0;
	bool done = 0;
	while (!done) {
		std::cout << ("----Menu----") << std::endl;;
		std::cout << ("1. Add") << std::endl;
		std::cout << ("2. Remove") << std::endl;
		std::cout << ("3. Display all animals") << std::endl;
		std::cout << ("4. Display animal count") << std::endl;
		std::cout << ("5. Exit") << std::endl;
		while (!good) {
			std::cout << ("Enter: ");
			std::cin >> choice;
			if (!std::cin||choice<1||choice>5) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "-Invalid Input. Please try again." << std::endl;
			}
			else {
				good = 1;;
			}
		}
		done = 1;
	}
	return choice;
}

//Precondition:
//	_Zoo must be an pointer array of size 10.
//Postcondition:
//	_Print out all cage's number and cage's content.
void Zoo::displayZooCages(Animal ** zoo)
{
	int i = 1;
	std::cout << ("----Zoo Cages----") << std::endl;
	for (; i < 11; i++) {
		if ((zoo[i - 1]) != nullptr) {
			printf("%-5d %-5s\n",i, (**(zoo + i - 1)).getAnimalType().c_str());
		}
		else {
			printf("%-5d [%-5s]\n", i,"Empty");
		}
	} 
	printf("%-5d %-5s\n", i, "Exit");
	std::cout << "_______________________________________________________________________________" << std::endl;


}

//Precondition:
//	_Zoo must be an pointer array of size 10.
//Postcondition:
//	_Add an animal to an empty cage.
void Zoo::add(Animal ** zoo)
{
	std::cout << "-Adding Animal-" << std::endl;
	int cageNumber = 0;
	int choice = 0;
	bool added = 0;
	bool done = 0;
	Zoo::displayZooCages(zoo);
	while (!added) {
		std::cout << "Enter cage number: ";
		std::cin >> cageNumber;
		if (std::cin&&cageNumber < 12 && cageNumber>0) {
			if (cageNumber ==11) {
				std::cout << "-Exiting" << std::endl;
				break;
			}
			if (*(zoo + cageNumber - 1) == nullptr) {
				std::cout << "-Available Animals-" << std::endl;
				std::cout << "1. lizard" << std::endl;
				std::cout << "2. snake" << std::endl;
				std::cout << "3. eagle" << std::endl;
				std::cout << "4. chicken" << std::endl;
				std::cout << "5. bear" << std::endl;
				std::cout << "6. hyena" << std::endl;
				std::cout << "7. lion" << std::endl;
				std::cout << "8. Exiting" << std::endl;
				while (!done)
				{
					std::cout << "Enter:";
					std::cin >> choice;
					if (std::cin&&choice < 9 && choice>0) {
						switch (choice) {
							delete[] * (zoo + choice - 1);
						case 1:
							*(zoo + cageNumber - 1) = new lizard;
							break;
						case 2:
							*(zoo + cageNumber - 1) = new snake;
							break;
						case 3:
							*(zoo + cageNumber - 1) = new eagle;
							break;
						case 4:
							*(zoo + cageNumber - 1) = new chicken;
							break;
						case 5:
							*(zoo + cageNumber - 1) = new bear;
							break;
						case 6:
							*(zoo + cageNumber - 1) = new hyena;
							break;
						case 7:
							*(zoo + cageNumber - 1) = new lion;
							break;
						case 8:
							std::cout << "-Exiting-" << std::endl;
							break;
						}
						if (choice > 0 && choice < 8) {
							std::cout << "Added: " << (**(zoo + cageNumber - 1)).getAnimalType() << " at cage " << cageNumber << std::endl;
						}
						done = 1;
						added = 1;
						
					}
					else {
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "-Invalid Input. Plese try again.-" << std::endl;
					}
				}
			}
			else {
				std::cout << "-Cage occupired.Please try again-" << std::endl;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "-Invalid Input. Plese try again.-" << std::endl;
		}
	}
}

//Precondition:
//	_Zoo must be an pointer array of size 10.
//Postcondition:
//	_Remove an animal from an ocupied cage.
void Zoo::remove(Animal ** zoo)
{
	std::cout << "-Removing Animal-" << std::endl;
	int choice = 0;
	bool removed = 0;
	while (!removed) {
		Zoo::displayZooCages(zoo);
		std::cout << "Enter cage number: ";
		std::cin >> choice;
		if (std::cin&&choice < 12 && choice>0) {
			if (choice == 11) {
				std::cout << "-Exiting" << std::endl;
				break;
			}
			if (*(zoo + choice - 1) == nullptr) {
				std::cout << "-Nothing to be remove. Given cage is empty.-" << std::endl;
			}
			else {
				std::cout << "Removed: " << (**(zoo + choice - 1)).getAnimalType()<<" at cage "<<choice << std::endl;
				delete *(zoo + choice - 1);
				*(zoo + choice - 1) = NULL;
				removed = 1;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "-Invalid Input. Plese try again.-" << std::endl;
		}
	}
}

//Precondition:
//	_Zoo must be an pointer array of size 10.
//Postcondition:
//	_Print out all the animal's cage nubmer and animal's details.
void Zoo::displayAllAnimals(Animal ** zoo)
{
	std::cout << std::setw(0) << "Cage";
	std::cout<<std::setw(30) << "Animal(Type, Talk, Move)" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << std::setw(0)<<i+1 << "  ";
		if (*(zoo + i) == nullptr) {
			std::cout <<std::setw(12)<< "Empty" << std::endl;
		}
		else {
			std::cout <<std::setw(12)<< (**(zoo + i)) << std::endl;
		}
	}
}

//Precondition:
//	_Zoo must be an pointer array of size 10.
//Postcondition:
//	_Print out the number of Animal's object existed.
void Zoo::displayAnimalCount(Animal ** zoo)
{
	std::cout << "Current animal that existed: "<< (**zoo).getCount() << std::endl;
}
