#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const
{ 
	return m_MaxTries; 
}

int32 FBullCowGame::GetCurrentTry() const
{
	return m_CurrentTry;
}

FSize FBullCowGame::GetHiddenWordLength() const
{
	return m_HiddenWord.length();
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	m_MaxTries = MAX_TRIES;
	m_HiddenWord = HIDDEN_WORD;
	m_CurrentTry = 1;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(const FString& Guess) const
{
	// TODO finish this
	if (false)
		return EWordStatus::NotIsogram;
	else if (false)
		return EWordStatus::NotLowercase;
	else if (this->GetHiddenWordLength() != Guess.length())
		return EWordStatus::WrongLength;

	return EWordStatus::OK;
}

FBullCowCount FBullCowGame::SubmitGuess(const FString& Guess)
{
	++m_CurrentTry;

	FBullCowCount BullCowCount;

	size_t HiddenWordLength = m_HiddenWord.length();
	for (size_t i = 0; i < HiddenWordLength; ++i)
	{
		auto pos = m_HiddenWord.find(Guess[i]);
		if (pos == i)
			++BullCowCount.Bulls;
		else if (pos != FString::npos)
			++BullCowCount.Cows;
	}


	return BullCowCount;
}
