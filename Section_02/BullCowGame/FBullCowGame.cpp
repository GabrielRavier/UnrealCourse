#include "FBullCowGame.h"
#include <algorithm>
#include <map>

// Make syntax unreal-friendly
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const
{
	return m_CurrentTry;
}

FSize FBullCowGame::GetHiddenWordLength() const
{
	return m_HiddenWord.length();
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20} };
	return WordLengthToMaxTries[m_HiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // This MUST be an isogram

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
	if (String.length() <= 0)
		return true;	// 0/1-length strings are always isograms lol

	TMap<char, bool> LetterSeen;

	for (char i : String)
	{
		i = static_cast<char>(tolower(i));
		if (LetterSeen[i])
			return false;
		LetterSeen[i] = true;
	}
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
	if (!IsIsogram(Guess))
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
