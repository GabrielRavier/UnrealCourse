#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const
{ 
	return m_MaxTries; 
}

int32 FBullCowGame::GetCurrentTry() const
{
	return m_CurrentTry;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	m_MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	m_HiddenWord = HIDDEN_WORD;

	m_CurrentTry = 1;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(const FString& Guess)
{
	return false;
}

BullCowCount FBullCowGame::SubmitGuess(const FString & Guess)
{
	++m_CurrentTry;

	BullCowCount BullCowCount;

	return BullCowCount;
}
