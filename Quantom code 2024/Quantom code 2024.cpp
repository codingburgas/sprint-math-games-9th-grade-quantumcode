#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Functions.h"
using namespace std;

int main()
{
	char answer;
	cout << "Welcome to QuantumCode" << '\n' << '\n';
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
			cout << "You selected '" << answer << "', which is not a valid option. ";
			cout << "Would you like to try again? (Y/N)";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				cout << '\n' << '\n';
				continue;
			}
			cout << "Quitting...";
			return 0;
		}
	}
}