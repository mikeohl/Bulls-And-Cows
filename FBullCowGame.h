#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullsAndCows
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxAttempts() const;
	int32 GetCurrentAttempt() const;

	// bool IsGameWon() const;

	bool CheckGuess(FString Guess);
	FBullsAndCows ScoreGuess(FString Guess);
	void PrintResultOfGuess();

	void Reset();



private:
	int32 CurrentAttempt;
	int32 MaxGuesses;
	FString HiddenWord;
};