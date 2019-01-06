#include "FBullCowGame.h"

void FBullCowGame::Reset(int WordLength)
{

}

int FBullCowGame::GetMaxTries()
{
	return m_MaxTries;
}

int FBullCowGame::GetCurrentTry()
{
	return 0;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(const std::string & Guess)
{
	return false;
}
