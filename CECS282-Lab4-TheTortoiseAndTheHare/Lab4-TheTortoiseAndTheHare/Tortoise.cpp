/*
 * Tortoise.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Sotheanith
 */

#include <cstdlib>
#include <iostream>
#include "Tortoise.h"
using namespace std;
int Tortoise::moveTortoise() {
	int random = (rand() % 10) + 1;
	if (random > 8) {
		if (animal::getPos() < 1) {
			animal::setPos(1);
		} else {
			animal::setPos(animal::getPos() - 6);
		}
		cout << "Tortoise: Slip" << endl;
	} else if (random > 5) {
		if (animal::getPos() + 1 > 70) {
			animal::setPos(70);
		} else {
			animal::setPos(animal::getPos() + 1);
		}
		cout << "Tortoise: Slow plod" << endl;
	} else {
		if (animal::getPos() + 3 > 70) {
			animal::setPos(70);
		} else {
			animal::setPos(animal::getPos() + 3);
		}
		cout << "Tortoise: Fast plod" << endl;
	}
	return animal::getPos();
}

