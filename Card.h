#ifndef CARD_H
#define CARD_H

typedef struct
{
	char frontSide;
	char backSide;
	int hidden;
} Card;

void initCard(Card*, char);
void showCard(Card*);
void hideCard(Card*);
void swapCards(Card*, Card*);
void printCard(const Card*);

int isCardEmpty(const Card*);
int isCardDuplicate(const Card*, const Card*);
int isCardMatch(Card*, Card*);

void printCardEmptyError(void);
void printCardDuplicateError(void);

#endif