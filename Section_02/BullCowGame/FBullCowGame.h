#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(int WordLength);	// TODO make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(const std::string& Guess);	// TODO make a more rich return value

private:
	int m_CurrentTry = 1;
	int m_MaxTries = 5;
};

