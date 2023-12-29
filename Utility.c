#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define MIN 1
#define MAX 6

static int isValidRange(int);

size_t getInput(void)
{
	int input;

	int valid = 0;
	do
	{
		printf("\nEnter row, then column in format XX: ");

		if(scanf("%d", &input) == 1 && isValidRange(input))
			valid = 1;
		else
			fprintf(stderr, "Invalid input, try again\n");

		while(getchar() != '\n');

	} while(!valid);

	return (size_t)input;
}

size_t getRowIndex(size_t num)
{
	return num / 10 - 1;
}

size_t getColIndex(size_t num)
{
	return num % 10 - 1;
}

void clearScreen(void)
{
	printf("\nPress enter to continue...");
	getchar();
	system("cls");
}

static int isValidRange(int num)
{
	return (num / 10 >= MIN && num / 10 <= MAX)
		&& (num % 10 >= MIN && num % 10 <= MAX);
}