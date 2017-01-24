/*
 * Card.hpp
 *
 *  Created on: Sep 7, 2016
 *      Author: Sotheanith
 */

#ifndef CARD_H_
#define CARD_H_
#include <iostream>
#include <string>
using namespace std;
class Card {
private:
	char suit;
	int rank;
public:
	Card();
	Card(char s, int r);
	int getValue();
	void setValue(int r);
	void displayCard();
};
#endif /* CARD_H_ */
