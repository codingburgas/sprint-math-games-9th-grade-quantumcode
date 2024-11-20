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
	cout << "                        |                                                                  |\n";
	cout << "                        |  A number in the range of 10000 to 99999 has been riddled        |\n";
	cout << "                        |  A digit glowing in yellow means it is in the number             |\n";
	cout << "                        |  There is a text that you have to read carefully.                |\n";
	cout << "                        |  but in the wrong spot.                                          |\n";
	cout << "                        |  A digit glowing in green means it is in the number              |\n";
	cout << "                        |  and in the right spot.                                          |\n";
	cout << "                        |  A non-glowing digit means it is not in the number.              |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                      You have 5 tries to guess it.               |\n";
	cout << "                        |                            Good luck!                            |\n";
	cout << "                         ------------------------------------------------------------------                         \n";
	//displaying rules
	int generatedNumber = generateNumber();
	int attempts = 5;
	int guess;
	bool guessTaken = false;
	while(true){
		cout << generatedNumber;
		if (attempts < 5) guessTaken = true;
		attempts--;
		char answer;
		if (guessTaken && attempts >= 0) {
			if (guess == generatedNumber) {   //if the player has won asking if they want to play again
				cout << "You have won!" << '\n' << "Would you like to try again?(Y/N)";
				cin >> answer;
				if (answer == 'Y' || answer == 'y') {
					startNumberWordle(); // if the player wants to play again restarting the game
				}
				else {
					cout << "Returning to main menu...";
					return; // returning to the main menu if the player does not want to play again
				}
			}
		}
		else if (attempts < 0) { //if the player has lost displaying the right number
			cout << '\n' << "You have lost!" << '\n' << "The right number was " << generatedNumber << '\n';
			cout << "Would you like to try again?(Y/N)"; // asking if they to play again
			cin >> answer;
			if (answer == 'Y' || answer == 'y') {
				startNumberWordle();
			}
			else {
				cout << "Returning to main menu...";
				return;
			}
		}
		else if(attempts != 0){ //if the player has not guessed the number nor won, the game continues
			cout << '\n' << "Type your guess : ";
			cin >> guess;
			while (!guessValid(guess)) {
				cout << "Your guess is not valid! Please try again.(10000-99999) : ";
				cin >> guess; // if the guess is not valid ask the user to try again
			}
			for (int i = 4; i > -1; i--){
				bool flag = false;
				if (findNthDigit(i, guess) == findNthDigit(i, generatedNumber)) {
						cout << "\033[32m" << findNthDigit(i, guess) << "\033[0m";
						//display that the digit is in the right place(green)
						flag = true; //the flag shows that the number was found
				}
				if (flag) continue; 
				for (int j = 3; j > -1; j--) {
					if (findNthDigit(i, guess) == findNthDigit(j, generatedNumber) && i != j) {

						cout << "\033[33m" << findNthDigit(i, guess) << "\033[0m";
						//display that the digit is in the wrong place but in the number(yellow)
						flag = true;
						break;

					}
				}
				if(!flag) cout << "\033[0m" << findNthDigit(i, guess);
				//if the digit is not in the word display it as grey
			}
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
		//checking if the number is valid
	}
	return (digitCount == 5 && firstDigit != 0);
	// if the number is 5-digit and the first digit is not a 0 the number is valid
}