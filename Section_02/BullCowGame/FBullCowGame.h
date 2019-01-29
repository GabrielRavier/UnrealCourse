/* Game logic (no view code or direct user interaction)
Simple guess the word game based on Mastermind*/

#pragma once
#include <string>
#include <cstdint>

using int32 = int32_t;
using FSize = size_t;
using FString = std::string;

struct FBullCowCount
{
	size_t Bulls = 0;
	size_t Cows = 0;
};

enum class EGuessStatus
{
	InvalidStatus,
	OK,
	NotIsogram,
	WrongLength,
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	FSize GetHiddenWordLength() const;
	bool IsGameWon() const;

	void Reset();
	EGuessStatus CheckGuessValidity(const FString& Guess) const;

	// Count bulls and cows, and increase try number assuming guess is valid
	FBullCowCount SubmitValidGuess(const FString& Guess);

private:
	bool IsIsogram(const FString& String) const;
	bool IsLowerCase(const FString& String) const;

	// See Reset for initial values
	int32 m_CurrentTry;
	FString m_HiddenWord;
	bool m_IsGameWon;
};

