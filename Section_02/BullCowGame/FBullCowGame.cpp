#include "FBullCowGame.h"
#include <algorithm>

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
	m_IsGameWon = false;
}

bool FBullCowGame::IsGameWon() const
{
	return m_IsGameWon;
}

static bool IsIsogram(FString String)
{
	std::sort(String.begin(), String.end());

	auto len = String.size();
	for (size_t i = 1; i < len; ++i)
		if (String[i] == String[i - 1])
			return false;
	return true;
}

static bool IsLowerCase(const FString& String)
{
	return std::find_if(String.begin(), String.end(), [](unsigned char c)
	{
		return (!isalnum(c) || !islower(c));
	}) == String.end();
}

EGuessStatus FBullCowGame::CheckGuessValidity(const FString& Guess) const
{
	if (!IsLowerCase(Guess))
		return EGuessStatus::NotLowercase;
	else if (!IsIsogram(Guess))
		return EGuessStatus::NotIsogram;
	else if (this->GetHiddenWordLength() != Guess.length())
		return EGuessStatus::WrongLength;

	return EGuessStatus::OK;
}

FBullCowCount FBullCowGame::SubmitValidGuess(const FString& Guess)
{
	++m_CurrentTry;
	FBullCowCount BullCowCount;

	// Loop through all the guess letters to try to find them in the hidden word
	size_t HiddenWordLength = this->GetHiddenWordLength();
	for (size_t i = 0; i < HiddenWordLength; ++i)
	{
		auto pos = m_HiddenWord.find(Guess[i]);
		if (pos == i)
			++BullCowCount.Bulls;
		else if (pos != FString::npos)
			++BullCowCount.Cows;
	}

	m_IsGameWon = (BullCowCount.Bulls == this->GetHiddenWordLength());

	return BullCowCount;
}
