#include <stddef.h>

#include "Card.h"
#include "Board.h"
#include "Utility.h"

void startGame(void)
{
	Board board;
	initBoard(&board);
	shuffleBoard(&board);

	while(!isBoardSolved(&board))
	{
		size_t input, otherInput;
		size_t row, col, otherRow, otherCol;

		printBoard(&board);

		int cardEmpty = 0;
		do 
		{
			input = getInput();
			row = getRowIndex(input);
			col = getColIndex(input);

			if(!(cardEmpty = isCardEmpty(&(board.cards[row][col]))))
				showCard(&(board.cards[row][col]));
			else
				printCardEmptyError();

			printBoard(&board);

		} while(cardEmpty);

		int cardDuplicate = 0;
		do 
		{
			otherInput = getInput();
			otherRow = getRowIndex(otherInput);
			otherCol = getColIndex(otherInput);

			if(!(cardEmpty = isCardEmpty(&(board.cards[otherRow][otherCol]))))
			{
				if(!(cardDuplicate = isCardDuplicate(&(board.cards[row][col]),
					&(board.cards[otherRow][otherCol]))))
					showCard(&(board.cards[otherRow][otherCol]));
				else
					printCardDuplicateError();
			}
			else
				printCardEmptyError();

			printBoard(&board);

		} while(cardEmpty || cardDuplicate);

		if(!isCardMatch(&(board.cards[row][col]), &(board.cards[otherRow][otherCol])))
		{
			hideCard(&(board.cards[row][col]));
			hideCard(&(board.cards[otherRow][otherCol]));
		}

		clearScreen();
	}
}