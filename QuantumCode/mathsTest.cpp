#include <iostream>
#include <random> // For generating random numbers
#include <vector> // For using the vector container
#include <string> // For using the string class
#include <Windows.h> // For Windows-specific console color functions
#include "mathsTest.h" // Including the functions for the Maths Test
using namespace std;

// Defining color codes for console text
#define RED 4
#define GREEN 2
#define DARKBLUE 1
#define AQUA 3
#define GOLD 6

// Structure, representing a mathematical question
struct TestQuestion
{
    string question; // Holds the text of the question
    int answer; // Holds the correct answer to the question
    TestQuestion(int answer, string question) // Constructor to initialize the question and answer
    {
        this->answer = answer;
        this->question = question;
    }
};

// Function to create a list of questions and answers
void createQuestions(std::vector<TestQuestion>& questions)
{
    // Initialize a list of questions with their correct answers
    TestQuestion q1(120, "What is permutation of 5?");
    TestQuestion q2(720, "What is permutation of 6?");
    TestQuestion q3(24, "What is permutation of 4?");
    TestQuestion q4(6, "If 2x - 3 = 9, what is x?");
    TestQuestion q5(5, "If 5x + 4 = 29, what is x?");
    TestQuestion q6(3, "If 9x + 8 = 35, what is x?");
    TestQuestion q7(10, "What is 20% of 50?");
    TestQuestion q8(3, "What is 15% of 20?");
    TestQuestion q9(36, "What is permutation of 3, multiplied by the square root of 36?");
    TestQuestion q10(16, "What is the perimeter of a square, if a = 4?");
    TestQuestion q11(9, "What is the value of x, if 2x=27-9?");
    TestQuestion q12(5, "What is the square root of 25?");
    TestQuestion q13(0, "If a=0 and b=8, what's the value of c, when c = a.b");
    TestQuestion q14(6, "What is the square root of 36?");
    TestQuestion q15(7, "What is the square root of 49?");
    TestQuestion q16(8, "What is the square root of 64?");
    TestQuestion q17(9, "What is the square root of 81?");
    TestQuestion q18(10, "What is the square root of 100?");
    TestQuestion q19(2, "What is the square root of 4?");
    TestQuestion q20(3, "What is the square root of 9?");
    TestQuestion q21(4, "What is the square root of 16?");
    TestQuestion q22(1, "What does the square root of 25 divided by 5 equal?");
    TestQuestion q23(42, "If a=7 and b=6, what's the value of c, when c = a.b");
    TestQuestion q24(14, "If a= 42 and b=3, what's the value of c, when c = a:b");

    // Store the questions in a vector
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
}

// Function, used to set the console text color
void SetColor(int color)
{
    if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)) // Try to set the console text color
    {
        return;
    }
    else // If setting the color fails set it to GOLD 
    {
        SetColor(GOLD);
    }
}

// Function to start the Maths Test
void startMathsTest()
{
    SetColor(AQUA);

    // Display the rules
    cout << "                         ------------------------------------------------------------------                        \n";
    cout << "                        |                           Maths Test                             |\n";
    cout << "                        |                                                                  |\n";
    cout << "                        |                      The Rules of the game are:                  |\n";
    cout << "                        |                                                                  |\n";
    cout << "                        |  A mathematical question has been asked.                         |\n";
    cout << "                        |  You have to type in the right answer, in order to               |\n";
    cout << "                        |  succeed. Otherwise, it says you have failed.                    |\n";
    cout << "                        |  The questions are rightfully taken from the                     |\n";
    cout << "                        |  9th grade Mathematics coursebook.                               |\n";
    cout << "                        |  The test includes questions from : Algebra,                     |\n";
    cout << "                        |  Percentages, Roots, Geometry.                                   |\n";
    cout << "                        |                                                                  |\n";
    cout << "                        |                            Good luck!                            |\n";
    cout << "                         ------------------------------------------------------------------                         \n";

    vector<TestQuestion> questions;
    createQuestions(questions); // Create a list of questions

    int answer = 0; // Variable to store user's answer
    int randomQuestion = rand() % questions.size(); // Generate a number to select a random question
    cout << questions[randomQuestion].question; // display the randomly selected question
    cin >> answer;

    // Check if the user's answer is correct 
    if (answer == questions[randomQuestion].answer)
    {
        SetColor(GREEN); // Set color to GREEN if the player has won
        cout << "\n\n";
        cout << "*****************************************\n";
        cout << "*           CONGRATULATIONS!             *\n";
        cout << "*    You got it absolutely right!        *\n";
        cout << "* You are a true maths genius! Well done!*\n";
        cout << "*****************************************\n\n";

        char answer;
        cout << "Would you like to try again? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            startMathsTest(); // Restarting the test 
        }
        else
        {
            SetColor(GOLD); // returing to main menu
            cout << "Returning to main menu..." << endl;
            return;
        }
    }
    else
    {
        SetColor(RED); // Set color to RED if the player has lost
        cout << "\n\n";
        cout << "*****************************************\n";
        cout << "*           OOPS! INCORRECT!             *\n";
        cout << "* Mistakes are a part of learning.       *\n";
        cout << "* Let's give it another shot!            *\n";
        cout << "*****************************************\n\n";

        char answer;
        cout << "Would you like to try? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            startMathsTest(); // Restarting the test
        }
        else
        {
            SetColor(GOLD); // returning to the main menu
            cout << "Returning to main menu..." << endl;
            return;
        }
    }
}
