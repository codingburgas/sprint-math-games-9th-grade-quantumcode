#include "numberwordle.h"
#include <iostream>
#include <random>
#include <string>
#include "functions.h"
using namespace std;

// Defining color codes for console text
#define GREEN 2
#define DARKBLUE 1
#define RED 4
#define WHITE 7
#define GOLD 6
#define AQUA 3

// Function to start the Number Wordle game
void startNumberWordle()
{
    setColor(AQUA);
    cout << "====================================================================\n";
    cout << "|                        NUMBER PUZZLE GAME                         |\n";
    cout << "====================================================================\n";
    setColor(WHITE);

    // Displaying the game rules
    setColor(GREEN);
    cout << "Game Rules:\n";
    cout << "  - A 5-digit number between 10000 and 99999 is hidden.\n";
    cout << "  - You have 5 attempts to guess it.\n";
    cout << "  - Each guess will give you feedback:\n";
    cout << "    - A digit glowing in \033[1;32mgreen\033[0m means the digit is in the correct position.\n";
    cout << "    - A digit glowing in \033[1;33myellow\033[0m means it is in the number but in the wrong position.\n";
    cout << "    - A digit with no glow means it is not in the number at all.\n";
    cout << "====================================================================\n";

    int generatedNumber = generateNumber();
    int attempts = 6;
    string guess;
    bool guessTaken = false;
    // Starting a loop and counting the attempts
    while (true) {
        if (attempts < 5) guessTaken = true;
        attempts--;
        char answer;
        // Check if the input is a valid number

        if (attempts == 0) { // If the player has lost
            setColor(RED);
            cout << "\nYou have lost! The right number was " << generatedNumber << endl;
            setColor(WHITE);
            cout << "Would you like to try again? (Y/N): ";
            cin >> answer;
            if (answer == 'Y' || answer == 'y') {
                startNumberWordle(); // Restart the game
            }
            else {
                setColor(GOLD);
                cout << "Returning to the main menu...\n"; // else return to the main menu
                return;
            }
        }
        else if (attempts >= 0) { // If the player still has attempts left
            setColor(WHITE);
            cout << "\nYou have " << attempts << " attempts left.\n";
            cout << "Type your guess: ";
            cin >> guess;
            
            while (!guessValid(guess)) {
                setColor(RED);
                cout << "Your guess is not valid! Please try again (10000-99999): ";
                setColor(WHITE);
                cin >> guess; // If the guess is not valid, ask again
            }

            // Tell if the player has found any digits
            for (int i = 4; i > -1; i--) {
                bool flag = false;
                if (findNthDigit(i, stoi(guess)) == findNthDigit(i, generatedNumber)) {
                    setColor(GREEN);
                    cout << findNthDigit(i, stoi(guess)); // Green if the digit is in the right place
                    flag = true;
                }
                if (flag) continue;

                // Check for yellow (wrong place but in the number)
                for (int j = 3; j > -1; j--) {
                    if (findNthDigit(i, stoi(guess)) == findNthDigit(j, generatedNumber) && i != j) {
                        setColor(GOLD);
                        cout << findNthDigit(i, stoi(guess)); // Yellow if the digit is in the number but wrong place
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    setColor(WHITE);
                    cout << findNthDigit(i, stoi(guess)); // White if the digit is not in the number
                }
            }
        }

        if (stoi(guess) == generatedNumber) { // If the player has won
            setColor(GREEN);
            cout << "\nYou have won! Congratulations!\n";
            setColor(WHITE);
            cout << "Would you like to try again? (Y/N): ";
            cin >> answer;
            if (answer == 'Y' || answer == 'y') {
                startNumberWordle(); // Restart the game
            }
            else {
                setColor(GOLD);
                cout << "Returning to the main menu...\n"; // else return to the main menu
                return;
            }
        }
    }
}

// Function to generate a random 5-digit number between 10000 and 99999
int generateNumber()
{
    srand(time(nullptr));
    return (rand() % 90000) + 10000;
}

// Function to extract the Nth digit from a number
int findNthDigit(int digit, int number)
{
    int last_digit = 0;
    for (int i = 0; i <= digit; i++) {
        last_digit = number % 10; // Getting the last digit of the number
        if (i == digit) return last_digit;
        number = number / 10; // Deleting the last digit of the number
    }
    return last_digit;
}

// Function to check if a guess is a valid 5-digit number
bool guessValid(string guess)
{
    bool flag = false;
    for (char& element : guess) {
        if (!isdigit(element)) flag = true;
    }
    if (flag) {
        bool flag2 = false;
        int counter = 0;
        while (flag) {
            guess.clear();
            setColor(RED);
            cout << "Invalid guess! Please enter a number between 10000 - 99999: " << '\n';
            setColor(WHITE);
            cin >> guess;
            for (char& element : guess) {
                if (isdigit(element)) {
                    counter++;
                }
                if (counter == guess.size()) flag2 = true;
            }
            if (flag2) flag = false;
        }
    }
    int firstDigit;
    int digitCount = 0;
    int num = stoi(guess);
    if (num < 0 || num == 0) return false;
    while (num > 0) {
        num = num / 10;
        digitCount++;
        if (num < 10 && num > 0) firstDigit = num;
    }

    return (digitCount == 5 && firstDigit != 0); // Valid if it's a 5-digit number with no leading zero
}
