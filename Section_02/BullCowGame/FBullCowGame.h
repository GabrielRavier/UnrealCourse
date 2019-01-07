#pragma once
#include <string>
#include <cstdint>

using int32 = int32_t;
using FString = std::string;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	// TODO Make a more rich return value
	bool CheckGuessValidity(const FString& Guess);	// TODO Make a more rich return value

	// Count bulls and cows, and increase try number assuming guess is valid
	BullCowCount SubmitGuess(const FString& Guess);

private:
	int32 m_CurrentTry;	// See Reset for initial values
	int32 m_MaxTries;
	FString m_HiddenWord;
};

