/*
 * myDate.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Sotheanith Sok
 */
#include <cstring>
#include <iostream>
#include <cmath>
#include "myDate.h"

using namespace std;

//Precondition:
//	_none
//Postcondtions:
//	_initialize the date to May 11, 1959
myDate::myDate() {
	Month = 5, Day = 11, Year = 1959;
}

//Precondition:
//	_none
//Postcondtion:	
//	_date will be initialize to a given date if it is after December 31, 1958 and it is a valid date
//	_else date will be initialize to May 11, 1959
myDate::myDate(int M, int D, int Y) {
	if (M > 0 && M < 13 && D > 0 && D <= NumberOfDayInMonth(M, Y)
			&& Y >= 1959) {
		Month = M, Day = D, Year = Y;
	} else {
		Month = 5, Day = 11, Year = 1959;
	}
}

//Precondition:
//	_none
//Postconditin:
//	_copy a char array representing the date value stored in this object into the char array "s"
void myDate::display(char f[]) {
	char s[20];
	switch (Month) {
	case 1:
		strcpy_s(s, "January");
		break;
	case 2:
		strcpy_s(s, "February");
		break;
	case 3:
		strcpy_s(s, "March");
		break;
	case 4:
		strcpy_s(s, "April");
		break;
	case 5:
		strcpy_s(s, "May");
		break;
	case 6:
		strcpy_s(s, "June");
		break;
	case 7:
		strcpy_s(s, "July");
		break;
	case 8:
		strcpy_s(s, "August");
		break;
	case 9:
		strcpy_s(s, "September");
		break;
	case 10:
		strcpy_s(s, "October");
		break;
	case 11:
		strcpy_s(s, "November");
		break;
	case 12:
		strcpy_s(s, "December");
		break;
	}
	char day[15];
	sprintf_s(day, " %d, %d", Day, Year);
	strcat_s(s, sizeof s, day);
	strcpy_s(f,sizeof s, s);
}

//Precondition:
//	_N is positive integer
//Postconditon:
//	_increase the date by N days
void myDate::incrDate(int N) {
	double JD = GregorianToJulian() + N;
	JulianToGregorian(JD);
}

//Precondtion:
//	_N is positive integer
//Postcondition:
//	_decrease the date by N days
void myDate::decrDate(int N) {
	double JD = GregorianToJulian() - N;
	JulianToGregorian(JD);
}

//Precondtion:
//	_none
//Postcondition:
//	_Return the the different of days between this object and D object
//	_Postive value if D's date come before this's date
//	_Negative value if this's date come before D's date
int myDate::daysBetween(myDate D) {
	return (GregorianToJulian() - D.GregorianToJulian());
}

//Precondtion:
//	_none
//Postcondition:
//	_Return the value of Month as a integer
int myDate::getMonth() {
	return Month;
}

//Precondtion:
//	_none
//Postcondition:
//	_Return the Day
int myDate::getDay() {
	return Day;
}

//Precondtion:
//	_none
//Postcondition:
//	_Return the value of Year
int myDate::getYear() {
	return Year;
}

//Precondtion:
//	_none
//Postcondition:
//	_Return the number of day since the current Year begin
int myDate::getYearOffset() {
	return abs(GregorianToJulian() - myDate(1, 1, Year).GregorianToJulian());
}

//Precondtion:
//	_none
//Postcondition:
//	_Return the number of days in a specific month
double myDate::GregorianToJulian() {
	return (367 * Year) - (trunc((7 * (Year + trunc((Month + 9) / 12))) / 4))
			+ trunc(275 * Month / 9) + Day + 1721013.5;
}

///Precondtion:
//	_none
//Postcondition:
//	_Return the Julian date of this object
void myDate::JulianToGregorian(double JD) {
	int L = JD + 68569 + 1;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	Year = I;
	Month = J;
	Day = K;
}

//Precondtion:
//	_none
//Postcondition:
//	_Convert the date value of this object into a Gregorian date value represented by JD Julian Date
int myDate::NumberOfDayInMonth(int Month, int Year) {
	switch (Month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		//Check for leap year
		if (Year % 4 != 0) {
			return 28;
		} else if (Year % 400 == 0) {
			return 29;
		} else if (Year % 100 == 0) {
			return 28;
		} else {
			return 29;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 0;
	}
}

//Precondtion:
//	_none
//Postcondition:
//	_Return true if this date come after d date else return false
bool myDate::operator >(const myDate& d) {
	if (this->daysBetween(d) > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//Precondtion:
//	_none
//Postcondition:
//	_Return true if this date come after d date or this and d is the same date else return false
bool myDate::operator >=(const myDate& d) {
	if (this->daysBetween(d) >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//Precondtion:
//	_none
//Postcondition:
//	_Return true if this date come before d date or this and d is the same date else return false
bool myDate::operator <=(const myDate& d) {
	if (this->daysBetween(d) <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//Precondtion:
//	_none
//Postcondition:
//	_Return true if this date come before d date else return false
bool myDate::operator <(const myDate& d) {
	if (this->daysBetween(d) < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//Precondtion:
//	_none
//Postcondition:
//	_Return true if this date and d date is the same date else return false
bool myDate::operator ==(const myDate& d) {
	if (this->daysBetween(d) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//Precondtion:
//	_none
//Postcondition:
//	_Return true if this date and d date is not the same date else return false
bool myDate::operator !=(const myDate& d) {
	if (this->daysBetween(d) != 0) {
		return 1;
	}
	else {
		return 0;
	}
}