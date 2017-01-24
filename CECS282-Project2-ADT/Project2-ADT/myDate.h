/*
 * myDate.h
 *
 *  Created on: Sep 21, 2016
 *      Author: Sotheanith Sok
 */

#ifndef MYDATE_H_
#define MYDATE_H_

class myDate {
private:
	int Month, Day, Year;
	double GregorianToJulian();
	void JulianToGregorian(double JD);
	int NumberOfDayInMonth(int M, int Y);
public:
	myDate();
	myDate(int M, int D, int Y);
	void display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(myDate D);
	int getMonth();
	int getDay();
	int getYear();
	int getYearOffset();
};

#endif /* MYDATE_H_ */
