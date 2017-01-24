/*
 * TheTortoiseAndTheHare.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Sotheanith
 */
#include "hare.h"
#include "Tortoise.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std;

int menu();
void race();
int main() {
	srand((unsigned) time(0));
	int input = 0;
	do {
		input = menu();
		switch (input) {
		case 1:
			cout << "-Begin the race-" << endl;
			race();
			break;
		case 2:
			cout << "-Exiting-" << endl;
			break;
		}

	} while (input != 2);
	return 0;
}
;
int menu() {
	string str = "";
	while (str.compare("1") != 0 && str.compare("2") != 0) {
		//Menu
		cout << "1. Begin Race" << endl;
		cout << "2. Exit" << endl;
		cin >> str;
		//Input validation
		if (str.compare("1") != 0 && str.compare("2") != 0) {
			cout << "Invalid input. Please try again." << endl;
		}
	}
	return atoi(str.c_str());
}
void race() {
	Hare h;
	Tortoise t;
	int hPos = 0;
	int tPos = 0;
	//Begin the race
	cout << "BANG!!!!!" << endl;
	cout << "AND THEY'RE OFF !!!!!" << endl;
	for (int i = 1; i <= 70; i++) {
		//Move animals
		hPos = h.moveHare();
		tPos = t.moveTortoise();
		//Draw location
		for (int j = 1; j <= 70; j++) {
			if (hPos == tPos && hPos == j) {
				cout << "OUCH!!!";
			} else if (hPos == j || tPos == j) {
				if (hPos == j) {
					cout << "H";
				}
				if (tPos == j) {
					cout << "T";
				}
			} else {
				cout << "-";
			}
		}
		cout << "" << endl;
		if (hPos == 70 || tPos == 70) {
			break;
		}
	}
	//Win-Condition
	if (hPos == 70 && tPos == 70) {
		cout << "It's a tie." << endl;
	} else if (hPos == 70) {
		cout << "Hare wins. Yunch." << endl;
	} else if (tPos == 70) {
		cout << "TORTOISE WINS!!! YAY!!!" << endl;
	} else {
		cout << "No one finish the race." << endl;
	}
}

