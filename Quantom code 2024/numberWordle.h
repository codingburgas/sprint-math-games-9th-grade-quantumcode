#pragma once

void startNumberWordle();

int generateNumber();

int findNthDigit(int digit, int number);

void checkForMatch(int n, int variant, int& rightSpot, int& wrongSpot);

bool guessValid(int guess);