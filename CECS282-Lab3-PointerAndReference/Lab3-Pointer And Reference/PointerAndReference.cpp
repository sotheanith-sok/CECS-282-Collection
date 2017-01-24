/*
* Lab3.cpp
*
* Created on: Sept 11, 2016
* Author: Sotheanith Sok
*/

#include <iostream>
using namespace std;

void integerCalc(int a, int b, int& c, int& d);
void integerCalc(int a, int b, int* c, int* d);

int main() {
	int a;
	int b;
	int c;
	int d;
	//Get Input
	cout << "Please enter the first number." << endl;
	cin >> a;
	cout << "Please enter the second number." << endl;
	cin >> b;
	integerCalc(a, b, c, d);
	integerCalc(a, b, &c, &d);
	return 0;
}
void integerCalc(int a, int b, int& c, int& d) {
	c = a / b;
	d = a % b;
	cout << "-Pass by Reference-" << endl;
	cout << "First Values: " << a << endl;
	cout << "Second Values: " << b << endl;
	cout << "Result: " << c << endl;
	cout << "Remainder: " << d << endl;
}
void integerCalc(int a, int b, int* c, int* d) {
	*c = a / b;
	*d = a % b;
	cout << "-Pass by Pointer-" << endl;
	cout << "First Values: " << a << endl;
	cout << "Second Values: " << b << endl;
	cout << "Result: " << *c << endl;
	cout << "Remainder: " << *d << endl;
}
