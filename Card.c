#include <stdio.h>
#include <ctype.h>

#include "Card.h"

static void removeCard(Card*);

void initCard(Card *card, char fSide)
{
	card->frontSide = fSide;
	card->backSide = '*';
	card->hidden = 1;
}

void showCard(Card *card)
{
	card->hidden = 0;
}

void hideCard(Card *card)
{
	card->hidden = 1;
}

void swapCards(Card *card, Card *otherCard)
{
	Card tempCard = *card;
	*card = *otherCard;
	*otherCard = tempCard;
}

void printCard(const Card *card)
{
	printf("%c", card->hidden ? card->backSide : card->frontSide);
}

int isCardEmpty(const Card *card)
{
	return isspace(card->frontSide) && isspace(card->backSide);
}

int isCardDuplicate(const Card *card, const Card *otherCard)
{
	return card == otherCard;
}

int isCardMatch(Card *card, Card *otherCard)
{
	if(card->frontSide == otherCard->frontSide)
	{
		puts("Match!");
		removeCard(card);
		removeCard(otherCard);

		return 1;
	}

	return 0;
}

void printCardEmptyError(void)
{
	fprintf(stderr, "Card is empty\n");
}

void printCardDuplicateError(void)
{
	fprintf(stderr, "Card is duplicate\n");
}

static void removeCard(Card *card)
{
	card->frontSide = ' ';
	card->backSide = ' ';
}