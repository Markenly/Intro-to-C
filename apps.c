// Markenly Alusma
//COP 2220
//Large Program 2

//precompiler directives
#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>	    	   

// Displays the list of apps available
//prompts for the user’s selection and sets the value of the selection
void DisplayApps(char *selectionPtr);

//sets the cost of the item based on value stored in purchase
void SetCost(char selection, double *costPtr);

//Displays the codes for the user to input money - gets user input amounts
//compares the int codes and updates the deposit amount
void PaymentOptions(double *depositPtr, double cost);

//compares the amount the user has in deposits to the price of app selected.
//It returns 1 if the amount is enough to cover the cost, 0 if there is not enough.
int Compare(double deposit, double choiceCost);

//uses PaymentOptions function to display and collect dollar amounts from the user
//uses Compare function to keep comparing the added deposited amount to the item cost.
void Pay(double *depositPtr, double choiceCost);

//calculates the amount of leftover from your deposits
void GetChange(double *depositPtr, double choiceCost);

//Asks the user if they want another app
void DoItAgain(char *quitPtr);


int main(void)
{
	char selection;
	double amount;
	double InputAmount;
	char quit;
	InputAmount = 0;

	do
	{
		DisplayApps(&selection);
		//printf("%c", selection);



		SetCost(selection, &amount);
		//printf("%f", amount);

		Pay(&InputAmount, amount);

		GetChange(&InputAmount, amount);
		printf("\n You have purchased: %c", selection);
		printf("\n\n You have %.2f left\n", InputAmount);


		DoItAgain(&quit);
	} while (quit == 'Y' || quit == 'y');
	printf("\n You have: %.2f credit available for next purchase\n ", InputAmount);
	printf("\n Thank you for purchasing!\n\n");





	return (0);
}



void DisplayApps(char *selectionPtr)
{
	char userSelect;
	printf("Welcome to Mar'Kenly's APP STORE\n");
	printf("\n****************************\n\n");

	printf("HERE ARE THE SELECTIONS:\n\n");
	printf("L -- LogMeIn Ignition      1399.99\n");
	printf("V -- VIP Black              999.99\n");
	printf("F -- Facetune                 3.99\n");
	printf("T -- Tap Menu               399.99\n");
	printf("M -- Minecraft                6.99\n");
	printf("\n\n\nPlease enter a selection:");
	scanf(" %c", &userSelect);
	*selectionPtr = userSelect;

}



void SetCost(char selection, double *costPtr)
{
	if (selection == 'L' || selection == 'l')
	{
		*costPtr = 1399.99;

	}
	else if (selection == 'V' || selection == 'v')
	{

		*costPtr = 999.99;
	}
	else if (selection == 'F' || selection == 'f')
	{

		*costPtr = 3.99;
	}
	else if (selection == 'T' || selection == 't')
	{

		*costPtr = 399.99;
	}

	else if (selection == 'M' || selection == 'm')
	{

		*costPtr = 6.99;
	}

}



void PaymentOptions(double *depositPtr, double cost)
{
	int userMoney;
	printf(" You have %.2f in your bank account\n", *depositPtr);
	printf(" The item cost %.2f\n", cost);
	printf("\nPlease credit your money by selection:\n\n");
	printf("\n--- 1   1000.00\n");
	printf("--- 2    500.00\n");
	printf("--- 3    100.00\n");
	printf("--- 4     10.00\n");
	printf("\nDeposit Amount:\n");
	scanf("%d", &userMoney);

	if (userMoney == 1)
	{

		*depositPtr += 1000.00;

	}

	else if (userMoney == 2)
	{

		*depositPtr += 500.00;
	}

	else if (userMoney == 3)
	{

		*depositPtr += 100.00;
	}

	else if (userMoney == 4)
	{

		*depositPtr += 10.00;
	}


}



int Compare(double deposit, double choiceCost)
{

	if (deposit >= choiceCost)
		return 1;
	else
		return 0;

}



void Pay(double *depositPtr, double choiceCost)
{

	while (Compare(*depositPtr, choiceCost) != 1)
	{
		printf("\n---------------------------------------\n");
		printf("\n You do not have enough in your bank\n\n");
		PaymentOptions(depositPtr, choiceCost);
	}

}



void GetChange(double *depositPtr, double choiceCost)
{
	*depositPtr -= choiceCost;

}



void DoItAgain(char *quitPtr)
{
	printf("\n Do you want to make another purchase?");
	scanf(" %c", quitPtr);



}
