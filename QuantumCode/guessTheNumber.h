#pragma once 
#include <vector>
#include <string>
struct Question;
void startGuessTheNumber();

void createQuestions(std::vector <Question>& questions);

bool isValid(std::string guess);