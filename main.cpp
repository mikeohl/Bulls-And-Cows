/* Main file: Controls game & user interaction
 * Game is created with instance of FBullCowGame class
**/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// Function Prototypes

void PrintIntro();
void GuessWord();
bool PlayAgain();
FText GetValidGuess();

// Game instance is global because only one game is needed
FBullCowGame BCGame;

int main() 
{
	do
	{
		PrintIntro();
		GuessWord();
	} 
	while (PlayAgain());

	std::cout << std::endl;
	return 0;
}

// Player guesses word until the word is correct or attempts exceeds MaxAttempts
void GuessWord()
{
	BCGame.Reset();
	int32 MaxAttempts = BCGame.GetMaxAttempts();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentAttempt() <= MaxAttempts)
	{
		FText Guess = GetValidGuess();

		FBullsAndCows BullCowCount = BCGame.ScoreGuess(Guess);

		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
	}

	// TODO: Summarize Game
}

// Output game introduction text
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.WordLength() << " letter word I'm thinking of?" << std::endl;
	return;
}

// Receive word/guess from player
FText GetValidGuess()
{
	EGuessValidity Validity = EGuessValidity::_Invalid;
	FText Guess = "";
	do
	{
		std::cout << "Attempt " << BCGame.GetCurrentAttempt() << ", Enter your guess: ";
		getline(std::cin, Guess);

		EGuessValidity Validity = BCGame.CheckGuess(Guess);
		switch (Validity)
		{
		case EGuessValidity::Wrong_Length:
			std::cout << "Please enter a " << BCGame.WordLength() << " letter word." << std::endl;
			break;
		case EGuessValidity::Not_Lowercase:
			std::cout << "Please enter a word only in lowercase letters." << std::endl;
			break;
		case EGuessValidity::Not_Isogram:
			/*std::cout << "Please enter an isogram (a word with no repeating letter)." << std::endl;
			break;*/
		case EGuessValidity::OK:
			return Guess;
		}
	} while (Validity != EGuessValidity::OK);
}

// Ask player whether to play again
bool PlayAgain()
{
	std::cout << "Would you like to play again? [y/n]: ";
	FText Response = "";
	getline(std::cin, Response);
	
	return Response[0] == 'y' || Response[0] == 'Y';
}



