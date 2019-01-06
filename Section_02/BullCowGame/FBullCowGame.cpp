#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const 
{ 
	return m_MaxTries; 
}

int FBullCowGame::GetCurrentTry() const
{
	return m_CurrentTry;
}

void FBullCowGame::Reset(int WordLength)
{

}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(const std::string & Guess)
{
	return false;
}
