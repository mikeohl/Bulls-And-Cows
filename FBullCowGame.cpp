#include "FBullCowGame.h"

using int32 = int;

// Simple Hidden Word. TODO: Add list of words to pick from at random
const FString HIDDEN_WORD = "planet";

// Constructor
FBullCowGame::FBullCowGame() : CurrentAttempt(1), MaxGuesses(5) {}

// Get the maximum number of attempts the player has to guess the word
int32 FBullCowGame::GetMaxAttempts() const { return MaxGuesses; }

// Get the number of the current attempt of the player 
int32 FBullCowGame::GetCurrentAttempt() const { return CurrentAttempt; }

// Get length of hidden word
int32 FBullCowGame::WordLength() const { return HIDDEN_WORD.length(); }

// Get if the player has won the game
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

// Advance current attempt if Guess is valid
EGuessValidity FBullCowGame::CheckGuess(FString Guess) const
{
	if (Guess.length() != WordLength()) { // TODO: Implement Logic
		return EGuessValidity::Wrong_Length;
	}

	if (false) {
		return EGuessValidity::Not_Lowercase;
	}

	if (false) {
		return EGuessValidity::Not_Isogram;
	}

	return EGuessValidity::OK;
}

// Counts bulls & cows in 'valid' Guess
FBullsAndCows FBullCowGame::ScoreGuess(FString Guess)
{
	FBullsAndCows BullCowCount;

	int32 HiddenWordLength = HiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		if (Guess[i] == HiddenWord[i]) {
			BullCowCount.Bulls++;
		}
		else {
			for (int32 j = 0; j < HiddenWordLength; j++)
			{
				if (Guess[i] == HiddenWord[j]) {
					BullCowCount.Cows++;
					break;
				}
			}
		}
	}

	// Update attempt and score
	CurrentAttempt++;
	if (BullCowCount.Bulls == WordLength()) {
		bGameIsWon = true;
	}

	return BullCowCount;
}

//void FBullCowGame::PrintResultOfGuess()
//{
//	return;
//}


void FBullCowGame::Reset()
{
	bGameIsWon = false;
	CurrentAttempt = 1;
	HiddenWord = HIDDEN_WORD;
	return;
}
