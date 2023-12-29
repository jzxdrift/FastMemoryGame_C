#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"
#include "Board.h"

void initBoard(Board *board)
{
	for(size_t i = 0, face = 'A'; i < ROWS; ++i)
	{
		for(size_t j = 0; j < COLS; j += 2, ++face)
		{
			initCard(&(board->cards[i][j]), (char)face);
			initCard(&(board->cards[i][j + 1]), (char)face);
		}
	}
}

void shuffleBoard(Board *board)
{
	srand((unsigned)time(NULL));

	for(size_t i = 0; i < ROWS; ++i)
	{
		for(size_t j = 0; j < COLS; ++j)
			swapCards(&(board->cards[i][j]),
				&(board->cards[(size_t)rand() % ROWS][(size_t)rand() % COLS]));
	}
}

void printBoard(const Board *board)
{
	printf("  ");

	for(size_t i = 1; i <= COLS; ++i)
		printf("%zu ", i);
	puts("");

	for(size_t i = 0; i < ROWS; ++i)
	{
		printf("%zu ", i + 1);

		for(size_t j = 0; j < COLS; ++j)
		{
			printCard(&(board->cards[i][j]));
			printf(" ");
		}

		puts("");
	}
}

int isBoardSolved(const Board *board)
{
	for(size_t i = 0; i < ROWS; ++i)
	{
		for(size_t j = 0; j < COLS; ++j)
		{
			if(!isCardEmpty(&(board->cards[i][j])))
				return 0;
		}
	}
	puts("Game solved!");

	return 1;
}
