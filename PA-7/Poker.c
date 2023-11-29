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

//calculate highest hand value
int calcHand(Hand* hand) {
	int handValue = 0;
	int i, j;

	//if all suits are the same
	if (hand->cards[0].col == hand->cards[1].col && hand->cards[1].col == hand->cards[2].col && hand->cards[2].col == hand->cards[3].col && hand->cards[3].col == hand->cards[4].col) {
		//check for royal flush
		if (hand->cards[0].row == 8 && hand->cards[1].row == 9 && hand->cards[2].row == 10 && hand->cards[3].row == 11 && hand->cards[4].row == 12) {
			if (handValue < 10) {
				handValue = 10;
			}

		}
		//check for straight flush
		else if (hand->cards[0].row == hand->cards[1].row - 1 && hand->cards[1].row == hand->cards[2].row - 1 && hand->cards[2].row == hand->cards[3].row - 1 && hand->cards[3].row == hand->cards[4].row - 1) {
			if (handValue < 9) {
				handValue = 9;
			}

		}
		//else flush
		else {
			if (handValue < 6) {
				handValue = 6;
			}

		}

	}
	else {
		//check for four of a kind
		if (hand->cards[0].row == hand->cards[1].row && hand->cards[1].row == hand->cards[2].row && hand->cards[2].row == hand->cards[3].row) {
			if (handValue < 8) {
				handValue = 8;
			}

		}
		else if (hand->cards[1].row == hand->cards[2].row && hand->cards[2].row == hand->cards[3].row && hand->cards[3].row == hand->cards[4].row)
		{
			if (handValue < 8) {
				handValue = 8;
			}
		}

		//check for full house
		if (hand->cards[0].row == hand->cards[1].row && hand->cards[1].row == hand->cards[2].row && hand->cards[3].row == hand->cards[4].row) {
			if (handValue < 7) {
				handValue = 7;
			}
		}
		else if (hand->cards[0].row == hand->cards[1].row && hand->cards[2].row == hand->cards[3].row && hand->cards[3].row == hand->cards[4].row) {
			if (handValue < 7) {
				handValue = 7;
			}
		}

		//check for straight
		if (hand->cards[0].row == hand->cards[1].row - 1 && hand->cards[1].row == hand->cards[2].row -1 && hand->cards[2].row == hand->cards[3].row -1 && hand->cards[3].row == hand->cards[4].row - 1) {
			if (handValue < 5) {
				handValue = 5;
			}
		}

		//check for three of a kind
		if (hand->cards[0].row == hand->cards[1].row && hand->cards[1].row == hand->cards[2].row) {
			if (handValue < 4) {
				handValue = 4;
			}
		}
		else if (hand->cards[1].row == hand->cards[2].row && hand->cards[2].row == hand->cards[3].row) {
			if (handValue < 4) {
				handValue = 4;
			}
		}
		else if (hand->cards[2].row == hand->cards[3].row && hand->cards[3].row == hand->cards[4].row) {
			if (handValue < 4) {
				handValue = 4;
			}
		}

		//check for two pair
		if (hand->cards[0].row == hand->cards[1].row && hand->cards[2].row == hand->cards[3].row) {
			if (handValue < 3) {
				handValue = 3;
			}
		}
		else if (hand->cards[1].row == hand->cards[2].row && hand->cards[3].row == hand->cards[4].row) {
			if (handValue < 3) {
				handValue = 3;
			}
		}
		else if (hand->cards[0].row == hand->cards[1].row && hand->cards[3].row == hand->cards[4].row) {
			if (handValue < 3) {
				handValue = 3;
			}
		}

		//check for pair
		for (i = 0; i < HANDSIZE - 1; i++) {
			for (j = i + 1; j < HANDSIZE; j++) {
				if (hand->cards[i].row == hand->cards[j].row) {
					if (handValue < 2) {
						handValue = 2;
					}
				}
			}
		}

		//if no hands
		if (handValue < 1) {
			handValue = 1;
		}
	}
	return handValue;
}

