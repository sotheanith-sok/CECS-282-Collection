/*
* main.cpp
*
*  Created on: October 10, 2016
*      Author: Sotheanith Sok
*/

#include <iostream>
#include "myDate.h"
int main() {
	myDate d1, d2(2, 2, 2016);
	std::cout << (d1 == d2) << std::endl;
	std::cout << (d1 != d2) << std::endl;
	std::cout << (d1 >= d2) << std::endl;
	std::cout << (d1 <= d2) << std::endl;
	std::cout << (d1 > d2) << std::endl;
	std::cout << (d1 < d2) << std::endl;
	return 0;
}