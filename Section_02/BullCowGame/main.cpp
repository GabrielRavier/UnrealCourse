/*

	This is the console executable, which makes use of the FBullCowGame class.
	This acts as the view in a MVC pattern, and is responsible for all user interaction.
	For game logic see the FBullCowGame class.

*/

#include <iostream>
#include <string>
#include <cstdint>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int32_t;

static void PrintIntro();
static void PlayGame();
static FText GetValidGuess();
static bool AskToPlayAgain();

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


static void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	// TODO Change from for to while loop once we're validating files
	for (int32 i = 0; i < MaxTries; ++i)
	{
		auto Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	std::cout << '\n';
}

static void PrintIntro()
{
	// Introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
}

// Loop continually until we've got a valid guess
static FText GetValidGuess()
{
	// Get a guess from the player
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess : ";
	FText Guess;
	getline(std::cin, Guess);

	EGuessStatus Status = EGuessStatus::InvalidStatus;

	do
	{
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::WrongLength:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;

		case EGuessStatus::NotIsogram:
			std::cout << "Please enter a word without repeating letters\n";
			break;

		case EGuessStatus::NotLowercase:
			std::cout << "Please enter all lowercase letters\n";
			break;

		case EGuessStatus::InvalidStatus:
			std::cout << "Invalid status\n";
			break;
		}
	} while (Status != EGuessStatus::OK);

	return Guess;
}

static bool AskToPlayAgain()
{
	std::cout << "Do you want to play again ? ";
	FText Response;
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
