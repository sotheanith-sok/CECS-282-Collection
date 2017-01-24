/*
 * Card.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: Sotheanith
 */
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

Card::Card() {
	suit = 'X';
	rank = 0;
}
Card::Card(char s, int r) {
	suit = s;
	rank = r;
}
int Card::getValue() {
	if (rank > 10) {
		return 10;
	}
	return rank;
}
void Card::setValue(int r) {
	rank = r;
}
void Card::displayCard() {
	//Get the value of the card
	string card = "     ";
	if (rank == 1) {
		card += "Ace";
	} else if (rank == 2) {
		card += "Two";
	} else if (rank == 3) {
		card += "Three";
	} else if (rank == 4) {
		card += "Four";
	} else if (rank == 5) {
		card += "Five";
	} else if (rank == 6) {
		card += "Six";
	} else if (rank == 7) {
		card += "Seven";
	} else if (rank == 8) {
		card += "Eight";
	} else if (rank == 9) {
		card += "Nine";
	} else if (rank == 10) {
		card += "Ten";
	} else if (rank == 11) {
		card += "Jack";
	} else if (rank == 12) {
		card += "Queen";
	} else if (rank == 13) {
		card += "King";
	} else {
		card += "Unknown value";
	}
	card += " of ";
	//Get the suit of the card
	if (suit == 'S') {
		card += "Spade";
	} else if (suit == 'H') {
		card += "Heart";
	} else if (suit == 'D') {
		card += "Diamond";
	} else if (suit == 'C') {
		card += "Club";
	} else {
		card += "Unknown Suit";
	}
	cout << card << endl;
}

