#pragma once
#include <string>

using FString = std::string;
using int32 = int;

enum class EGuessValidity
{
	_Invalid,
	Wrong_Length,
	OK,
	Not_Isogram,
	Not_Lowercase
};

//enum class EResetStatus 
//{
//	No_Hidden_Word,
//	OK
//};

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
	int32 WordLength() const;
	bool IsGameWon() const;
	EGuessValidity CheckGuess(FString Guess) const;

	FBullsAndCows ScoreGuess(FString Guess);
	void Reset();

	//void PrintResultOfGuess();


private:
	FString HiddenWord;
	int32 MaxGuesses;
	int32 CurrentAttempt;
	bool bGameIsWon;
};