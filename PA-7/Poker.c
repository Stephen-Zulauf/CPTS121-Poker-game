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

//sort hand into ascending order
void sortHand(Hand* hand) {
	int i,j;
	int minIndex;
	Card temp = { 0,0,0 };

	//sort by suit
	for (i = 0; i < HANDSIZE-1; i++) {

		minIndex = i;
		for (j = i + 1; j < HANDSIZE; j++) {
			if (hand->cards[j].col < hand->cards[minIndex].col) {
				minIndex = j;
			}
		}

		//swap
		if (minIndex != i) {
			temp = hand->cards[i];
			hand->cards[i] = hand->cards[minIndex];
			hand->cards[minIndex] = temp;
		}
	}

	//sort by face
	for (i = 0; i < HANDSIZE - 1; i++) {

		minIndex = i;
		for (j = i + 1; j < HANDSIZE; j++) {
			if (hand->cards[j].row < hand->cards[minIndex].row) {
				minIndex = j;
			}
		}

		//swap
		if (minIndex != i) {
			temp = hand->cards[i];
			hand->cards[i] = hand->cards[minIndex];
			hand->cards[minIndex] = temp;
		}
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

		if (hand->cards[i].number == 0) {

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
		
	}
	return i + place + 1;
}

//need suits and face values array
int dealDealer(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* hand, int place) {
	//calculate holds
	int discard = 0;
	int handValue = 0;
	int hold[HANDSIZE] = { 0 };
	int i;

	//if all suits are the same
	if (hand->cards[0].col == hand->cards[1].col && hand->cards[1].col == hand->cards[2].col && hand->cards[2].col == hand->cards[3].col && hand->cards[3].col == hand->cards[4].col) {
		//check for royal flush
		
		//check for straight flush

		//check for flush
	}

	for (i = 0; i < HANDSIZE; i++) {

		

		//check for four of a kind

		//check for full house

		

		//check for straight

		//check for three of a kind

		//check for two pair

		//check for pair

		//calc high card
	}
	

}

/*discard menu*/
int menu_discard(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* hand, int place) {
	int i;
	int discards = 3;
	int choice =  0;
	Hand choices;

	for (i = 0; i < HANDSIZE; i++) {
		choices.cards[i].col = 0;
		choices.cards[i].row = 0;
		choices.cards[i].number = 0;
	}

	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, hand, wFace, wSuit);
	printf(" -------------------------------------------------\n");
	printf(" Which cards would you like to discard?\n");

	printf(" discards left: %d\n", discards);

	for (i = 0; i < HANDSIZE; i++) {
		printf("%d) %s of %s\n", i+1, wFace[hand->cards[i].row], wSuit[hand->cards[i].col]);
	}
	printf("6) Exit\n");

	while (choice != 6) {

		scanf("%d", &choice);
		
		switch (choice) {
		case 6:
			//exit
			break;
		default:
			if (choice > 0 && choice <= 5 && discards > 0) {
				if (choices.cards[choice-1].number == 0) {
					choices.cards[choice-1].number = hand->cards[choice-1].number;
					choices.cards[choice-1].row = hand->cards[choice-1].row;
					choices.cards[choice-1].col = hand->cards[choice-1].col;
					hand->cards[choice-1].number = 0;
					discards--;
				}
				else {
					hand->cards[choice-1].number = choices.cards[choice-1].number;
					hand->cards[choice-1].row = choices.cards[choice-1].row;
					hand->cards[choice-1].col = choices.cards[choice-1].col;
					choices.cards[choice-1].number = 0;
					discards++;
				}
				system("cls");
				printf(" -------------------- PLAYER HAND-----------------\n");
				print_hand(0, hand, wFace, wSuit);
				printf(" -------------------------------------------------\n");
				printf(" Which cards would you like to discard?\n");

				printf(" discards left: %d\n", discards);
				printf("-----Discards:------\n");
				for (i = 0; i < HANDSIZE; i++) {
					if (choices.cards[i].number != 0) {
						printf("%d) %s of %s\n", i + 1, wFace[choices.cards[i].row], wSuit[choices.cards[i].col]);
					}
					
				}
				printf("-----------\n");

				for (i = 0; i < HANDSIZE; i++) {
					if (hand->cards[i].number != 0) {
						printf("%d) %s of %s\n", i + 1, wFace[hand->cards[i].row], wSuit[hand->cards[i].col]);
					}
				}
				printf("6) Confirm\n");
				choice = 0;
			}
			else if (choice > 0 && choice <= 5 && discards == 0) {
				if (hand->cards[choice - 1].number == 0 && choices.cards[choice - 1].number != 0) {
					hand->cards[choice - 1].number = choices.cards[choice - 1].number;
					hand->cards[choice - 1].row = choices.cards[choice - 1].row;
					hand->cards[choice - 1].col = choices.cards[choice - 1].col;
					choices.cards[choice - 1].number = 0;
					discards++;

					system("cls");
					printf(" -------------------- PLAYER HAND-----------------\n");
					print_hand(0, hand, wFace, wSuit);
					printf(" -------------------------------------------------\n");
					printf("Which cards would you like to discard?\n");

					printf(" discards left: %d\n", discards);
					printf("-----Discards:------\n");
					for (i = 0; i < HANDSIZE; i++) {
						if (choices.cards[i].number != 0) {
							printf("%d) %s of %s\n", i + 1, wFace[choices.cards[i].row], wSuit[choices.cards[i].col]);
						}

					}
					printf("-----------\n");

					for (i = 0; i < HANDSIZE; i++) {
						if (hand->cards[i].number != 0) {
							printf("%d) %s of %s\n", i + 1, wFace[hand->cards[i].row], wSuit[hand->cards[i].col]);
						}
					}
					printf("6) Confirm\n");
					choice = 0;
				}
				else {
					system("cls");
					printf(" -------------------- PLAYER HAND-----------------\n");
					print_hand(0, hand, wFace, wSuit);
					printf(" -------------------------------------------------\n");
					printf(" No more discards\n");

					printf(" discards left: %d\n", discards);
					printf("-----Discards:------\n");
					for (i = 0; i < HANDSIZE; i++) {
						if (choices.cards[i].number != 0) {
							printf("%d) %s of %s\n", i + 1, wFace[choices.cards[i].row], wSuit[choices.cards[i].col]);
						}

					}
					printf("-----------\n");

					for (i = 0; i < HANDSIZE; i++) {
						if (hand->cards[i].number != 0) {
							printf("%d) %s of %s\n", i + 1, wFace[hand->cards[i].row], wSuit[hand->cards[i].col]);
						}
					}
					printf("6) Confirm\n");
					choice = 0;

				}


			}
			else {
				system("cls");
				printf(" -------------------- PLAYER HAND-----------------\n");
				print_hand(0, hand, wFace, wSuit);
				printf(" -------------------------------------------------\n");
				printf(" Please Enter Valid choice\n");

				printf(" discards left: %d\n", discards);
				printf("-----Discards:------\n");
				for (i = 0; i < HANDSIZE; i++) {
					if (choices.cards[i].number != 0) {
						printf("%d) %s of %s\n", i + 1, wFace[choices.cards[i].row], wSuit[choices.cards[i].col]);
					}

				}
				printf("-----------\n");

				for (i = 0; i < HANDSIZE; i++) {
					if (hand->cards[i].number != 0) {
						printf("%d) %s of %s\n", i + 1, wFace[hand->cards[i].row], wSuit[hand->cards[i].col]);
					}
				}
				printf("6) Confirm\n");
				choice = 0;

			}

		}
		

		
	}
	return discards;
}

