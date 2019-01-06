#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();

	void Reset();	// TODO make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(const std::string& Guess);	// TODO make a more rich return value

private:
	int m_CurrentTry;	// See Reset for initial values
	int m_MaxTries;
};

