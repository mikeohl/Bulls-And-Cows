/* Bull Cow Class implementation. 
 * Can check to see if guess is valid, score guess,
 * set new game, plus getter & helper functions 

 */

#pragma once
#include "FBullCowGame.h"
#include <map>

#define TMap std::map

using int32 = int;

// Simple Hidden Word. TODO: Add list of words to pick from at random
const FString HIDDEN_WORD = "assumption";
const float ATTEMPTS_PER_LETTER = 1.4f;

// Constructor
FBullCowGame::FBullCowGame() : CurrentAttempt(1), MaxAttempts(5) {}


// Get if the player has won the game
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


// Get the number of the current attempt of the player 
int32 FBullCowGame::GetCurrentAttempt() const { return CurrentAttempt; }


// Get the maximum number of attempts the player has to guess the word
int32 FBullCowGame::GetMaxAttempts() const { return HIDDEN_WORD.length() * ATTEMPTS_PER_LETTER; }


// Get length of hidden word
int32 FBullCowGame::WordLength() const { return HIDDEN_WORD.length(); }


// Advance current attempt if Guess is valid
EGuessValidity FBullCowGame::CheckGuess(FString Guess) const
{
	if (Guess.length() != WordLength()) {
		return EGuessValidity::Wrong_Length;
	}
	else if (!IsLowerCase(Guess)) {
		return EGuessValidity::Not_Lowercase;
	}
	//else if (!IsIsogram(Guess)) {
	//	return EGuessValidity::Not_Isogram;
	//}
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


// Set class variables to initial values and select word
void FBullCowGame::NewGame()
{
	bGameIsWon = false;
	HiddenWord = HIDDEN_WORD; // TODO: Replace to randomly select word in list
	CurrentAttempt = 1;
	return;
}


// Determines whether the word is an Isogram
bool FBullCowGame::IsIsogram(FString Word) const
{
	int32 WordLength = Word.length();
	if (WordLength < 2) {
		return true;
	}
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}


// Prototype function O(n log n) to n(26) => 37 [Only English]
bool FBullCowGame::IsIsogram_v2(FString Word) const
{
	int32 WordLength = Word.length();
	if (WordLength > 26) {
		return false;
	}
	for (int i = 0; i < WordLength - 1; i++)
	{
		for (int j = i + 1; j < WordLength; j++)
		{
			if (Word[i] == Word[j]) {
				return false;
			}
		}
	}
	return true;
}


// Determine whether the word is all lowercase
bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (isupper(Letter)) {
			return false;
		}
	}
	return true;
}
