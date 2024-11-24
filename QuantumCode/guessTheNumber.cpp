#include <iostream>
#include "guessTheNumber.h"
#include <random>
#include <string>
#include <vector>
using namespace std;

//Structure, representing a mathematical question
struct Question
{
	string question; //Holds the text of the question
	int answer; // Holds the correct answer to the question
	Question(int answer, string question) { //Constructor to intialize the question and answer
		this->answer = answer;
		this->question = question;
	}
};

void startGuessTheNumber()
{
	cout << "                         ------------------------------------------------------------------                        \n";
	cout << "                        |                           Guess The Number                       |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                      The Rules of the game are:                  |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |  A text will appear on your screen                               |\n";
	cout << "                        |  Read the text carefully and try to guess the number X           |\n";
	cout << "                        |  The number X ranges from 0 to 10000.                            |\n";
	cout << "                        |                                                                  |\n";
	cout << "                        |                You have 3 tries to guess the number.             |\n";
	cout << "                        |                            Good luck!                            |\n";
	cout << "                         ------------------------------------------------------------------                         \n";
	cout << "                                                                                                                       \n";
	cout << "                                                                                                                  \n";
	//displaying rules
	srand(time(nullptr)); //Makes a random question appear every time
	vector<Question> questions;
	createQuestions(questions);
	int randomnum = rand() % questions.size();
	int attempts = 3; // How many attempts a player has
	cout << questions[randomnum].question;
	char answer;
	string guess;
	bool flag = false;
	while (attempts != 0) {
		cin >> guess; // The player has to enter a guess
		for (char& element : guess) {
			if (!isdigit(element)) flag = true;
		}
		if (flag) {
			bool flag2 = false;
			int counter = 0;
			while (flag) {
				cout << "guess not valid. Try again (0 - 10000)";
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
		if (stoi(guess) == questions[randomnum].answer) {
			cout << "You won!" << '\n' << "Would you like to try again? (Y/N): ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				cout << "Restarting..." << '\n' << '\n' << '\n';
				startGuessTheNumber(); // Restart the game
			}
			else {
				cout << "Returning to main menu...";
				return; // Exit to the main menu
			}
		}
		else {
			attempts--;
			if (attempts > 0) {
				cout << "Incorrect. Try again! Attempts left: " << attempts << '\n'; // When the answer is wrong it shows how many attempts has left
			}
		}

		if (attempts == 0) {
			cout << "You lost the game! The correct answer was: " << questions[randomnum].answer << '\n'; // When the player has lost it shows the right answer
			cout << "Would you like to try again? (Y/N): "; // Asking if they want to try again
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				cout << "Restarting..." << '\n\n\n';
				startGuessTheNumber(); // Restart the game
			}
			else {
				cout << "Returning to main menu...";
				return; // Exit the game or return to the main menu
			}
		}
	}


}

