#include "FBullCowGame.h"
#include <algorithm>
#include <map>
#define TMap std::map

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

bool FBullCowGame::IsIsogram(const FString& String) const
{
	auto Str = String;
	std::sort(Str.begin(), Str.end());
	
	auto len = Str.size();
	for (size_t i = 1; i < len; ++i)
		if (Str[i] == Str[i - 1])
			return false;
	return true;
}

bool FBullCowGame::IsLowerCase(const FString& String) const
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
	else
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
