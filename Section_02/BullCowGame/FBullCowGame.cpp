#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const 
{ 
	return m_MaxTries; 
}

int FBullCowGame::GetCurrentTry() const
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
	m_CurrentTry = 1;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(const std::string & Guess)
{
	return false;
}
