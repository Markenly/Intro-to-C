// Markenly Alusma

// 11/18/17

// Drumset Inventory 

// Last Program

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<ctype.h>

#include<string.h>

#define MAXSIZE 50



typedef struct {

	char brand[20];

	char model[20];

	int id;

	int quantityIn;

	double cost;

	double price;

} drumSet;



// Prototypes 

// Greets the user.
void Greeting();


//Displays five entries of drum sets.
//Updates the number of entries.
void CatalogFive(drumSet d1[], int *num);


//Goes through the drumset array.
//Displays the brands, models, ids, quantity, cost and prices.
void Print(drumSet d1[], int num);


//Declares (creates) a file.
//Opens the file.
//Writes catagorlist in the file.
void Save(drumSet d1[], int num);


//Asks user for selection.
//Adds entry.
void Add(drumSet d1[], int *num);


//Deletes an entry.
void Delete(drumSet d1[], int *num);


//Presents ids.
//Asks for an id.
//Returns the id.
int Search(drumSet d1[], int num);


//resets the catalog.
void Clear(int *num);


//Looks through entry.
//Asks uer for price.
//Updates the price of specified entry.
void Update(drumSet d1[], int *num);



int main()

{

	char option;

	int num = 0;

	drumSet d1[MAXSIZE];

	CatalogFive(d1, &num);

	Greeting();


	// Menu
	printf("Menu\n");

	printf("A - Add a new entry\n");

	printf("D - Delete an entry\n");

	printf("P - Print entire catalog\n");

	printf("S - Save the current catalog\n");

	printf("C - Clear entire catalog\n");

	printf("U - Update...\n");

	printf("Q - Quit and exit catalog\n");

	//Get choice
	printf("Enter choice");
	scanf(" %c", &option);

	while (option != 'Q' && option != 'q')
	{

		if (option == 'A' || option == 'a')
		{

			Add(d1, &num);

		}
		else if (option == 'D' || option == 'd')
		{

			Delete(d1, &num);

		}
		else if (option == 'P' || option == 'p')
		{

			Print(d1, num);

		}
		else if (option == 'S' || option == 's')
		{

			Save(d1, num);

		}
		else if (option == 'C' || option == 'c')
		{

			Clear(&num);

		}
		else if (option == 'U' || option == 'u')
		{

			Update(d1, &num);

		}
		else
		{

			printf("Not applicable");

		}

		printf("Menu\n");

		printf("A - Add a new entry\n");

		printf("D - Delete an entry\n");

		printf("P - Print entire catalog\n");

		printf("S - Save the current catalog\n");

		printf("C - Clear entire catalog\n");

		printf("U - Update...\n");

		printf("Q - Quit and exit catalog\n");

		//Get choice

		printf("Enter choice");

		scanf(" %c", &option);

	}

	return 0;

}


//Greets the user.
void Greeting()
{

	printf("Hello and welcome.\n");

	printf("This program helps you create an inventory for drum sets.\n");

	printf("To get you started, 5 shoes have already been entered.\n");

}



//Resets the catalog.
void Clear(int *num)
{

	*num = 0;

}



//Goes through the drumset array.
//Displays the brands, models, ids, quantity, cost and prices.
void Print(drumSet d1[], int num)
{

	int i;

	for (i = 0; i < num; i += 1)

	{

		printf("brand: %s\n", d1[i].brand);

		printf("model: %s\n", d1[i].model);

		printf("id #: %d\n", d1[i].id);

		printf("quantity in stock: %d\n", d1[i].quantityIn);

		printf("cost: $%.2f\n", d1[i].cost);

		printf("price: $%.2f\n", d1[i].price);

	}

	if (num == 0)

	{

		printf("The catalog is clear\n");

	}

}



