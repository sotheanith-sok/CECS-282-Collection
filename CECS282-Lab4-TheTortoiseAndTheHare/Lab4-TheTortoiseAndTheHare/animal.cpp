/*
 * animal.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Sotheanith
 */
#include "animal.h"
animal::animal() {
	pos = 1;
}
int animal::getPos() {
	return pos;
}
void animal::setPos(int pos) {
	this->pos = pos;
}

