#ifndef POKER_H
#define POKER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "animation.h"
#include "types.h"


void shuffle(int wDeck[][13]);

//need suits and face values array
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);

//need suits and face values array
int dealHand(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* hand, int place);

/*discard menu*/
void menu_discard(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* hand, int place);

/*main game loop*/
void loop_game();

/*Main menu*/
void menu_main();

#endif // !POKER_H

