// Markenly Alusma
// Letter Guessing Game


#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#define MAXGUESSES 5

//function prototypes with a comment for each one describing what the function does.
//Copy and paste from assignment
//this function provides instructions to the user on how to play the game 
void GameRules();

//this function runs one game. It for checks either 5 incorrect guesses or correct guess.
//It returns a 0 if the game is over and the player did not guess the letter, otherwise it returns 1. 
int GuessTheLetter(char);

//this function prompts the player to make a guess and returns that guess.
//this function is called from inside the GuessTheLetter( ) function described above 
char GetTheGuess();

//this function takes two arguments, the guess from the player and the solution letter from the file.
//It lets the user know if the guess comes alphabetically before or after the answer.
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match.
//this function is called from inside the GuessTheLetter( ) function described above 
int CompareLetters(char, char);



int main()
{
	//declare additional variables
	//declare FILE pointer
	FILE *letterptr;
	int numGames = 6, i = 0, win;
	char guess, solution;


	//display instructions
	GameRules();


	//connect to the file HINT: use fopen
	letterptr = fopen("letterList.txt", "r");


	//get number of games to play
	printf("How many games would you like to play?\n");
	printf("Please choose a number from (1-8)");
	scanf("%d", &numGames);
	printf("The number of games you choose is %d", numGames);

	//this for loop will allow the player to play more than one game
	//without recompiling
	for (i = 0; i < numGames; i++)
	{
		//get a letter from file - use fscanf
		fscanf(letterptr, " %c", &solution);
		solution = tolower(solution);

		//Play one game (Call PlayOneGame function)
		win = GuessTheLetter(solution);

		//tell the player if they have won or lost
		if (win == 0) printf("you lost, the correct letter is %c", solution);
		if (win == 1) printf("you won! That's what's up");
	}

	//close file
	fclose(letterptr);
	return 0;
}


//Function definitions
//copy and paste prototypes and comments from assignment. Then remove the ; from each

void GameRules()
{
	printf("Welcome to Markenly's Letter Guess Game\n");
	printf("You will enter the number of games you want to play (1 - 6 games)\n");
	printf("You will only have 5 chances to guess each letter\n");
	printf("Let's begin! Ready when you are.");
	return 0;
}


int GuessTheLetter(char solution)
{
	int numGuesses = 0;
	int winOrLose = 0;//SHOULD BE INITIALZED TO 0
	char guess;

	//As long as the user  has not used up the maximum number
	//of guesses and has not guessed correctly 
	//the game will continue using this while loop
	while (numGuesses < MAXGUESSES && winOrLose == 0)
	{
		//function call to GetGuess
		guess = GetTheGuess();

		//function call to CompareSolutionToGuess
		winOrLose = CompareLetters(guess, solution);

		//update counter for number of guesses used
		numGuesses = numGuesses + 1;
	}
	return winOrLose;

}

char GetTheGuess()
{
	char yourGuess;

	printf("Enter your guess");
	scanf(" %c", &yourGuess);

	return yourGuess;
}

int CompareLetters(char guess, char solution)
{
	int win1;

	if (guess == solution)
	{
		printf("Your guess was correct. You won!");
		win1 = 1;
	}
	else if (guess < solution)
	{
		printf("The letter comes after %c", &guess);
		win1 = 0;
	}
	else
	{
		printf("The letter comes before %c", &guess);
		win1 = 0;
	}
	return win1;
}
