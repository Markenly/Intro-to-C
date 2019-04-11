// Markenly Alusma

// 11/23/17

// lab 3 

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<math.h>


// takes two integer arguments and returns the sum of the two arguments
int CalculateSum(int num1, int num2);

//takes two integer arguments and returns the difference of the two arguments
int CalculateDifference(int num1, int num2);

//takes two integer arguments and two integer pointer arguments 
//1. calculate the sum and stores the result in sumptr
//2. calculate the difference and store the result in diffPtr 
void CalculateBoth(int num1, int num2, int*sumPtr, int *diffPtr);


int main()
{
	int num1, num2, sum1, diff1, sum2, diff2, *sumPtr, *diffPtr;

	printf("enter a number");
	scanf("%d", num1);

	printf("enter a number");
	scanf("%d", num2);

	printf("the numbers are %d %d", num1, num2);

	sum1 = CalculateSum(num1, num2);

	printf("%d", sum1);

	diff1 = CalculateDifference(num1, num2);

	printf("%d", diff1);

	CalculateBoth(num1, num2, *sumPtr, *diffPtr);

	sum2 = &sumPtr;
	printf("%d", sum2);

	diff2 = &diffPtr;
	printf("%d", diff2);

	return 0;
}


int CalculateSum(int num1, int num2)
{
	int sum;

	sum = num1 + num2;
	return sum;
}


int CalculateDifference(int num1, int num2)
{
	int diff;

	diff = num1 - num2;
	return diff;
}


void CalculateBoth(int num1, int num2, int*sumPtr, int *diffPtr)
{
	sumPtr = num1 + num2;

	diffPtr = num1 - num2;
}