#pragma once
#include <string>

void startNumberWordle();

int generateNumber();

int findNthDigit(int digit, int number);

bool guessValid(std::string guess);