/*
 * main.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: Sotheanith
 */
#include <iostream>
#include "CardDeck.h"
#include <string>
using namespace std;
void menu();
void displayCard(CardDeck&);
void getNewDeck(CardDeck&);
void shuffling(CardDeck&);
void playingWars(CardDeck&);

int main() {
	//Declaration of variable and object
	string c;
	CardDeck deck;
	cout << "---Welcome to the Game of War!!!---" << endl;
	//Loop though menu
	do {
		menu();
		cin >> c;
		if (c == "1") {
			cout << "-Getting new deck" << endl;
			getNewDeck(deck);

		} else if (c == "2") {
			cout << "-Showing all cards-" << endl;
			displayCard(deck);
		} else if (c == "3") {
			cout << "-Shuffling-" << endl;
			shuffling(deck);
		} else if (c == "4") {
			cout << "-Playing Wars-" << endl;
			cout << "There are " << deck.cardsLeft() << " cards in the deck."
					<< endl;
			playingWars(deck);
		} else if (c == "5") {
			cout << "-Exiting-" << endl;
		} else {
			cout << "Invalid Input. Please try again." << endl;
		}
	} while (c != "5");
	return 0;
}

void menu() {
	cout << "---Menu---" << endl;
	cout << "1. Get a new card deck" << endl;
	cout << "2. Show all cards in the deck" << endl;
	cout << "3. Shuffle" << endl;
	cout << "4. Play WAR!" << endl;
	cout << "5. Exit" << endl;
}
void displayCard(CardDeck &deck) {
	cout << "Cards remaining: " << deck.cardsLeft() << endl;
	for (int i = 0; i < 52; i++) {
		deck.displayCardAt(i);
	}

}
void getNewDeck(CardDeck &deck) {
	CardDeck tempDeck;
	deck = tempDeck;

}
void shuffling(CardDeck &deck) {
	deck.shuffle();
}
void playingWars(CardDeck &deck) {
	int pPlayer = 0;
	int pAi = 0;
	string input = "Y";
	cout << "Get ready to play two-card WAR!!!" << endl;
	cout << "There are " << deck.cardsLeft() << " cards in the deck." << endl;
	while (input.compare("Y") == 0) {
		//Used new deck when it's runnning low
		if (deck.cardsLeft() < 10) {
			cout << "Card running low. Getting a new shuffled deck." << endl;
			getNewDeck(deck);
			shuffling(deck);
			cout << "There are " << deck.cardsLeft() << " cards in the deck."
					<< endl;
		}
		//Dealing the card
		cout << "...dealing...." << endl;
		for (int i = 0; i < 2; i++) {
			cout << "One for you..." << endl;
			pPlayer += deck.deal();
			cout << "One for me" << endl;
			pAi += deck.deal();
		}
		cout << "You have " << pPlayer << " points" << endl;
		cout << "I have " << pAi << " points" << endl;
		//Calculate the win condition
		if (pPlayer == pAi) {
			cout << "Tie game - I challenge you again." << endl;
		} else if (pAi > pPlayer) {
			cout << "In your face! - I win!" << endl;
		} else {
			cout << "Congratulation! You won." << endl;
		}
		pPlayer = 0;
		pAi = 0;
		cout << "There are " << deck.cardsLeft() << " cards in the deck."
				<< endl;
		cout << "Wanna play again? (Y/N)" << endl;
		//Check for ending condition
		do {
			cin >> input;
			if (input.compare("N") == 0) {
				cout << "Thank you for playing." << endl;
				break;
			} else if (input.compare("Y") == 0) {
				//Nothing needed to be done here
			} else {
				cout << "Invalid Input. Please try again." << endl;
			}
		} while (input.compare("Y") != 0);
	}

}

