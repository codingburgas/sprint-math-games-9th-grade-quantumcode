#include <iostream>
#include <random>
#include <vector>
#include <string>
#include "mathsTest.h"
using namespace std;
struct Question {
	string question;
	int answer;
	Question(int answer, string question) {
		this->answer = answer;
		this->question = question;
	}
};
void startMathsTest()
{
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
	if (answer == questions[randomQuestion].answer) {
		cout << "Hooray! You got it right!";
	}
}