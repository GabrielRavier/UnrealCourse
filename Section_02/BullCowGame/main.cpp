#include <iostream>
#include <string>
#include "FBullCowGame.h"

using std::cout;
using std::cin;
using std::string;
using std::getline;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// Instantiate a new game

// Entry point for our application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0; // Exit the application
}


void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	for (int i = 0; i < MaxTries; ++i)
	{
		auto Guess = GetGuess();
		cout << "Your guess was : " << Guess;
		cout << '\n';
	}

	cout << '\n';
}


void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
}


string GetGuess()
{
	// Get a guess from the player
	cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess : ";
	string Guess;
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again ? ";
	string Response;
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
