#include "numberwordle.h"
#include <iostream>
#include <random>
using namespace std;

void startNumberWordle()
{
	cout << "                         ------------------------------------------------------------------                        \n";
	cout << "                        |                           Number Puzzle                          |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                      The Rules of the game are:                  |\n";
	cout << "                        |      A number in the range of 10000 to 99999 has been riddled    |\n";
	cout << "                        |	       A digit glowing in yellow means it is in the number   	|\n";
	cout << "                        |						but in the wrong spot.						|\n";
	cout << "                        |		   A digit glowing in green means it is in the number		|\n";
	cout << "                        |						and in the right spot.						|\n";
	cout << "                        |      A digit non-glowing digit means it is not in the number.    |\n";
	cout << "                        |																	|\n";
	cout << "                        |					  You have 5 tries to guess it.					|\n";
	cout << "                        |                            Good luck!                            |\n";
	cout << "                         ------------------------------------------------------------------                         \n";
	cout << '\n\n\n';
	//displaying rules
	int generatedNumber = generateNumber();
	int attempts = 5;
	int guess;
	int numsInRightSpot;
	int numsInWrongSpot;
	while(true){
		cout << "Type your guess : ";
		cin >> guess;
		while (!guessValid(guess)) {
			cout << "Your guess is not valid! Please try again.";
			cin >> guess;
		}
		checkForMatch(guess, generatedNumber, numsInRightSpot, numsInWrongSpot);
		attempts--;
		if (attempts == 0) {
			bool playAgain = false;
			cout << "You have lost!" << '\n' << "The right number was " << generatedNumber << '\n';
			cout << "Do you want to play again?(Y/N)";
			if (playAgain) {
				startNumberWordle();
			}
			else {
				cout << "Returning to main menu...";
				return;
			}
		}
		else {
			//Finish the code here!!!!!!!
		}
	}
}

int generateNumber()
{
	srand(time(nullptr));
	int number = (rand() % 90000) + 10000; // generating number in range [10000, 99999]
	return number;
}

int findNthDigit(int digit, int number)
{

	int last_digit = 0;
	for (int i = 0; i <= digit; i++) {
		last_digit = number % 10;			//getting the last digit of the number
		if (i == digit) return last_digit;	
		number = number / 10;				//deleting the last digit of the number
	}
	return last_digit;
}

bool guessValid(int guess)
{
	int firstDigit;
	int digitCount = 0;
	if (guess < 0 || guess == 0) return false;
	while (guess > 0) {
		guess = guess / 10;
		digitCount++;
		if (guess < 10 && guess > 0) firstDigit = guess;
	}
	return (digitCount == 5 && firstDigit != 0);
}

void checkForMatch(int n, int variant, int& rightSpot, int& wrongSpot)
{
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			if (findNthDigit(i, n) == findNthDigit(j, variant)) {
				if (i != j) {
					wrongSpot++;      // if the digit is in the number but in the wrong spot(i != j) it will be "yellow"
				}
				else {
					rightSpot++;	  // if the digit is in the number and in the right spot(i == j) it will be "green"
				}
			}
		}
	}
}