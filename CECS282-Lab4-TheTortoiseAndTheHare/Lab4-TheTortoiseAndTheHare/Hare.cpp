/*
 * Hare.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Sotheanith
 */

#include "Hare.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int Hare::moveHare() {
	int random = (rand() % 10) + 1;
	if (random > 8) {
		cout << "Hare: Sleeping" << endl;
		//Sleep:Doing nothing
	} else if (random > 6) {
		if (animal::getPos() + 9 > 70) {
			animal::setPos(70);
		} else {
			animal::setPos(animal::getPos() + 9);
		}
		cout << "Hare: Big hop" << endl;
	} else if (random > 5) {
		if (animal::getPos() - 12 < 1) {
			animal::setPos(1);
		} else {
			animal::setPos(animal::getPos() - 12);
		}
		cout << "Hare: Big slip" << endl;
	} else if (random > 2) {
		if (animal::getPos() + 1 > 70) {
			animal::setPos(70);
		} else {
			animal::setPos(animal::getPos() + 1);
		}
		cout << "Hare: Small hop" << endl;
	} else {
		if (animal::getPos() - 2 < 1) {
			animal::setPos(1);
		} else {
			animal::setPos(animal::getPos() - 2);
		}
		cout << "Hare: Small slip" << endl;
	}
	return animal::getPos();
}
