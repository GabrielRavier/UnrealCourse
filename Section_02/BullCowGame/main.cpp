#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::getline;

void PrintIntro();
string GetGuessAndPrintBack();

int main()
{
	PrintIntro();

	GetGuessAndPrintBack();

	cout << '\n';
	return 0;
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
}

string GetGuessAndPrintBack()
{
	// Get a guess from the player
	cout << "Enter your guess : ";
	string Guess = "";
	getline(cin, Guess);

	// Repeat the guess back to them
	cout << "Your guess was : " << Guess << '\n';
	return Guess;
}
