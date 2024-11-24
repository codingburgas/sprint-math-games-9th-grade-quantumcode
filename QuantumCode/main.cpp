#include <iostream>
#include <windows.h>
#include <conio.h>
#include "functions.h"
#include "numberWordle.h"
#include "guessTheNumber.h"
#include "mathsTest.h"
#include "numberPuzzle.h"
using namespace std;

int main()
{
	char answer;
	
	while (true) {
		system("cls"); // clears the screen when selected
		displayMenu(); //displays menu
		cin >> answer;
		if (answer == '1') {
			startNumberWordle();  //function to start number wordle
		}
		else if (answer == '2') {
			startGuessTheNumber(); //function to start guessing the number
		}
		else if (answer == '3') {
			startNumberPuzzle(); //function to start number puzzle
		}
		else if (answer == '4') {
			startMathsTest(); //function to start maths test
		}
		else if (answer == '5') {
			aboutUs(); //to display about us info
		}
		else if (answer == '6') {
			cout << "Quitting...";
			return 0; //stops the program
		}
		else {
			cout << "You selected '" << answer << "', which is not a valid option.\n"; //When selected a non-valid answer
			cout << "Would you like to try again? (Y/N): ";
			cin >> answer; 
			if (answer == 'Y' || answer == 'y') {
				cout << "\n\n";
				continue; 
			}
			cout << "Exiting the program... Goodbye!\n";
			return 0; //stops the program
		}
	}
}