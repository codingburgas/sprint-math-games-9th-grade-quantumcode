#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void startNumberPuzzle() {

	cout << "                         ------------------------------------------------------------------ \n";
	cout << "                        |                           Number Puzzle                          |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                      The Rules of the game are:                  |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |   The game will chose a random number and you have to guess it.  |\n";
	cout << "                        |    System will give you advices for guessing higher or lower.    |\n";
	cout << "                        |              The number X ranges from 0 to 100.                  |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                  Keep guessing until you won.                    |\n";
	cout << "                        |                            Good luck!                            |\n";
	cout << "                         ------------------------------------------------------------------ \n";







	srand((unsigned int)time(NULL));
	int number = (rand() % 100) + 1;
	int guess = 0;

	do {

		cout << "Enter Guess (1-100):";
		cin >> guess;

		if (guess > number)
			cout << "Guess lower!" << endl;
		else if (guess < number)
			cout << "Guess higher!" << endl;
		else
			cout << "You won!" << endl;


	} while (guess != number);
}