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
FText GetGuess();

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

// Player has NUM_GUESSES to guess isogram
void GuessWord()
{
	BCGame.Reset();
	int32 MaxAttempts = BCGame.GetMaxAttempts();

	// TODO: Change to while loop so that we can get out early if the correct word is guessed
	while (BCGame.GetCurrentAttempt() <= MaxAttempts)
	{
		FText Guess = GetGuess(); // TODO: Make sure guess is valid

		// Output guess back to the player
		std::cout << "You guessed: " << Guess << std::endl;
		std::cout << std::endl;

		// If Guess is valid, score guess
		if (BCGame.CheckGuess(Guess)) {
			FBullsAndCows BullCowCount = BCGame.ScoreGuess(Guess);
	
			// Print number of bulls and cows
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
		}
		else {
			std::cout << "Invalid Guess" << std::endl;
		}
	}

	// TODO: Summarize Game
}

// Output game introduction text
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?" << std::endl;
	return;
}

// Receive word/guess from player
FText GetGuess()
{
	std::cout << "Attempt " << BCGame.GetCurrentAttempt() << ", Enter your guess: ";
	FText Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

// Ask player whether to play again
bool PlayAgain()
{
	std::cout << "Would you like to play again? [y/n]: ";
	FText Response = "";
	getline(std::cin, Response);
	
	return Response[0] == 'y' || Response[0] == 'Y';
}



