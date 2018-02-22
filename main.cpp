/* Main file: Controls game & user interaction
 * Game is created with instance of FBullCowGame class
 */

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Unreal Type Indentifiers to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Function Prototypes

void PrintIntro();
void PrintSummary();
void GuessWord();
bool PlayAgain();
FText GetValidGuess();

// Game instance is global because only one game is needed across plays
FBullCowGame BCGame;

int main() 
{
	do
	{
		BCGame.NewGame();
		PrintIntro();
		GuessWord();
		PrintSummary();
	} 
	while (PlayAgain());

	std::cout << std::endl;
	return 0;
}

// Player guesses word until the word is correct or attempts exceeds MaxAttempts
void GuessWord()
{
	int32 MaxAttempts = BCGame.GetMaxAttempts();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentAttempt() <= MaxAttempts)
	{
		FText Guess = GetValidGuess();

		FBullsAndCows BullCowCount = BCGame.ScoreGuess(Guess);

		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
}

// Output game introduction text
void PrintIntro()
{
	std::cout << std::endl;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << std::endl;
	std::cout << "          }   {      ___            " << std::endl;
	std::cout << "          (o o)     (o o)           " << std::endl;
	std::cout << "   /-------\\ /       \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O         O| COW  | \\  " << std::endl;
	std::cout << " *  |-,--- |           |------|  *  " << std::endl;
	std::cout << "    ^      ^           ^      ^      " << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.WordLength() << " letter word I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

// Receive word/guess from player
FText GetValidGuess()
{
	EGuessValidity Validity = EGuessValidity::_Invalid;
	FText Guess = "";
	do
	{
		std::cout << "Attempt " << BCGame.GetCurrentAttempt() << " of " << BCGame.GetMaxAttempts() << ", Enter your guess: ";
		getline(std::cin, Guess);

		Validity = BCGame.CheckGuess(Guess);
		switch (Validity)
		{
		case EGuessValidity::Wrong_Length:
			std::cout << "Please enter a " << BCGame.WordLength() << " letter word." << std::endl;
			break;
		case EGuessValidity::Not_Lowercase:
			std::cout << "Please enter a word only in lowercase letters." << std::endl;
			break;
		case EGuessValidity::Not_Isogram:
			std::cout << "Please enter an isogram (a word with no repeating letter)." << std::endl;
			break;
		}
		std::cout << std::endl;
	} while (Validity != EGuessValidity::OK);
	return Guess;
}

// Ask player whether to play again
bool PlayAgain()
{
	std::cout << "Would you like to play again? [y/n]: ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	
	return Response[0] == 'y' || Response[0] == 'Y';
}

// Output game summary text
void PrintSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations, you guessed the word!" << std::endl;
	}
	else {
		std::cout << "Sorry, you couldn't guess the word. Better luck next time!" << std::endl;
	}
	std::cout << std::endl;
}

