/*
 * CardDeck.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: Sotheanith
 */
#include <cstdlib>
#include <ctime>
#include "CardDeck.h"
#include "Card.h"

CardDeck::CardDeck() {
	char suit[4] = { 'S', 'H', 'D', 'C' };
	int c = 0;
	//Initialize the deck
	for (int cout = 0; cout < 52;) {
		for (int i = 1; i < 14; i++) {
			deck[cout] = Card(suit[c], i);
			cout++;
		}
		c++;
	}
}

void CardDeck::displayCardAt(int x) {
	if (deck[x].getValue() != 0) {
		deck[x].displayCard();
	}
}
int CardDeck::deal() {
	int values;
	for (int i = 0; i < 52; i++) {
		if (deck[i].getValue() != 0) {
			deck[i].displayCard();
			values = deck[i].getValue();
			deck[i].setValue(0);
			return values;
		}
	}
	return -1;
}
int CardDeck::cardsLeft() {
	int cout = 0;
	for (int i = 0; i < 52; i++) {
		if (deck[i].getValue() != 0) {
			cout++;
		}
	}
	return cout;
}
void CardDeck::shuffle() {
	srand((unsigned) time(0));
	for (int i = 0; i < 52; i++) {
		int j = (rand() % 52);
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

