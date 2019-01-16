/*

	This is the console executable, which makes use of the FBullCowGame class.
	This acts as the view in a MVC pattern, and is responsible for all user interaction.
	For game logic see the FBullCowGame class.

*/

#include <iostream>
#include <string>
#include <cstdint>
#include "FBullCowGame.h"

using std::cout;
using std::cin;
using std::getline;

using FText = std::string;
using int32 = int32_t;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// Instantiate a new game

// Entry point for our application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
		// TODO Add a game summary
	} while (AskToPlayAgain());

	return 0; // Exit the application
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	// TODO Change from for to while loop once we're validating files
	for (int32 i = 0; i < MaxTries; ++i)
	{
		auto Guess = GetGuess(); // TODO Make loop checking for valid guesses

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows
		cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << '\n';
	}

	cout << '\n';
}


void PrintIntro()
{
	// Introduce the game
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
}

FText GetGuess()	// Change to GetValidGuess and make it validate the guess
{
	// Get a guess from the player
	cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess : ";
	FText Guess;
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again ? ";
	FText Response;
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
