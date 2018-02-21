#include "FBullCowGame.h"

using int32 = int;

// Simple Hidden Word. TODO: Add list of words to pick from at random
const FString HIDDEN_WORD = "alaba";

// Constructor
FBullCowGame::FBullCowGame() : CurrentAttempt(1), MaxGuesses(5) {}

void FBullCowGame::Reset()
{
	CurrentAttempt = 1;
	HiddenWord = HIDDEN_WORD;
	// plus more?

	return;
}

int32 FBullCowGame::GetMaxAttempts() const
{
	return MaxGuesses;
}

int32 FBullCowGame::GetCurrentAttempt() const
{
	return CurrentAttempt;
}

// Advance current attempt if Guess is valid
bool FBullCowGame::CheckGuess(FString Word)
{
	if (true) { // TODO: Implement Logic
		CurrentAttempt++;
		return true;
	}
	return false;
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

	return BullCowCount;
}

void FBullCowGame::PrintResultOfGuess()
{
	return;
}
