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
//defines color
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

void aboutUs()
{
	cout << "                         ================================================================                         \n";
	cout << "                        ||                            ABOUT US                           ||\n";
	cout << "                        ||                                                                 ||\n";
	cout << "                        ||                    We are Quantum Code:                        ||\n";
	cout << "                        ||                                                                 ||\n";
	cout << "                        ||              We created 4 fun and educational games:           ||\n";
	cout << "                        ||                1. Number Wordle Guess                           ||\n";
	cout << "                        ||                 2. Guess The Number                             ||\n";
	cout << "                        ||                  3. Guess the Puzzle                            ||\n";
	cout << "                        ||                    4. Maths Test                                ||\n";
	cout << "                        ||                       Good luck!                                ||\n";
	cout << "                         ================================================================                         \n";
}
//about us menu
void displayMenu()
{
	setColor(AQUA); // Menu title color
	cout << "+-------------------------------------------------+\n";
	cout << "|              WELCOME TO QUANTUM CODE           |\n";
	cout << "+-------------------------------------------------+\n";
	cout << "|                    MAIN MENU                   |\n";
	cout << "+-------------------------------------------------+\n\n";
	//welcome message
	setColor(GOLD);
	cout << "  *************************************\n";
	cout << "  *           CHOOSE AN OPTION        *\n";
	cout << "  *************************************\n";

	setColor(WHITE); // Select menu color
	cout << "  [1] Play Number Wordle\n";
	cout << "  [2] Play Guess the Number\n";
	cout << "  [3] Try the Number Puzzle\n";
	cout << "  [4] Take a Maths Test\n";
	cout << "  [5] Learn About Us\n";
	cout << "  [6] Exit\n";

	setColor(GREEN); // Prompt color
	cout << "\n  Please enter your choice (1-6): "; //To select a option
}
