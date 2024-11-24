#include "Functions.h"
#include <iostream>
#include <Windows.h>
using namespace std;
#define GREEN 2
#define DARKBLUE 1
#define RED 4
#define WHITE 7
#define GOLD 6
#define AQUA 3
// define the colors, with their number
void setColor(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
	else
	{
		setColor(color);
	}
}


void aboutUs(){
	cout << "                         ------------------------------------------------------------------                        \n";
	cout << "                        |                           TEMPLATE                               |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                      The Rules of the game are:                  |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |  There is a text that you have to read carefully.                |\n";
	cout << "                        |  When you read the text, you have to find the number 'X'.        |\n";
	cout << "                        |  When you find the number X, please only answer with that        |\n";
	cout << "                        |  number.                                                         |\n";
	cout << "                        |  You have 3 tries to find the number.                            |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                            Good luck!                            |\n";
	cout << "                         ------------------------------------------------------------------                         \n";
}

void displayMenu()
{
	cout << " _ _ _ _____ __    _____ _____ _____ _____    _____ _____    _____ _____ _____ _____ _____ _____ _____    _____ _____ ____  _____  \n";
	cout << "| | | |   __|  |  |     |     |     |   __|  |_   _|     |  |     |  |  |  _  |   | |_   _|  |  |     |  |     |     |    \|   __| \n";
	cout << "| | | |   __|  |__|   --|  |  | | | |   __|    | | |  |  |  |  |  |  |  |     | | | | | | |  |  | | | |  |   --|  |  |  |  |   __| \n";
	cout << "|_____|_____|_____|_____|_____|_|_|_|_____|    |_| |_____|  |__  _|_____|__|__|_|___| |_| |_____|_|_|_|  |_____|_____|____/|_____| \n";
	cout << "                                                               |__|                                                                \n";
	//welcome message
	setColor(GOLD); //the color of the text
	cout << "Please choose an option from the menu below:\n";
	cout << "---------------------------------\n";
	cout << "1. Play Number Wordle\n";
	cout << "2. Play Guess the Number\n";
	cout << "3. Try the Number Puzzle\n";
	cout << "4. Take a Maths Test\n";
	cout << "5. Learn About Us\n";
	cout << "6. Exit\n";
	cout << "---------------------------------\n\n";
	cout << "Enter your choice (1-6): "; 

}
