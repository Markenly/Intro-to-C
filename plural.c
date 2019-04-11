// Markenly Alusma
// Pluralizer


#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 20

//Greets the user
void Greeting();

//Gets the word from the user
char GetWord(char word[])

//Changes word from upper or lower
void UpperLower();

//Determines which rule to choose
void WhichRule();

//Rule 1
void Rule1();

//Rule 2
void Rule2();

//Rule default
void RuleDefault();

//Saves both words to the ouput
void SaveOutput();

int main()
{
	FILE *pluralptr;
	char choice;
	char word1[];

	Greeting();

	printf("Would you like to enter a word Y <yes> or N <no> \n");
	scanf(" %c", &choice);

	while (choice == 'Y' || choice == 'y')
	{
		word1rd(&word1);
	}

	pluralptr = fopen("pluralWords.txt", "w"); //prepares for access






	fclose(pluralptr);
	return 0;
}

void Greeting()
{
	printf("Welcome to the Pluraliezer \n");
}


char GetWord(char word[])
{

	printf("please enter a word");
	scanf("%s", word);
	return word;
}
