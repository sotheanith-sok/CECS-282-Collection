/*
 * myDate.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Sotheanith Sok
 */
#include <string>
#include <iostream>
#include <cmath>
#include "myDate.h"

using namespace std;

//Default Constructor
myDate::myDate() {
	Month = 5, Day = 11, Year = 1959;
}

//Overloaded Constructor
myDate::myDate(int M, int D, int Y) {
	if (M > 0 && M < 13 && D > 0 && D <= NumberOfDayInMonth(M, Y)
			&& Y >= 1959) {
		Month = M, Day = D, Year = Y;
	} else {
		Month = 5, Day = 11, Year = 1959;
	}
}

//Use to display the date
void myDate::display() {
	string s;
	switch (Month) {
	case 1:
		s += "January";
		break;
	case 2:
		s += "February";
		break;
	case 3:
		s += "March";
		break;
	case 4:
		s += "April";
		break;
	case 5:
		s += "May";
		break;
	case 6:
		s += "June";
		break;
	case 7:
		s += "July";
		break;
	case 8:
		s += "August";
		break;
	case 9:
		s += "September";
		break;
	case 10:
		s += "October";
		break;
	case 11:
		s += "November";
		break;
	case 12:
		s += "December";
		break;
	}
	cout << s << " " << Day << ", " << Year;
}

//Use to increase date
void myDate::incrDate(int N) {
	double JD = GregorianToJulian() + N;
	JulianToGregorian(JD);
}

//Use to decrease date
void myDate::decrDate(int N) {
	double JD = GregorianToJulian() - N;
	JulianToGregorian(JD);
}

//Find the difference between two dates
int myDate::daysBetween(myDate D) {
	return abs(GregorianToJulian() - D.GregorianToJulian());
}

//Get month
int myDate::getMonth() {
	return Month;
}

//Get day
int myDate::getDay() {
	return Day;
}

//Get year
int myDate::getYear() {
	return Year;
}

//Get how many has it been since the beginning of the year
int myDate::getYearOffset() {
	return abs(GregorianToJulian() - myDate(1, 1, Year).GregorianToJulian());
}

//Use to convert Gregorian to Julian
double myDate::GregorianToJulian() {
	return (367 * Year) - (trunc((7 * (Year + trunc((Month + 9) / 12))) / 4))
			+ trunc(275 * Month / 9) + Day + 1721013.5;
}

//Use to convert from Gregorian to Julian
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

//Use to find the number of day in a certain month
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