/*main game loop*/
void loop_game() {
	/*init place in deck*/
	int place = 0;

	/*number of cards discarded*/
	int discarded = 3;

	/*init hands*/
	Hand comp_hand = { 0,0,0 };
	Hand player_Hand = { 0,0,0 };

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King", "Ace" };

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
	/*sort hands*/
	delay(3);
	sortHand(&comp_hand);
	sortHand(&player_Hand);
	system("cls");

	/*print graphic card list*/
	printf(" -------------------- DEALER----------------------\n");
	print_hand(1, &comp_hand, face, suit);
	printf("\n");
	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, &player_Hand, face, suit);
	printf("\n");
	/*print card list*/
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
			discarded = menu_discard(deck, face, suit, &player_Hand, place);
			if (discarded == 3) {
				//no cards discarded
				choice = 0;
				system("cls");
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

			}
			else {
				//cards discarded
				choice = 2;
				system("cls");
				/*print graphic card list*/
				printf("\n");
				printf(" -------------------- PLAYER HAND-----------------\n");
				print_hand(1, &player_Hand, face, suit);
				printf("\n");
				printf(" ----------------------------------------\n");
				printf("Discarded:\n");
				for (i = 0; i < HANDSIZE; i++) {
					if (player_Hand.cards[i].number == 0) {
						printf("%s of %s -\n ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);
					}
				}
				printf("\n");
				delay(3);
				/*draw new cards*/
				place = dealHand(deck, face, suit, &player_Hand, place);
				system("cls");
				/*print graphic card list*/
				printf("\n");
				printf(" -------------------- PLAYER HAND-----------------\n");
				print_hand(0, &player_Hand, face, suit);
				printf("\n");
				printf(" ----------------------------------------\n");
				printf("New Hand:\n");
				for (i = 0; i < HANDSIZE; i++) {
					printf("%s of %s -\n ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);
				}
				delay(3);
				
			}
			break;
		case 2:
			//continue loop
			break;
		default:
			break;
		}
	}

	/*sort hands*/
	sortHand(&comp_hand);
	sortHand(&player_Hand);

	/*dealer draw*/
	//TODO

	system("cls");
	/*print graphic card list*/
	printf(" -------------------- DEALER----------------------\n");
	print_hand(1, &comp_hand, face, suit);
	printf("\n");

	/*print card list*/
	for (i = 0; i < HANDSIZE; i++) {
		printf("c:%s of %s - ", face[comp_hand.cards[i].row], suit[comp_hand.cards[i].col]);
	}
	printf("\n");
	printf(" ----------------------------------------\n");
	printf("Dealer Discards:\n");
	//check for discards in for loop
	//TODO

	delay(3);

	/*reveal hands*/

	/*print graphic card list*/
	printf(" -------------------- DEALER----------------------\n");
	print_hand(1, &comp_hand, face, suit);
	printf("\n");
	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, &player_Hand, face, suit);
	printf("\n");
	/*print card list*/
	for (i = 0; i < HANDSIZE; i++) {
		printf("c:%s of %s - ", face[comp_hand.cards[i].row], suit[comp_hand.cards[i].col]);
	}
	printf("\n");
	for (i = 0; i < HANDSIZE; i++) {
		printf("p:%s of %s - ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);

	}
	printf("\n");
	printf(" ----------------------------------------\n");
	printf("Reveal\n");
	printf("1) continue\n");

	choice = 0;
	while (choice != 1) {
		scanf("%d", &choice);
	}

	/*calculate winner*/
	//TODO

	printf(" -------------------- DEALER----------------------\n");
	print_hand(0, &comp_hand, face, suit);
	printf("\n");
	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, &player_Hand, face, suit);
	printf("\n");
	/*print card list*/
	for (i = 0; i < HANDSIZE; i++) {
		printf("c:%s of %s - ", face[comp_hand.cards[i].row], suit[comp_hand.cards[i].col]);
	}
	printf("\n");
	for (i = 0; i < HANDSIZE; i++) {
		printf("p:%s of %s - ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);

	}
	printf("\n");
	printf(" ----------------------------------------\n");
	// player or dealer wins with....


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