void createQuestions(std::vector <Question>& questions)
{

	Question q1(1002, "The number X I have in mind is the smallest four-digit number divisible by 6.");
	Question q2(996, "The number X I have in mind is the largest three-digit number divisible by 4.");
	Question q3(18, "The number X I have in mind is the smallest two-digit number divisible by 9.");
	Question q4(9999, "The number X I have in mind is the largest four-digit number divisible by 11.");
	Question q5(100, "The number X I have in mind is the smallest three-digit number divisible by 5.");
	Question q6(96, "The number X I have in mind is the largest two-digit number divisible by 12.");
	Question q7(1001, "The number X I have in mind is the smallest four-digit number divisible by 13.");
	Question q8(994, "The number X I have in mind is the largest three-digit number divisible by 7.");
	Question q9(10, "The number X I have in mind is the smallest two-digit number divisible by 10.");
	Question q10(9990, "The number X I have in mind is the largest four-digit number divisible by 15.");
	Question q11(104, "The number X I have in mind is the smallest three-digit number divisible by 8.");
	Question q12(98, "The number X I have in mind is the largest two-digit number divisible by 14.");
	Question q13(1008, "The number X I have in mind is the smallest four-digit number divisible by 16.");
	Question q14(999, "The number X I have in mind is the largest three-digit number divisible by 9.");
	Question q15(11, "The number X I have in mind is the smallest two-digit number divisible by 11.");
	Question q16(9990, "The number X I have in mind is the largest four-digit number divisible by 18.");
	Question q17(108, "The number X I have in mind is the smallest three-digit number divisible by 12.");
	Question q18(85, "The number X I have in mind is the largest two-digit number divisible by 17.");
	Question q19(1000, "The number X I have in mind is the smallest four-digit number divisible by 20.");
	Question q20(988, "The number X I have in mind is the largest three-digit number divisible by 13.");
	Question q21(19, "The number X I have in mind is the smallest two-digit number divisible by 19.");
	Question q22(9975, "The number X I have in mind is the largest four-digit number divisible by 21.");
	Question q23(112, "The number X I have in mind is the smallest three-digit number divisible by 14.");
	Question q24(88, "The number X I have in mind is the largest two-digit number divisible by 22.");
	Question q25(1008, "The number X I have in mind is the smallest four-digit number divisible by 24.");
	Question q26(990, "The number X I have in mind is the largest three-digit number divisible by 15.");
	Question q27(23, "The number X I have in mind is the smallest two-digit number divisible by 23.");
	Question q28(9975, "The number X I have in mind is the largest four-digit number divisible by 25.");
	Question q29(112, "The number X I have in mind is the smallest three-digit number divisible by 16.");
	Question q30(96, "The number X I have in mind is the largest two-digit number divisible by 26.");
	Question q31(1008, "The number X I have in mind is the smallest four-digit number divisible by 27.");
	Question q32(986, "The number X I have in mind is the largest three-digit number divisible by 17.");
	Question q33(28, "The number X I have in mind is the smallest two-digit number divisible by 28.");
	Question q34(9996, "The number X I have in mind is the largest four-digit number divisible by 29.");
	Question q35(108, "The number X I have in mind is the smallest three-digit number divisible by 18.");
	Question q36(90, "The number X I have in mind is the largest two-digit number divisible by 30.");
	Question q37(1003, "The number X I have in mind is the smallest four-digit number divisible by 31.");
	Question q38(969, "The number X I have in mind is the largest three-digit number divisible by 19.");
	Question q39(32, "The number X I have in mind is the smallest two-digit number divisible by 32.");
	Question q40(9990, "The number X I have in mind is the largest four-digit number divisible by 33.");
	Question q41(120, "The number X I have in mind is the smallest three-digit number divisible by 20.");
	Question q42(68, "The number X I have in mind is the largest two-digit number divisible by 34.");
	Question q43(1000, "The number X I have in mind is the smallest four-digit number divisible by 35.");
	Question q44(987, "The number X I have in mind is the largest three-digit number divisible by 21.");
	Question q45(36, "The number X I have in mind is the smallest two-digit number divisible by 36.");
	Question q46(9996, "The number X I have in mind is the largest four-digit number divisible by 37.");
	Question q47(110, "The number X I have in mind is the smallest three-digit number divisible by 22.");
	Question q48(76, "The number X I have in mind is the largest two-digit number divisible by 38.");
	Question q49(1014, "The number X I have in mind is the smallest four-digit number divisible by 39.");
	Question q50(990, "The number X I have in mind is the largest three-digit number divisible by 15.");
	Question q51(1050, "The number X I have in mind is the smallest four-digit number divisible by 42.");
	Question q52(992, "The number X I have in mind is the largest three-digit number divisible by 23.");
	Question q53(40, "The number X I have in mind is the smallest two-digit number divisible by 40.");
	Question q54(9900, "The number X I have in mind is the largest four-digit number divisible by 45.");
	Question q55(126, "The number X I have in mind is the smallest three-digit number divisible by 21.");
	Question q56(96, "The number X I have in mind is the largest two-digit number divisible by 24.");
	Question q57(1023, "The number X I have in mind is the smallest four-digit number divisible by 47.");
	Question q58(994, "The number X I have in mind is the largest three-digit number divisible by 27.");
	Question q59(25, "The number X I have in mind is the smallest two-digit number divisible by 25.");
	Question q60(9996, "The number X I have in mind is the largest four-digit number divisible by 51.");
	Question q61(144, "The number X I have in mind is the smallest three-digit number divisible by 24.");
	Question q62(88, "The number X I have in mind is the largest two-digit number divisible by 44.");
	Question q63(1008, "The number X I have in mind is the smallest four-digit number divisible by 56.");
	Question q64(972, "The number X I have in mind is the largest three-digit number divisible by 27.");
	Question q65(33, "The number X I have in mind is the smallest two-digit number divisible by 33.");
	Question q66(9960, "The number X I have in mind is the largest four-digit number divisible by 55.");
	Question q67(108, "The number X I have in mind is the smallest three-digit number divisible by 36.");
	Question q68(85, "The number X I have in mind is the largest two-digit number divisible by 17.");
	Question q69(1020, "The number X I have in mind is the smallest four-digit number divisible by 60.");
	Question q70(999, "The number X I have in mind is the largest three-digit number divisible by 31.");
	Question q71(50, "The number X I have in mind is the smallest two-digit number divisible by 50.");
	Question q72(9996, "The number X I have in mind is the largest four-digit number divisible by 63.");
	Question q73(128, "The number X I have in mind is the smallest three-digit number divisible by 32.");
	Question q74(92, "The number X I have in mind is the largest two-digit number divisible by 46.");
	Question q75(1001, "The number X I have in mind is the smallest four-digit number divisible by 41.");
	Question q76(980, "The number X I have in mind is the largest three-digit number divisible by 35.");
	Question q77(40, "The number X I have in mind is the smallest two-digit number divisible by 40.");
	Question q78(9900, "The number X I have in mind is the largest four-digit number divisible by 54.");
	Question q79(132, "The number X I have in mind is the smallest three-digit number divisible by 22.");
	Question q80(99, "The number X I have in mind is the largest two-digit number divisible by 33.");
	Question q81(1024, "The number X I have in mind is the smallest four-digit number divisible by 64.");
	Question q82(990, "The number X I have in mind is the largest three-digit number divisible by 45.");
	Question q83(44, "The number X I have in mind is the smallest two-digit number divisible by 44.");
	Question q84(9990, "The number X I have in mind is the largest four-digit number divisible by 66.");
	Question q85(120, "The number X I have in mind is the smallest three-digit number divisible by 40.");
	Question q86(87, "The number X I have in mind is the largest two-digit number divisible by 29.");
	Question q87(1002, "The number X I have in mind is the smallest four-digit number divisible by 39.");
	Question q88(924, "The number X I have in mind is the largest three-digit number divisible by 28.");
	Question q89(18, "The number X I have in mind is the smallest two-digit number divisible by 9.");
	Question q90(9900, "The number X I have in mind is the largest four-digit number divisible by 72.");
	Question q91(128, "The number X I have in mind is the smallest three-digit number divisible by 16.");
	Question q92(91, "The number X I have in mind is the largest two-digit number divisible by 13.");
	Question q93(1026, "The number X I have in mind is the smallest four-digit number divisible by 39.");
	Question q94(952, "The number X I have in mind is the largest three-digit number divisible by 34.");
	Question q95(24, "The number X I have in mind is the smallest two-digit number divisible by 12.");
	Question q96(9996, "The number X I have in mind is the largest four-digit number divisible by 78.");
	Question q97(100, "The number X I have in mind is the smallest three-digit number divisible by 20.");
	Question q98(80, "The number X I have in mind is the largest two-digit number divisible by 16.");
	Question q99(1008, "The number X I have in mind is the smallest four-digit number divisible by 48.");
	Question q100(994, "The number X I have in mind is the largest three-digit number divisible by 14.");
	// The questions
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
	questions.push_back(q25);
	questions.push_back(q26);
	questions.push_back(q27);
	questions.push_back(q28);
	questions.push_back(q29);
	questions.push_back(q30);
	questions.push_back(q31);
	questions.push_back(q32);
	questions.push_back(q33);
	questions.push_back(q34);
	questions.push_back(q35);
	questions.push_back(q36);
	questions.push_back(q37);
	questions.push_back(q38);
	questions.push_back(q39);
	questions.push_back(q40);
	questions.push_back(q41);
	questions.push_back(q42);
	questions.push_back(q43);
	questions.push_back(q44);
	questions.push_back(q45);
	questions.push_back(q46);
	questions.push_back(q47);
	questions.push_back(q48);
	questions.push_back(q49);
	questions.push_back(q50);
	questions.push_back(q51);
	questions.push_back(q52);
	questions.push_back(q53);
	questions.push_back(q54);
	questions.push_back(q55);
	questions.push_back(q56);
	questions.push_back(q57);
	questions.push_back(q58);
	questions.push_back(q59);
	questions.push_back(q60);
	questions.push_back(q61);
	questions.push_back(q62);
	questions.push_back(q63);
	questions.push_back(q64);
	questions.push_back(q65);
	questions.push_back(q66);
	questions.push_back(q67);
	questions.push_back(q68);
	questions.push_back(q69);
	questions.push_back(q70);
	questions.push_back(q71);
	questions.push_back(q72);
	questions.push_back(q73);
	questions.push_back(q74);
	questions.push_back(q75);
	questions.push_back(q76);
	questions.push_back(q77);
	questions.push_back(q78);
	questions.push_back(q79);
	questions.push_back(q80);
	questions.push_back(q81);
	questions.push_back(q82);
	questions.push_back(q83);
	questions.push_back(q84);
	questions.push_back(q85);
	questions.push_back(q86);
	questions.push_back(q87);
	questions.push_back(q88);
	questions.push_back(q89);
	questions.push_back(q90);
	questions.push_back(q91);
	questions.push_back(q92);
	questions.push_back(q93);
	questions.push_back(q94);
	questions.push_back(q95);
	questions.push_back(q96);
	questions.push_back(q97);
	questions.push_back(q98);
	questions.push_back(q99);
	questions.push_back(q100);
	// Adds the questions to the end of the questions vector.
}