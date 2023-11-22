#include "Poker.h"

/* shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

// returns place in deck
int dealHand(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand * hand, int place) {
	int i,j,k;

	for (i = 0; i < HANDSIZE; i++) {

		hand->cards[i].number = i + place + 1;

		/* loop through rows of wDeck */
		for (j = 0; j <= 3; j++)
		{
			/* loop through columns of wDeck for current row */
			for (k = 0; k <= 12; k++)
			{
				/* if slot contains current card, display card */
				if (wDeck[j][k] == i + place + 1)
				{
					/*strcpy(hand->cards[i].col, wFace[k]);
					strcpy(hand->cards[i].row, wSuit[j]);*/

					hand->cards[i].col = j;
					hand->cards[i].row = k;

				}
			}
		}
	}
	return i + place + 1;
}

/*discard menu*/
void menu_discard(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* hand, int place) {
	int i;
	int discards = 3;
	int choice = 0;

	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, hand, wFace, wSuit);
	printf(" -------------------------------------------------\n");
	printf(" Which cards would you like to discard?\n");
	printf(" discards left: %d\n", discards);

	for (i = 0; i < HANDSIZE; i++) {
		printf("%d) %s of %s\n", i+1, wFace[hand->cards[i].row], wSuit[hand->cards[i].col]);
	}

	while (choice != 6) {

		scanf("%d", &choice);

		if (discards == 0 && choice != 6) {
			switch (choice) {
			default:
				printf(" -------------------- PLAYER HAND-----------------\n");
				print_hand(0, hand, wFace, wSuit);
				printf(" -------------------------------------------------\n");
				printf(" No Discards Left\n");
				printf("Enter 6 to exit\n");
			}
		}
		else {
			switch (choice) {
			case 1:
				//prompt
				break;
			case 2:
				//prompt
				break;
			case 3:
				//prompt
				break;
			case 4:
				//prompt
				break;
			case 5:
				//prompt
				break;
			case 6:
				//exit
				break;
			default:
				printf("invalid choice");
				break;
			}
		}
	}
}

/*main game loop*/
void loop_game() {
	/*init place in deck*/
	int place = 0;

	/*init hands*/
	Hand comp_hand = { 0,0,0 };
	Hand player_Hand = { 0,0,0 };

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	/* seed random-number generator */
	srand((unsigned)time(NULL));

	shuffle(deck);
	place = dealHand(deck, face, suit, &comp_hand, place);
	place = dealHand(deck, face, suit, &player_Hand, place);
	//deal(deck, face, suit);

	/*print graphic card list*/
	printf(" -------------------- DEALER----------------------\n");
	print_hand(1, &comp_hand, face, suit);
	printf("\n");
	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, &player_Hand, face, suit);
	printf("\n");
	/*print card list*/
	int i;
	for (i = 0; i < HANDSIZE; i++) {
		printf("c:%s of %s - ", face[comp_hand.cards[i].row], suit[comp_hand.cards[i].col]);
	}
	printf("\n");
	for (i = 0; i < HANDSIZE; i++) {
		printf("p:%s of %s - ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);

	}
	printf("\n");
	printf(" ----------------------------------------\n");
	printf("Discard Cards?\n");
	printf("1) Discard\n");
	printf("2) Hold\n");

	/*change out cards*/
	int choice = 0;

	while (choice != 2) {

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			//discard menu
			system("cls");
			menu_discard(deck, face, suit, &player_Hand, place);
			break;
		case 2:
			//continue loop
			break;
		default:
			break;
		}
	}

}

/*Main menu*/
void menu_main() {

	print_title();
	printf("\n");
	printf("1) Play Game\n");
	printf("2) Display Rules\n");
	printf("3) Exit\n");

	int choice = 0;

	while (choice != 3) {

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			//play
			system("cls");
			loop_game();
			break;
		case 2:
			//rules
			break;
		case 3:
			//exit
			break;
		}
	}


}



