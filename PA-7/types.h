#ifndef TYPER_H
#define TYPER_H

#define HANDSIZE 5

#include <stdio.h>
#include <time.h>

typedef struct card {
	int number;
	/*char row[10];
	char col[10];*/
	int row;
	int col;
} Card;

typedef struct hand {
	Card cards[HANDSIZE];

} Hand;

void delay(int number_of_seconds);


#endif // !TYPER_H