//Declares (creates) a file.
//Opens the file.
//Writes catagorlist in the file.
void Save(drumSet d1[], int num)
{

	FILE *catptr;

	int i;

	catptr = fopen("catalog.txt", "w");

	for (i = 0; i < num; i += 1)

	{

		fprintf(catptr, "brand: %s\n", d1[i].brand);

		fprintf(catptr, "model: %s\n", d1[i].model);

		fprintf(catptr, "id #: %d\n", d1[i].id);

		fprintf(catptr, "quantity in stock: %d\n", d1[i].quantityIn);

		fprintf(catptr, "cost: $%.2f\n", d1[i].cost);

		fprintf(catptr, "price: $%.2f\n", d1[i].price);

	}

	fclose(catptr);

}



//Asks user for selection.
//Adds entry.
void Add(drumSet d1[], int *num)
{

	int i;

	i = *num;

	printf("enter brand\n");

	scanf("%s", d1[*num].brand);

	printf("enter model\n");

	scanf("%s", d1[*num].model);

	printf("enter id\n");

	scanf("%d", d1[*num].id);

	printf("enter quantity\n"),

		scanf("%d", d1[*num].quantityIn);

	printf("enter cost\n"),

		scanf("%lf", d1[*num].cost);

	printf("enter price\n"),

		scanf("%lf", d1[*num].price);

	*num = *num + 1;

}



//Deletes an entry.
void Delete(drumSet d1[], int *num)
{

	int found;

	found = Search(d1, *num);

	if (found == -1)

	{

		printf("\nThis is not found in the Catalog\n");

	}

	else

	{

		d1[found] = d1[*num - 1];

	}



	*num = *num - 1;

}



//Presents ids.
//Asks for an id.
//Returns the id.
int Search(drumSet d1[], int num)
{

	int tar;

	int i;

	// Present ids

	printf("\nlist of id #s:\n");

	for (i = 0; i < num; i++)
	{
		printf("%d,", d1[i].id);
	}

	//prompt for id
	printf("\nEnter id\n");

	scanf("%d", &tar);

	//locate and return index
	for (i = 0; i < num; i++)
	{
		if (tar == d1[i].id)

			return i;
	}

	return -1;

}



//Looks through entry.
//Asks uer for price.
//Updates the price of specified entry.
void Update(drumSet d1[], int *num)
{

	int found;

	found = Search(d1, *num);

	if (found != -1)
	{
		printf("Enter price update");

		scanf("%lf", d1[*num].price);
	}
	else
	{
		printf("\nThis is not found in the Catalog\n");
	}

}



//Displays five entries.
//Updates the number of entries.
void CatalogFive(drumSet d1[], int *num)
{

	/*char brand[20];

	char model[20];

	int id;

	int quantityIn;

	double cost;

	double price;*/

	*num = 5;

	strcpy(d1[0].brand, "yamaha");

	strcpy(d1[0].model, "live custom");

	d1[0].id = 2046;

	d1[0].quantityIn = 10;

	d1[0].cost = 449.00;

	d1[0].price = 654.00;


	strcpy(d1[1].brand, "pearl");

	strcpy(d1[1].model, "export");

	d1[1].id = 2048;

	d1[1].quantityIn = 8;

	d1[1].cost = 339.00;

	d1[1].price = 578.00;


	strcpy(d1[2].brand, "sonor");

	strcpy(d1[2].model, "s drive");

	d1[2].id = 2050;

	d1[2].quantityIn = 15;

	d1[2].cost = 672.00;

	d1[2].price = 889.00;


	strcpy(d1[3].brand, "dw");

	strcpy(d1[3].model, "performance");

	d1[3].id = 2052;

	d1[3].quantityIn = 4;

	d1[3].cost = 989.00;

	d1[3].price = 1679.00;


	strcpy(d1[4].brand, "gretsch");

	strcpy(d1[4].model, "marquee");

	d1[4].id = 2054;

	d1[4].quantityIn = 5;

	d1[4].cost = 693.00;

	d1[4].price = 1558.00;
}