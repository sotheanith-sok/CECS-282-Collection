/*
* studentDatabaseHelper.cpp
*
*  Created on: Sep 21, 2016
*      Author: Sotheanith Sok
*/
#include "studentDatabaseHelper.h"
#include "student.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstring>
#include <string>

//Precondtion:
//	_size must be 10
//	_enough memory neccessary to store 10 student structures
//Postcondtion:
//	_intitalize student structure to a predetermine name, unique identification number, grade,
//	and a date of birth between January 1, 1990 and December 31, 1994
void studentDatabaseHelper:: initialization(struct student *list, int size) {
	//Initialize the name
	strcpy_s((list + 0)->name, "Thomas");
	strcpy_s((list + 1)->name, "Thor");
	strcpy_s((list + 2)->name, "Bob that guy");
	strcpy_s((list + 3)->name, "Joe the Plumber");
	strcpy_s((list + 4)->name, "Morgan de Morgan");
	strcpy_s((list + 5)->name, "Mordremot");
	strcpy_s((list + 6)->name, "Primodus");
	strcpy_s((list + 7)->name, "Jormag");
	strcpy_s((list + 8)->name, "Zhaitain");
	strcpy_s((list + 9)->name, "Kralkatorrik");
	std::vector<int> duplicationList;
	for (int i = 0; i < 10; i++) {
		//Initialize the ID
		int done = false;
		while (!done) {
			int j = (int)(rand() % 9000) + 1000;
			if (!(std::find(duplicationList.begin(), duplicationList.end(), j) != duplicationList.end())) {
				duplicationList.push_back(j);
				(list+i)->id = j;
				done = true;
			}
		}
		//Initialize the grade
		(list + i)->grade = (int)(rand() % 51) + 50;
		//Initialize date of birth
		int m = (int)(rand() % 12) + 1;
		int y = (int)(rand() % 5) + 1990;
		int d = (int)(rand() % myDate::NumberOfDayInMonth(m, y)) + 1;
		myDate date(m, d, y);
		(list + i)->dob = date;
	}
}

//Precondtion:
//	_none
//Postcondtion:
//	_Return the valid option in which the user chose
int studentDatabaseHelper::menu() {
	bool done = false;
	std::string choice = "0";
	std::cout << "1. Display original list" << std::endl;
	std::cout << "2. Display list sorted by Student ID" << std::endl;
	std::cout << "3. Display list sorted by Student Age" << std::endl;
	std::cout << "4. Display list sorted by Name" << std::endl;
	std::cout << "5. Display list sorted by Grade" << std::endl;
	std::cout << "6. Exit" << std::endl;
	do {
		std::cin >> choice;
		if (choice.compare("1") != 0 && choice.compare("2") != 0
			&& choice.compare("3") != 0 && choice.compare("4") != 0
			&& choice.compare("5") != 0 && choice.compare("6") != 0) {
			std::cout << "Invalid Input. Re-enter:";
		}
		else {
			done = true;
		}
	} while (!done);
	return atoi(choice.c_str());
}

//Precondtion:
//	_ptr is an Array of Pointer of type student structure and it must not point to null
//	_size is bigger than 0
//	_low must be smaller than high
//Postcondtion:
//	_Sorted ptr by the student's identfication numbers in an ascending order
void studentDatabaseHelper::sortedByID(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}
	//pick the pivot
	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	//make Left< pivot and right> pivot
	int i = low, j = high;
	while (i <= j) {
		while ((*(ptr+i))->id< pivot->id) {
			i++;
		}
		while ((*(ptr + j))->id > pivot->id) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr+i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortedByID(ptr, size, low, j);
	}
	if (high > i) {
		sortedByID(ptr, size, i, high);
	}
}

//Precondtion:
//	_ptr is an Array of Pointer of type student structure and it must not point to null
//	_size is bigger than 0
//	_low must be smaller than high
//Postcondtion:
//	_Sorted ptr by the student's ages in an ascending order
void studentDatabaseHelper::sortedByAge(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}
	//pick the pivot
	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	//make Left< pivot and right> pivot
	int i = low, j = high;
	while (i <= j) {
		while ((*(ptr + i))->dob.daysBetween(pivot->dob)<0) {
			i++;
		}
		while ((*(ptr + j))->dob.daysBetween(pivot->dob)>0) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr + i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortedByAge(ptr, size, low, j);
	}
	if (high > i) {
		sortedByAge(ptr, size, i, high);
	}
}

//Precondtion:
//	_ptr is an Array of Pointer of type student structure and it must not point to null
//	_size is bigger than 0
//	_low must be smaller than high
//Postcondtion:
//	_Sorted ptr by the student's names in an ascending order
void studentDatabaseHelper::sortedByName(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}
	//pick the pivot
	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	//make Left< pivot and right> pivot
	int i = low, j = high;
	while (i <= j) {
		while (strcmp((*(ptr + i))->name, pivot->name)<0) {
			i++;
		}
		while (strcmp((*(ptr + j))->name, pivot->name)>0) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr + i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortedByName(ptr, size, low, j);
	}
	if (high > i) {
		sortedByName(ptr, size, i, high);
	}
}

//Precondtion:
//	_ptr is an Array of Pointer of type student structure and it must not point to null
//	_size is bigger than 0
//	_low must be smaller than high
//Postcondtion:
//	_Sorted ptr by the student's grades in a descending order
void studentDatabaseHelper::sortedByGrade(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}
	//pick the pivot
	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	//make Left< pivot and right> pivot
	int i = low, j = high;
	while (i <= j) {
		while ((*(ptr + i))->grade> pivot->grade) {
			i++;
		}
		while ((*(ptr + j))->grade < pivot->grade) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr + i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortedByGrade(ptr, size, low, j);
	}
	if (high > i) {
		sortedByGrade(ptr, size, i, high);
	}
}

//Precondtion:
//	_paramType: 1=Array of student structure, 2=Array of Pointers pointed to student structure
//	_ptr must be Array of student structure or Array of Pointers pointed to student structure
//	_size is bigger than 0
//Postcondtion:
//	_display all student informations
void studentDatabaseHelper::display(int paramType, void *ptr, int size) {
	struct student *temp1 = nullptr;
	struct student **temp2 = nullptr;
	std::printf("%-20s %-20s %-20s %-20s\n", "Student ID", "Name", "Birthday", "Grade");
	char s[20];
	switch (paramType) {
	case 1:
		temp1 = (struct student*)ptr;
		for (int i = 0; i < size; i++) {
			(temp1 + i)->dob.display(s);
			std::printf("%-20i %-20s %-20s %-20i\n", (temp1 + i)->id, (temp1 + i)->name, s, (temp1 + i)->grade);
		}
		break;
	case 2:
		temp2 = (struct student**)ptr;
		for (int i = 0; i < size; i++) {
			(*(temp2 + i))->dob.display(s);
			std::printf("%-20i %-20s %-20s %-20i\n", (*(temp2 + i))->id, (*(temp2 + i))->name, s, (*(temp2 + i))->grade);
		}
		break;
	default:
		break;
	}
}

//Precondtion:
//	_list: Array of student structure
//	_ptr: Array of pointer pointed to student structure
//	_size is bigger than 0
//Postcondtion:
//	_copied pointers from list into ptr
void studentDatabaseHelper::copyPointer(struct student *list, struct student **ptr, int size) {
	for (int i = 0; i < size; i++) {
		*(ptr + i) = list + i;
	}
}

