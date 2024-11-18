#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Functions.h"
#include "numberWordle.h"
#include "mathsTest.h"
using namespace std;

int main()
{
	cout << " _ _ _ _____ __    _____ _____ _____ _____    _____ _____    _____ _____ _____ _____ _____ _____ _____    _____ _____ ____  _____  \n";
	cout << "| | | |   __|  |  |     |     |     |   __|  |_   _|     |  |     |  |  |  _  |   | |_   _|  |  |     |  |     |     |    \|   __| \n";
	cout << "| | | |   __|  |__|   --|  |  | | | |   __|    | | |  |  |  |  |  |  |  |     | | | | | | |  |  | | | |  |   --|  |  |  |  |   __| \n";
	cout << "|_____|_____|_____|_____|_____|_|_|_|_____|    |_| |_____|  |__  _|_____|__|__|_|___| |_| |_____|_|_|_|  |_____|_____|____/|_____| \n";
	cout << "                                                               |__|                                                                \n";
	char answer;
	while (true) {
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
			aboutUs();
		}
		else if (answer == '6') {
			cout << "Quitting...";
			return 0;
		}
		else {
			cout << "You selected '" << answer << "', which is not a valid option.\n";
			cout << "Would you like to try again? (Y/N): ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y') {
				cout << "\n\n";
				continue;
			}
			cout << "Exiting the program... Goodbye!\n";
			return 0;
		}
	}
}