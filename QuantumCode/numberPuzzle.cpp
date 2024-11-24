#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "functions.h"
#include "numberPuzzle.h"
using namespace std;

// Defining color codes for console text
#define GREEN 2
#define DARKBLUE 1
#define RED 4
#define WHITE 7
#define GOLD 6
#define AQUA 3

// Function to validate input
bool isValid(string guess) {
    for (size_t i = 0; i < guess.size(); i++) {
        if (!isdigit(guess[i])) return false;
    }
    int num = stoi(guess);
    return num >= 1 && num <= 100;
}

void startNumberPuzzle() {
    while (true) {
        // Display title and rules
        setColor(AQUA);
        cout << "+--------------------------------------------------------------------------------+\n";
        cout << "|                                NUMBER PUZZLE                                   |\n";
        cout << "+--------------------------------------------------------------------------------+\n";

        setColor(GOLD);
        cout << "|                                   RULES                                        |\n";
        cout << "|  1. The game will choose a random number between 1 and 100.                    |\n";
        cout << "|  2. Guess the number. Hints will guide you (higher/lower).                     |\n";
        cout << "|  3. Keep guessing until correct.                                              |\n";
        cout << "|                              GOOD LUCK!                                       |\n";
        cout << "+--------------------------------------------------------------------------------+\n\n";

        // Generate random number
        srand((unsigned int)time(NULL));
        int number = (rand() % 100) + 1;
        string guess;
        
        // Game loop
        do {
            setColor(WHITE);
            cout << "Enter your guess (1-100): ";
            cin >> guess;

            while (!isValid(guess)) {
                cout << "Invalid guess. Try again (1-100): ";
                cin >> guess;
            }
            int guessInt = stoi(guess); // turns the string into integer
            
            if (guessInt > number) { // if the guess is higher display "guess lower!"
                setColor(RED);
                cout << "\n*********************************************\n";
                cout << "*                GUESS LOWER!               *\n";
                cout << "*********************************************\n\n";
            }
            else if (guessInt < number) { // if the guess is higher display "guess higher!"
                setColor(GREEN);
                cout << "\n*********************************************\n";
                cout << "*                GUESS HIGHER!              *\n";
                cout << "*********************************************\n\n";
            }
            else { // if the player has won display "you won!"
                setColor(GOLD);
                cout << "\n*********************************************\n";
                cout << "*                 YOU WON!                  *\n";
                cout << "*********************************************\n\n";
            }
        } while (stoi(guess) != number);

        // Ask if the player wants to play again
        setColor(WHITE);
        cout << "Do you want to play again? (Y/N): ";
        char answer;
        cin >> ws >> answer;
        if (tolower(answer) != 'y') {
            cout << "Returning to main menu...\n"; // if not return to the main menu
            break;
        }
    }
}
