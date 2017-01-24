/**
 * myDate.h
 * 
 * Created on: Sep 21, 2016
 * Author: Sotheanith Sok
 */

#ifndef MYDATE_H_
#define MYDATE_H_
class myDate {
	//A myDate object is a date object contains various data including day, month, and year.
public:
	myDate();
	//Precondition:
	//	_none
	//Postcondtions:
	//	_initialize the date to May 11, 1959

	myDate(int M, int D, int Y);
	//Precondition:
	//	_none
	//Postcondtion:	
	//	_date will be initialize to a given date if it is after December 31, 1958 and it is a valid date
	//	_else date will be initialize to May 11, 1959

	void display(char s[]);
	//Precondition:
	//	_none
	//Postconditin:
	//	_copy a char array representing the date value stored in this object into the char array "s"

	void incrDate(int N);
	//Precondition:
	//	_N is positive integer
	//Postconditon:
	//	_increase the date by N days

	void decrDate(int N);
	//Precondtion:
	//	_N is positive integer
	//Postcondition:
	//	_decrease the date by N days
	
	int daysBetween(myDate D);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the the different of days between this object and D object
	//	_Postive value if D's date come before this's date
	//	_Negative value if this's date come before D's date

	int getMonth();
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the value of Month as a integer

	int getDay();
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the Day

	int getYear();
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the value of Year

	int getYearOffset();
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the number of day since the current Year begin

	static int NumberOfDayInMonth(int M, int Y);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the number of days in a specific month

	bool operator >(const myDate& d);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return true if this date come after d date else return false

	bool operator >=(const myDate& d);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return true if this date come after d date or this and d is the same date else return false

	bool operator <=(const myDate& d);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return true if this date come before d date or this and d is the same date else return false

	bool operator <(const myDate& d);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return true if this date come before d date else return false

	bool operator ==(const myDate& d);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return true if this date and d date is the same date else return false

	bool operator !=(const myDate& d);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return true if this date and d date is not the same date else return false

private:
	int Month, Day, Year;
	//Month: integer value of month. It can be any value from 1 to 12
	//Day: the current day of Month. The range of day is depended on the month
	//Year: the Year

	double GregorianToJulian();
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the Julian date of this object

	void JulianToGregorian(double JD);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Convert the date value of this object into a Gregorian date value represented by JD Julian Date
};

#endif
