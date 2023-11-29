#ifndef ANIM_H
#define ANIM_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "types.h"

void print_title();

void print_hand(int face_down, Hand* hand, const char* wFace[], const char* wSuit[]);

void print_winner(int winner, int winValue);

void print_rules();










#endif // !ANIM_H

