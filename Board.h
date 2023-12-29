#ifndef BOARD_H
#define BOARD_H

#include "Card.h"

#define ROWS 6
#define COLS 6

typedef struct
{
	Card cards[ROWS][COLS];
} Board;

void initBoard(Board*);
void shuffleBoard(Board*);
void printBoard(const Board*);

int isBoardSolved(const Board*);

#endif