#pragma once
#include <string>
#include <cstdint>

using int32 = int32_t;
using FString = std::string;

class FBullCowGame
{
public:
	FBullCowGame();

	void Reset();	// TODO Make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(const FString& Guess);	// TODO Make a more rich return value
	// TODO Provide a method for counting bulls and cows and increasing turn #

private:
	int32 m_CurrentTry;	// See Reset for initial values
	int32 m_MaxTries;
};

