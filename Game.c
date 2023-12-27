#include <stddef.h>

#include "Board.h"
#include "Utility.h"

void startGame(void)
{
	Board board;
	int input1, input2;

	initBoard(&board);
	shuffleBoard(&board);

	while(!isBoardSolved(&board))
	{
		printBoard(&board, 0, 0);

		unsigned cardEmpty = 0;
		do 
		{
			getInput(&input1);
			cardEmpty = isBoardCardEmpty(&board, (size_t)input1);
			printBoard(&board, (size_t)input1, 0);

		} while(cardEmpty);

		unsigned cardDuplicate = 0;
		do 
		{
			getInput(&input2);
			cardEmpty = isBoardCardEmpty(&board, (size_t)input2);
			cardDuplicate = isBoardCardDuplicate((size_t)input1, (size_t)input2);
			printBoard(&board, (size_t)input1, (size_t)input2);

		} while(cardEmpty || cardDuplicate);

		checkBoardMatch(&board, (size_t)input1, (size_t)input2);
		clearScreen();
	}
}