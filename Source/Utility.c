#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 6

void getInput(int *inp)
{
	unsigned valid = 0;
	do
	{
		printf("\nEnter row, then column in format XX: ");

		if(scanf("%d", inp) == 1 && (*inp / 10 >= MIN && *inp / 10 <= MAX)
			&& (*inp % 10 >= MIN && *inp % 10 <= MAX))
			valid = 1;
		else
			fprintf(stderr, "Invalid input, try again\n");

		while(getchar() != '\n');

	} while(!valid);
}

void clearScreen(void)
{
	printf("\nPress enter to continue...");
	getchar();
	system("cls");
}