//calculate winner// 0 for player 1 for computer
void calcWinner(Hand* player, Hand* comp, int* winner, int* handValue) {
	int playerVal = calcHand(player);
	int compVal = calcHand(comp);

	if (playerVal > compVal) {
		*winner = 0;
		*handValue = playerVal;
	}
	else if (compVal > playerVal) {
		*winner = 1;
		*handValue = compVal;
	}
	//check for high face card
	else if(player->cards[4].row > comp->cards[4].row) {
		*winner = 0;
		*handValue = playerVal;
	}
	else if (comp->cards[4].row > player->cards[4].row) {
		*winner = 1;
		*handValue = compVal;
	}
	//check for high suit
	else if (player->cards[4].col > comp->cards[4].col) {
		*winner = 0;
		*handValue = playerVal;
	}
	else if (comp->cards[4].col > player->cards[4].col) {
		*winner = 1;
		*handValue = compVal;
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

//hand must be sorted
int discardDealer(Hand* hand) {
	//calculate holds
	int hold[HANDSIZE] = { 0 };
	int value = calcHand(hand);
	int discards = 0;
	int i,j;

	switch (value) {
	case 1:
		//TODO more logic here
		//determine high cards discard others
		hold[4] = 1;
		hold[3] = 1;
		hold[2] = 1;

		break;
	case 2:
		//discard three
		for (i = 0; i < HANDSIZE - 1; i++) {
			for (j = i + 1; j < HANDSIZE; j++) {
				if (hand->cards[i].row == hand->cards[j].row) {
					hold[i] = 1;
					hold[j] = 1;
				}
			}
		}
		break;
	case 3:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	case 4:
		//discard two
		for (i = 0; i < HANDSIZE - 1; i++) {
			for (j = i + 1; j < HANDSIZE; j++) {
				if (hand->cards[i].row == hand->cards[j].row) {
					hold[i] = 1;
					hold[j] = 1;
				}
			}
		}
		break;
	case 5:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	case 6:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	case 7:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	case 8:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	case 9:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	case 10:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	default:
		//discard none
		for (i = 0; i < HANDSIZE; i++) {
			hold[i] = 1;
		}
		break;
	}

	//return number discarded
	for (i = 0; i < HANDSIZE; i++) {
		if (hold[i] == 0) {
			hand->cards[i].number = 0;
			discards += 1;
		}
	}
	
	return discards;

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
	/*for (i = 0; i < HANDSIZE; i++) {
		printf("c:%s of %s - ", face[comp_hand.cards[i].row], suit[comp_hand.cards[i].col]);
	}*/
	printf("\n");
	for (i = 0; i < HANDSIZE; i++) {
		printf("%s of %s - ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);

	}
	/*sort hands*/
	printf("\n");
	printf("SORTING HAND.....");
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
	/*for (i = 0; i < HANDSIZE; i++) {
		printf("c:%s of %s - ", face[comp_hand.cards[i].row], suit[comp_hand.cards[i].col]);
	}*/
	printf("\n");
	for (i = 0; i < HANDSIZE; i++) {
		printf("%s of %s - ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);

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

	/*re-sort player hand*/
	sortHand(&player_Hand);

	system("cls");
	/*print graphic card list*/
	printf(" -------------------- DEALER----------------------\n");
	print_hand(1, &comp_hand, face, suit);
	printf("\n");
	printf(" ----------------------------------------\n");

	/*dealer discard*/
	discarded = 0;
	discarded = discardDealer(&comp_hand);
	place = dealHand(deck, face, suit, &comp_hand, place);

	printf("Dealer Discards %d cards...\n", discarded);
	
	/*re-sort dealer hand*/
	sortHand(&comp_hand);

	delay(6);

	/*reveal hands*/
	system("cls");

	/*print graphic card list*/
	printf(" -------------------- DEALER----------------------\n");
	print_hand(1, &comp_hand, face, suit);
	printf("\n");
	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, &player_Hand, face, suit);
	printf("\n");

	/*print card list*/
	printf("\n");
	for (i = 0; i < HANDSIZE; i++) {
		printf("%s of %s - ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);

	}
	printf("\n");
	printf(" ----------------------------------------\n");
	printf("Reveal\n");
	printf("1) continue\n");

	choice = 0;
	while (choice != 1) {
		scanf("%d", &choice);
	}

	/*reveal calculate winner*/
	int winner = 0;
	int winValue = 0;

	/*TESTING
	//TODO test straight
	player_Hand.cards[0].row = 8;
	player_Hand.cards[1].row = 9;
	player_Hand.cards[2].row = 10;
	player_Hand.cards[3].row = 11;
	player_Hand.cards[4].row = 12;
	*/

	calcWinner(&player_Hand, &comp_hand, &winner, &winValue);

	system("cls");

	printf(" -------------------- DEALER----------------------\n");
	print_hand(0, &comp_hand, face, suit);
	printf("\n");
	printf(" -------------------- PLAYER HAND-----------------\n");
	print_hand(0, &player_Hand, face, suit);
	printf("\n");
	/*print card list*/
	for (i = 0; i < HANDSIZE; i++) {
		printf("%s of %s - ", face[comp_hand.cards[i].row], suit[comp_hand.cards[i].col]);
	}
	printf("\n");
	for (i = 0; i < HANDSIZE; i++) {
		printf("%s of %s - ", face[player_Hand.cards[i].row], suit[player_Hand.cards[i].col]);

	}
	printf("\n");
	printf(" ----------------------------------------\n");
	//TODO make print function here
	print_winner(winner, winValue);
	printf("\n");
	printf("1)Exit\n");

	choice = 0;
	while (choice != 1) {
		scanf("%d", &choice);
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
			choice = 0;
			system("cls");
			print_title();
			printf("\n");
			printf("1) Play Game\n");
			printf("2) Display Rules\n");
			printf("3) Exit\n");
			break;
		case 2:
			//rules
			system("cls");
			print_rules();
			printf("\n");
			printf("1) Go Back\n");
			choice = 0;
			while (choice != 1) {
				scanf("%d", &choice);
			}
			system("cls");
			print_title();
			printf("\n");
			printf("1) Play Game\n");
			printf("2) Display Rules\n");
			printf("3) Exit\n");
			break;
		case 3:
			//exit
			break;
		}
	}


}



