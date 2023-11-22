#ifndef TYPER_H
#define TYPER_H

#define HANDSIZE 5

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


#endif // !TYPER_H

