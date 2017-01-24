/*
 * CardDeck.h
 *
 *  Created on: Sep 7, 2016
 *      Author: Sotheanith
 */

#ifndef CARDDECK_H_
#define CARDDECK_H_
#include "Card.h"
class CardDeck {
private:
	Card deck[52];
public:
	CardDeck();
	void displayCardAt(int x);
	int deal();
	int cardsLeft();
	void shuffle();
};
#endif /* CARDDECK_H_ */
