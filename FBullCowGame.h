/* Bull Cow Game Class Definition. Class is used 
 * to implement game instance and keep game state 
 */

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

// Score Type
struct FBullsAndCows
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

// Game class
class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxAttempts() const;
	int32 GetCurrentAttempt() const;
	int32 WordLength() const;
	EGuessValidity CheckGuess(FString Guess) const;
	FBullsAndCows ScoreGuess(FString Guess);
	bool IsGameWon() const;
	void NewGame();

private:
	FString HiddenWord;
	int32 MaxAttempts;
	int32 CurrentAttempt;
	bool bGameIsWon;

	bool IsIsogram(FString Word) const;
	bool IsIsogram_v2(FString Word) const;
	bool IsLowerCase(FString Word) const;
};