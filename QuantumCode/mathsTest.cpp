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
		vector<Question> questions;
		questions.push_back(q1);
		questions.push_back(q2);
		int answer = 0;
		int randomQuestion = rand() % questions.size();
		cout << questions[randomQuestion].question;
		cin >> answer;
		if (answer == questions[randomQuestion].answer) {
			cout << "Hooray! You got it right!";
		}
	}
	