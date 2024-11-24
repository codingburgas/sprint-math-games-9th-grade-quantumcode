#include <iostream>
#include <windows.h>
#include <conio.h>
#include "functions.h"
#include "numberWordle.h"
#include "guessTheNumber.h"
#include "mathsTest.h"
#include "numberPuzzle.h"

using namespace std;

int main() {
    char answer;

    while (true) {
        system("cls"); // Clears the screen
        displayMenu(); // Displays menu
        cin >> answer;

        if (answer == '1') {
            startNumberWordle();  // Start Number Wordle
        }
        else if (answer == '2') {
            startGuessTheNumber(); // Start Guess the Number
        }
        else if (answer == '3') {
            startNumberPuzzle(); // Start Number Puzzle
        }
        else if (answer == '4') {
            startMathsTest(); // Start Maths Test
        }
        else if (answer == '5') {
            aboutUs(); // Display About Us
            char readAnswer;
            cout << "\n\nHave you read it? (Y/N): ";
            cin >> readAnswer;

            while (!(readAnswer == 'y' || readAnswer == 'Y')) {
                cout << "\n\nHave you read it? (Y/N): ";
                cin >> readAnswer;
            }
        }
        else if (answer == '6') {
            cout << "Quitting...";
            return 0; // Stops the program
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
            return 0; // Stops the program
        }
    }
}
