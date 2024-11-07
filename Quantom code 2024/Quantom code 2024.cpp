#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Functions.h"
using namespace std;

int main()
{
	char answer;
	cout << "Welcome to QuantumCode" << '\n';
	while (true) {
		cout << "Chose what you want to do : " << '\n';
		cout << "1. Equation wordle" << '\n' << "2. Game" << '\n' << "3. Game" << '\n' << "4. Game" << '\n';
		cout << "5. About us" << '\n' << "6. Quit" << '\n';
		cin >> answer;
		if (answer == '1') {
			startEquationWordle();
		}
		else if (answer == '2') {
			startGame();
		}
		else if (answer == '3') {
			startGame();
		}
		else if (answer == '4') {
			startGame();
		}
		else if (answer == '5') {
			startGame();
		}
		else if (answer == '5') {
			aboutUs();
		}
		else if (answer == '6') {
			cout << "Quitting...";
			return 0;
		}
		else {
			cout << "You selected '" << answer << "', which is not a valid option.";
			cout << "Would you like to try again? (Y/N)";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				std::cout << '\n' << '\n';
				continue;
			}
			std::cout << "Quitting...";
			return 0;
		}
	}
}