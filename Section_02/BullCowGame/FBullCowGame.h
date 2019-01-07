#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();

	void Reset();	// TODO Make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(const std::string& Guess);	// TODO Make a more rich return value
	// TODO Provide a method for counting bulls and cows and increasing turn #

private:
	int m_CurrentTry;	// See Reset for initial values
	int m_MaxTries;
};

