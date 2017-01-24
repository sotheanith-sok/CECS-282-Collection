#include "student.h"
#include "myDate.h"
#include <cstring>
#include <string>
#include <iostream>


int main() {
	struct student list[3];
	
	//Initialize name
	strcpy_s(list[0].name, "Johnny");
	strcpy_s(list[1].name, "Mark");
	strcpy_s(list[2].name, "Locus");

	//Initialize id
	list[0].id = 452;
	list[1].id = 900;
	list[2].id = 743;

	//Initialize grade
	list[0].grade = 56;
	list[1].grade = 78;
	list[2].grade = 100;

	//Initialize date of birth
	list[0].dob = myDate(1, 25, 1990);
	list[1].dob = myDate(7, 1, 1992);
	list[2].dob = myDate(3, 19, 1991);

	//Print out
	char s[50];
	std::printf("%-20s %-20s %-20s %-20s\n", "Student ID", "Name", "Birthday", "Grade");
	for (int i = 0; i < 3; i++) {
		list[i].dob.display(s);
		std::printf("%-20i %-20s %-20s %-20i\n", list[i].id, list[i].name, s, list[i].grade);
	}
	return 0;
}	