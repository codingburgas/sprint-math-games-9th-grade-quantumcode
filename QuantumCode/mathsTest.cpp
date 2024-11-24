#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <Windows.h>
#include "mathsTest.h"
using namespace std;
#define RED 4
#define GREEN 2
#define DARKBLUE 1
#define AQUA 3
#define GOLD 6

void SetColor(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
	else
	{
		SetColor(GOLD);
	}
}

struct Question
{
	string question;
	int answer;
	Question(int answer, string question)
	{
		this->answer = answer;
		this->question = question;
	}
};

void startMathsTest()
{
	SetColor(AQUA);
	cout << "                         ------------------------------------------------------------------                        \n";
	cout << "                        |                           Maths Test                             |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                      The Rules of the game are:                  |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |  A mathematic question has been asked.                           |\n";
	cout << "                        |  You have to type in the right answer, in order to               |\n";
	cout << "                        |  succeed. Otherwise, it says you have failed.                    |\n";
	cout << "                        |  The questions are rightfully taken from the                     |\n";
	cout << "                        |  9th grade Mathematics coursebook.                               |\n";
	cout << "                        |  The test includes questions from : Algebra,                     |\n";
	cout << "                        |  Percentages, Roots, Geometry.                                   |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                            Good luck!                            |\n";
	cout << "                         ------------------------------------------------------------------                         \n";
	Question q1(120, "What is permutation of 5?");
	Question q2(720, "What is permutation of 6?");
	Question q3(24, "What is permutation of 4?");
	Question q4(6, "If 2x - 3 = 9, what is x?");
	Question q5(5, "If 5x + 4 = 29, what is x?");
	Question q6(3, "If 9x + 8 = 35, what is x?");
	Question q7(10, "What is 20% of 50?");
	Question q8(3, "What is 15% of 20?");
	vector<Question> questions;
	questions.push_back(q1);
	questions.push_back(q2);
	questions.push_back(q3);
	questions.push_back(q4);
	questions.push_back(q5);
	questions.push_back(q6);
	questions.push_back(q7);
	questions.push_back(q8);
	int answer = 0;
	int randomQuestion = rand() % questions.size();
	cout << questions[randomQuestion].question;
	cin >> answer;
	if (answer == questions[randomQuestion].answer)
	{
		SetColor(GREEN);
		cout << "Hooray! You got it right!";
	}
	else
	{
		SetColor(RED);
		cout << "Wrong answer! Try again!";
	}
}