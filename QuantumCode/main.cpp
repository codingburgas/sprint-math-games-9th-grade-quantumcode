#include <iostream>
#include <windows.h>
#include <conio.h>
#include "functions.h"
#include "numberWordle.h"
#include "guessTheNumber.h"
#include "mathsTest.h"
using namespace std;

int main()
{
	char answer;
	
	while (true) {
		system("cls"); // clears the screen when selected
		displayMenu();
		cin >> answer;
		if (answer == '1') {
			startNumberWordle(); 
		}
		else if (answer == '2') {
			startGuessTheNumber();
		}
		else if (answer == '3') {
			startNumberPuzzle();
		}
		else if (answer == '4') {
			startMathsTest();
		}
		else if (answer == '5') {
			aboutUs(); //choices
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