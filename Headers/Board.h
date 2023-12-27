#ifndef BOARD_H
#define BOARD_H

#include <stddef.h>

#include "Card.h"

#define ROWS 6
#define COLS 6

typedef struct
{
	Card cards[ROWS][COLS];
} Board;

void initBoard(Board*);
void shuffleBoard(Board*);
void printBoard(Board*, const size_t, const size_t);
void checkBoardMatch(Board*, const size_t, const size_t);
unsigned isBoardCardEmpty(const Board*, const size_t);
unsigned isBoardCardDuplicate(const size_t, const size_t);
unsigned isBoardSolved(const Board*);

#endif
