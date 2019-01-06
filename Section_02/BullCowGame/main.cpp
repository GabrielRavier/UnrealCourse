#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::getline;

void PrintIntro();
void PlayGame();
string GetGuess();

const std::string &PrintGuess(std::string &Guess);


// Entry point for our application
int main()
{
	PrintIntro();

	PlayGame();

	return 0; // Exit the application
}


void PlayGame()
{
	// Loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; ++i)
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
	cout << "Enter your guess : ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}
