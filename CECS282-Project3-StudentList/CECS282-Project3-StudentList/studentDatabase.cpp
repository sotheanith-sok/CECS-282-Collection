/*
 * studentDatabase.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Sotheanith
 */
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "student.h"
#include "studentDatabaseHelper.h"


int main() {
	srand((unsigned) time(0));
	struct student list[10];
	int const size = sizeof(list) / sizeof(*list);
	struct student	*sortedIDList[size], *sortedAgeList[size], *sortedNameList[size], *sortedGradeList[size];
	//Intialize the value
	studentDatabaseHelper::initialization(list, size);
	//Copy pointers into arrays
	studentDatabaseHelper::copyPointer(list, sortedIDList, size);
	studentDatabaseHelper::copyPointer(list, sortedAgeList, size);
	studentDatabaseHelper::copyPointer(list, sortedNameList, size);
	studentDatabaseHelper::copyPointer(list, sortedGradeList, size);
	//Sort arrays
	studentDatabaseHelper::sortedByID(sortedIDList, size, 0, size - 1);
	studentDatabaseHelper::sortedByAge(sortedAgeList, size, 0, size - 1);
	studentDatabaseHelper::sortedByName(sortedNameList, size, 0, size - 1);
	studentDatabaseHelper::sortedByGrade(sortedGradeList, size, 0, size - 1);

	int choice = -1;
	do {
		choice = studentDatabaseHelper::menu();
		switch (choice) {
			case 1:
				std::cout << "-Displaying original list-"<<std::endl;
				studentDatabaseHelper::display(1,list, size);
				break;
			case 2:
				std::cout << "-Displaying list sorted by Student ID-" << std::endl;
				studentDatabaseHelper::display(2,sortedIDList, size);
				break;
			case 3:
				std::cout << "-Displaying list sorted by Student Age-" << std::endl;
				studentDatabaseHelper::display(2,sortedAgeList, size);
				break;
			case 4:
				std::cout << "-Displaying list sorted by Name-" << std::endl;
				studentDatabaseHelper::display(2,sortedNameList, size);
				break;
			case 5:
				std::cout << "-Displaying list sorted by Grade-" << std::endl;
				studentDatabaseHelper::display(2,sortedGradeList, size);
				break;
			case 6:
				std::cout << "-Exiting-" << std::endl;
				break;
			default:
				std::cout << "-Invalid Input-" << std::endl;
				break;
		}
	} while (choice != 6);
	return 0;
}
