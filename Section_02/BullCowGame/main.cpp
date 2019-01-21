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
	do
	{
		BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries();

		std::cout << "\n\n";

		// Loop asking for guesses until game is won or no tries remain
		while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
		{
			auto Guess = GetValidGuess();

			// Submit valid guess to the game
			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
			std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << "\n\n";
		}
	} while (AskToPlayAgain());	// Continue while user wants to play

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
	FText Guess;
	EGuessStatus Status = EGuessStatus::InvalidStatus;

	do
	{
		// Get a guess from the player
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess : ";
		getline(std::cin, Guess);

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

		default:
			break;	// Assume string is ok
		}
	} while (Status != EGuessStatus::OK);

	return Guess;
}

static bool AskToPlayAgain()
{
	std::cout << "Do you want to play again ? (y/n) ";
	FText Response;
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
