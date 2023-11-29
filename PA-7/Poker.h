#ifndef POKER_H
#define POKER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "animation.h"
#include "types.h"

/* initialize suit array
const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

initialize face array
const char* face[13] = {0"Deuce", 1"Three", 2"Four", 3"Five", 4"Six", 5"Seven", 6"Eight",
	7"Nine", 8"Ten", 9"Jack", 10"Queen", 11"King", 12"Ace" }; */


void shuffle(int wDeck[][13]);

//sort hand into ascending order
void sortHand(Hand* hand);

//calculate highest hand value
int calcHand(Hand* hand);

//calculate winner
void calcWinner(Hand* player, Hand* comp, int* winner,int* handValue);

//need suits and face values array
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);

//need suits and face values array
int dealHand(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* hand, int place);

//need suits and face values array
int discardDealer(Hand* hand);

/*discard menu*/
int menu_discard(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* hand, int place);

/*main game loop*/
void loop_game();

/*Main menu*/
void menu_main();

#endif // !POKER_H

