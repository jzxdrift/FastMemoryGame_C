#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "Board.h"

#define GET_ROW(x) ((x) / 10 - 1)
#define GET_COL(x) ((x) % 10 - 1)

static void hideBoard(Board*);

void initBoard(Board *b)
{
	for(size_t i = 0, letter = 'A'; i < ROWS; ++i)
	{
		for(size_t j = 0; j < COLS; j += 2, ++letter)
		{
			b->cards[i][j].frontSide = (unsigned char)letter;
			b->cards[i][j + 1].frontSide = (unsigned char)letter;
			
			b->cards[i][j].backSide = '*';
			b->cards[i][j + 1].backSide = '*';

			b->cards[i][j].hidden = 1;
			b->cards[i][j + 1].hidden = 1;
		}
	}
}

void shuffleBoard(Board *b)
{
	srand((unsigned)time(NULL));

	for(size_t i = 0; i < ROWS; ++i)
	{
		for(size_t j = 0; j < COLS; ++j)
		{
			size_t randRow = (size_t)rand() % ROWS;
			size_t randCol = (size_t)rand() % COLS;

			Card tmp = b->cards[i][j];
			b->cards[i][j] = b->cards[randRow][randCol];
			b->cards[randRow][randCol] = tmp;
		}
	}
}

void printBoard(Board *b, const size_t rc1, const size_t rc2)
{
	if(rc1 == 0 && rc2 == 0)
		hideBoard(b);

	if(rc1 != 0)
		b->cards[GET_ROW(rc1)][GET_COL(rc1)].hidden = 0;
	if(rc2 != 0)
		b->cards[GET_ROW(rc2)][GET_COL(rc2)].hidden = 0;

	printf("  ");

	for(size_t i = 1; i <= COLS; ++i)
		printf("%zu ", i);
	puts("");

	for(size_t i = 0; i < ROWS; ++i)
	{
		printf("%zu ", i + 1);

		for(size_t j = 0; j < COLS; ++j)
			printf("%c ", b->cards[i][j].hidden
				? b->cards[i][j].backSide
				: b->cards[i][j].frontSide);

		puts("");
	}
}

void checkBoardMatch(Board *b, const size_t rc1, const size_t rc2)
{
	if(b->cards[GET_ROW(rc1)][GET_COL(rc1)].frontSide
		== b->cards[GET_ROW(rc2)][GET_COL(rc2)].frontSide)
	{
		puts("Match!");
		
		b->cards[GET_ROW(rc1)][GET_COL(rc1)].frontSide = ' ';
		b->cards[GET_ROW(rc1)][GET_COL(rc1)].backSide = ' ';

		b->cards[GET_ROW(rc2)][GET_COL(rc2)].frontSide = ' ';
		b->cards[GET_ROW(rc2)][GET_COL(rc2)].backSide = ' ';
	}
}

unsigned isBoardSolved(const Board *b)
{
	for(size_t i = 0; i < ROWS; ++i)
	{
		for(size_t j = 0; j < COLS; ++j)
		{
			if(!isspace(b->cards[i][j].frontSide)
				&& !isspace(b->cards[i][j].backSide))
				return 0;
		}
	}
	puts("Game solved!");

	return 1;
}

unsigned isBoardCardEmpty(const Board *b, const size_t rc)
{
	if(isspace(b->cards[GET_ROW(rc)][GET_COL(rc)].frontSide)
		&& isspace(b->cards[GET_ROW(rc)][GET_COL(rc)].backSide))
	{
		fprintf(stderr, "Card is empty\n");
		return 1;
	}

	return 0;
}

unsigned isBoardCardDuplicate(const size_t rc1, const size_t rc2)
{
	if(rc1 == rc2)
	{
		fprintf(stderr, "Card is duplicate\n");
		return 1;
	}

	return 0;
}

static void hideBoard(Board *b)
{
	for(size_t i = 0; i < ROWS; ++i)
	{
		for(size_t j = 0; j < COLS; ++j)
			b->cards[i][j].hidden = 1;
	}
}
