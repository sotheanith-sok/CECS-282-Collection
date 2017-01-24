/**
* studentDatabaseHelper.h
*
* Created on: Oct 8, 2016
* Author: Sotheanith Sok
*/

#ifndef STUDENTDATABASEHELPER_H_
#define STUDENTDATABASEHELPER_H_
class studentDatabaseHelper{
	//studentDatabaseHelper contains static functions and algorithem neccessary for the functionality of the studentDatabase
public:
	static void initialization(struct student *list, int size);
	//Precondtion:
	//	_size must be 10
	//	_enough memory neccessary to store 10 student structures
	//Postcondtion:
	//	_intitalize student structure to a predetermine name, unique identification number, grade,
	//	and a date of birth between January 1, 1990 and December 31, 1994
	
	static int	menu();
	//Precondtion:
	//	_none
	//Postcondtion:
	//	_Return the valid option in which the user chose

	static void sortedByID(struct student **ptr, int size, int low, int high);
	//Precondtion:
	//	_ptr is an Array of Pointer of type student structure and it must not point to null
	//	_size is bigger than 0
	//	_low must be smaller than high
	//Postcondtion:
	//	_Sorted ptr by the student's identfication numbers in an ascending order

	static void sortedByAge(struct student **ptr, int size, int low, int high);
	//Precondtion:
	//	_ptr is an Array of Pointer of type student structure and it must not point to null
	//	_size is bigger than 0
	//	_low must be smaller than high
	//Postcondtion:
	//	_Sorted ptr by the student's ages in an ascending order

	static void sortedByName(struct student **ptr, int size, int low, int high);
	//Precondtion:
	//	_ptr is an Array of Pointer of type student structure and it must not point to null
	//	_size is bigger than 0
	//	_low must be smaller than high
	//Postcondtion:
	//	_Sorted ptr by the student's names in an ascending order

	static void sortedByGrade(struct student **ptr, int size, int low, int high);
	//Precondtion:
	//	_ptr is an Array of Pointer of type student structure and it must not point to null
	//	_size is bigger than 0
	//	_low must be smaller than high
	//Postcondtion:
	//	_Sorted ptr by the student's grades in a descending order

	static void display(int paramType, void *ptr, int size);
	//Precondtion:
	//	_paramType: 1=Array of student structure, 2=Array of Pointers pointed to student structure
	//	_ptr must be Array of student structure or Array of Pointers pointed to student structure
	//	_size is bigger than 0
	//Postcondtion:
	//	_display all student informations

	static void copyPointer(struct student *list,struct student **ptr,int size);
	//Precondtion:
	//	_list: Array of student structure
	//	_ptr: Array of pointer pointed to student structure
	//	_size is bigger than 0
	//Postcondtion:
	//	_copied pointers from list into ptr

};
#endif

