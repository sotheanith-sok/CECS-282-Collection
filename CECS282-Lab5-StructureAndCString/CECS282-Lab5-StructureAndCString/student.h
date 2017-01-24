/*
* student.h
*
*  Created on: Sep 28, 2016
*      Author: Sotheanith
*/

#ifndef STUDENT_H_
#define STUDENT_H_

#include <cstring>
#include "myDate.h"

struct student {
	// student structure contains informations related to a student

	char name[50];
	// name: the name of the student
	int id;
	// id: a unique identification number of the student

	int grade;
	// grade: the grade of the student

	myDate dob;
	// dob: the date of birth of the student
};

#endif /* STUDENT_H_ */
