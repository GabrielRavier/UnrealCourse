#pragma once

#include <string>

class FBullCowGame
{
public:
	void Reset(int WordLength); // TODO make a more rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(const std::string& Guess);

private:
	int m_CurrentTry;
	int m_MaxTries;
};

