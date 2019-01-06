#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";

	// Get a guess from the player
	cout << "Enter your guess : ";
	string Guess = "";
	cin >> Guess;

	// Repeat the guess back to them
	cout << "Your guess was : " << Guess << '\n';

	cout << '\n';
	return 0;
}
