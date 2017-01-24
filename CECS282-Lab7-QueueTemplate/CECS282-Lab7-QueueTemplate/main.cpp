#include "Queue.h"
#include <iostream>
#include <string>
//============================================================================
// Name        : main.cpp
// Author      : Sotheanith Sok
// Version     : 1.0
// Description : This main is used to test queue template
//============================================================================
int main() {
	Queue <std::string, 5> q;
	//Test empty(). 
	std::cout << "Test empty(). Expected 1" << std::endl;
	std::cout << q.empty() << std::endl;

	//Test push().
	q.push("Apple");
	q.push("Orange");
	q.push("Grape");
	q.push("Strawberry");
	q.push("Blueberry");

	//Test pop(). Expected "Apple"
	std::cout << "Test pop(). Expected \"Apple\"" << std::endl;
	std::cout << q.pop() << std::endl;
	
	//Test size(). Expected 4
	std::cout << "Test size(). Expected 4" << std::endl;
	std::cout << q.size() << std::endl;

	//Test getFront(). Expected "Orange"
	std::cout << "Test getFront(). Expected \"Orange\"" << std::endl;
	std::cout << q.getFront() << std::endl;

	//Test getBack(). Expected "Blueberry"
	std::cout << "Test getBack(). Expected \"Blueberry\"" << std::endl;
	std::cout << q.getBack() << std::endl;
	return 0;
}