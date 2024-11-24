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
	Question q9(36, "What is permutation of 3, multiplied by the square roof of 36?");
	Question q10(16, "What is the perimeter of a square, if a = 4?");
	Question q11(9, "What is the value of x, if 2x=27-9?");
	Question q12(5, "What is the square root of 25?");
	Question q13(0, "If a=0 and b=8, what's the value of c, when c = a.b");
	Question q14(6, "What is the square root of 36?");
	Question q15(7, "What is the square root of 49?");
	Question q16(8, "What is the square root of 64?");
	Question q17(9, "What is the square root of 81?");
	Question q18(10, "What is the square root of 100?");
	Question q19(2, "What is the square root of 4?");
	Question q20(3, "What is the square root of 9?");
	Question q21(4, "What is the square root of 16?");
	Question q22(1, "What does the square root of 25 divided by 5 equal?");
	Question q23(42, "If a=7 and b=6, what's the value of c, when c = a.b");
	Question q24(14, "If a= 42 and b=3, what's the value of c, when c = a:b");
	vector<Question> questions; 
	questions.push_back(q1);
	questions.push_back(q2);
	questions.push_back(q3);
	questions.push_back(q4);
	questions.push_back(q5);
	questions.push_back(q6);
	questions.push_back(q7);
	questions.push_back(q8);
	questions.push_back(q9);
	questions.push_back(q10);
	questions.push_back(q11);
	questions.push_back(q12);
	questions.push_back(q13);
	questions.push_back(q14);
	questions.push_back(q15);
	questions.push_back(q16);
	questions.push_back(q17);
	questions.push_back(q18);
	questions.push_back(q19);
	questions.push_back(q20);
	questions.push_back(q21);
	questions.push_back(q22);
	questions.push_back(q23);
	questions.push_back(q24);
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