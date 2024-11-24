#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "functions.h"
using namespace std;

void startNumberPuzzle() {

    setColor(3); // Aqua for the title
    cout << "+--------------------------------------------------------------------------------+\n";
    cout << "|                                NUMBER PUZZLE                                   |\n";
    cout << "+--------------------------------------------------------------------------------+\n";

    // Display rules
    setColor(6); // Gold for the rules
    cout << "|                                   RULES                                        |\n";
    cout << "|                                                                                |\n";
    cout << "|  1. The game will choose a random number between 1 and 100.                    |\n";
    cout << "|  2. You must guess the number by entering values.                              |\n";
    cout << "|  3. The system will give you hints:                                            |\n";
    cout << "|      - Guess higher if your guess is too low.                                  |\n";
    cout << "|      - Guess lower if your guess is too high.                                  |\n";
    cout << "|  4. Keep guessing until you find the correct number.                           |\n";
    cout << "|                                                                                |\n";
    cout << "|                              GOOD LUCK!                                        |\n";
    cout << "+--------------------------------------------------------------------------------+\n\n";

    // Random numbers
    srand((unsigned int)time(NULL));
    int number = (rand() % 100) + 1;
    int guess = 0;

    // Game loop
    do {
        setColor(7); // White for prompt
        cout << "Enter your guess (1-100): ";
        cin >> guess; //enter guess

        if (guess > number) {
            setColor(4); // when lower is going to be red
            cout << "\n*********************************************\n";
            cout << "*                GUESS LOWER!               *\n";
            cout << "*********************************************\n\n";
        }
        else if (guess < number) {
            setColor(2); // when higher is going to be green
            cout << "\n*********************************************\n";
            cout << "*                GUESS HIGHER!              *\n";
            cout << "*********************************************\n\n";
        }
        else {
            setColor(14); // When the player win is going to be yellow
            cout << "\n*********************************************\n";
            cout << "*                 YOU WON!                  *\n";
            cout << "*********************************************\n\n";
        }
    } while (guess != number); 
    cout << "\n*********************************************\n";
    cout << "*               CONGRATULATIONS!             *\n";
    cout << "*        DO YOU WANT TO PLAY AGAIN?(Y/N)      *\n";
    cout << "*********************************************\n\n";
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        startNumberPuzzle();
    }
    else {
        cout << "Returning to main menu...";
        return;
    }
}
