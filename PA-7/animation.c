#include "animation.h"

void print_title() {
	printf("  _____    _____              _   _____      _                  _____\n");
	printf(" | ____|  / ____|            | | |  __ \\    | |                |A .  |\n");
	printf(" | |__   | |     __ _ _ __ __| | | |__) |__ | | _____ _ __     | /.\\ |\n");
	printf(" |___ \\  | |    / _` | '__/ _` | |  ___/ _ \\| |/ / _ \\ '__|    |(_._)|\n");
	printf("  ___) | | |___| (_| | | | (_| | | |  | (_) |   <  __/ |       |  |  |\n");
	printf(" |____/   \\_____\\__,_|_|  \\__,_| |_|   \\___/|_|\\_\\___|_|       |____V|\n");
}

void print_hand(int face_down, Hand* hand, const char* wFace[], const char* wSuit[]) {
	int i;
	int faces[5] = {' '};
	int suits[5] = { ' ' };

	for (i = 0; i < HANDSIZE; i++) {
		char face = ' ';
		switch (hand->cards[i].row) {
		case 0:
			face = '2';
			break;
		case 1:
			face = '3';
			break;
		case 2:
			face = '4';
			break;
		case 3:
			face = '5';
			break;
		case 4:
			face = '6';
			break;
		case 5:
			face = '7';
			break;
		case 6:
			face = '8';
			break;
		case 7:
			face = '9';
			break;
		case 8:
			face = 'T';
			break;
		case 9:
			face = 'J';
			break;
		case 10:
			face = 'Q';
			break;
		case 11:
			face = 'K';
			break;
		case 12:
			face = 'A';
			break;
		default:
			face = '?';
			break;
		}
		faces[i] = face;

		switch (hand->cards[i].col) {
		case 0:
			suits[i] = '&';
			break;
		case 1:
			suits[i] = 'v';
			break;
		case 2:
			suits[i] = '%';
			break;
		case 3:
			suits[i] = '^';
			break;
		}
	}

	if (face_down == 0) {
		printf("          _____           _____           _____           _____           _____\n");
		printf("         |%c    |         |%c    |         |%c    |         |%c    |         |%c    |\n", faces[0], faces[1], faces[2], faces[3], faces[4]);
		printf("         |     |         |     |         |     |         |     |         |     |\n");
		printf("         |  %c  |         |  %c  |         |  %c  |         |  %c  |         |  %c  |\n", suits[0], suits[1], suits[2], suits[3], suits[4]);
		printf("         |     |         |     |         |     |         |     |         |     |\n");
		printf("         |____%c|         |____%c|         |____%c|         |____%c|         |____%c|\n", faces[0], faces[1], faces[2], faces[3], faces[4]);
	}
	else {
		printf("          _____           _____            _____           _____          _____\n");
		printf("         |\\ ~ /|         |\\ ~ /|          |\\ ~ /|         |\\ ~ /|        |\\ ~ /|\n");
		printf("         |}}:{{|         |}}:{{|          |}}:{{|         |}}:{{|        |}}:{{|\n");
		printf("         |}}:{{|         |}}:{{|          |}}:{{|         |}}:{{|        |}}:{{|\n");
		printf("	 |}}:{{|         |}}:{{|          |}}:{{|         |}}:{{|        |}}:{{|\n");
		printf("         |/_~_\\|         |/_~_\\|          |/_~_\\|         |/_~_\\|        |/_~_\\|\n");

	}
}

void print_winner(int winner, int winValue) {

	if (winner == 0) {
		printf("You win with ");
	}
	else {
		printf("Computer wins with ");
	}

	switch (winValue) {
	case 1:
		printf("High Card!");
		break;
	case 2:
		printf("One Pair!");
		break;
	case 3:
		printf("Two Pair!");
		break;
	case 4:
		printf("Three of a Kind!");
		break;
	case 5:
		printf("a Straight!");
		break;
	case 6:
		printf("a Flush!");
		break;
	case 7:
		printf("a Full House!");
		break;
	case 8:
		printf("Four of a Kind!");
		break;
	case 9:
		printf("a Straight Flush!");
		break;
	case 10:
		printf("a Royal Flush!");
		break;
	}
}

void print_rules() {
	printf("The Rules of Poker\n");
	printf("\n");
	printf("Poker is played from a standard pack of 52 cards. The cards are ranked (from high to low)\n");
	printf("Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3, 2\n");
	printf("There are four suits. In this version hearts are low spades high ( hearts, diamonds, clubs and spades);.\n");
	printf("\n");
	printf("Each player draws five cards (a hand) and can discard and draw up to three cards from the initial hand.\n");
	printf("Hands are ranked against the other player and whoever has the highest hand wins the round.\n");
	printf("\n");
	printf("How the hands are ranked: \n");
	printf("--------------------------\n");
	printf("1. Royal flush  \n");
	printf("2. Straight Flush \n");
	printf("3. Four of a Kind  \n");
	printf("4. Full House  \n");
	printf("5. Flush   \n");
	printf("6. Straight    \n");
	printf("7. Three of a Kind     \n");
	printf("8. Two Pair      \n");
	printf("9. Pair       \n");
	printf("10. High Card        \n");
	printf("--------------------------\n");
	printf("\n");
	printf("Descriptions of Hand Ranks: \n");
	printf("--------------------------\n");
	printf("\n");
	printf("-Royal Flush- \n");
	printf("A,K,Q,J,T all the same suit \n");
	printf("\n");
	printf("-Straight Flush- \n");
	printf("all 5 cards in order and the same suit\n");
	printf("\n");
	printf("-Four of a Kind-  \n");
	printf("four cards of the same face value\n");
	printf("\n");
	printf("-Full House -\n");
	printf("3 cards of the same face value and 2 cards of the same face value\n");
	printf("\n");
	printf("-Flush-\n");
	printf("all 5 cards the same suit\n");
	printf("\n");
	printf("-Straight-\n");
	printf("all 5 cards in order but not all the same suit\n");
	printf("\n");
	printf("-Three of a Kind-\n");
	printf("Three cards of the same face value\n");
	printf("\n");
	printf("-Two Pair-\n");
	printf("Two pairs of the same face value\n");
	printf("\n");
	printf("-Pair -\n");
	printf("One pair of the same face value \n");
	printf("\n");
	printf("-High Card-\n");
	printf("Any hand which doesn't qualify as any one of the above hands. \n");
	printf("If nobody has a pair or better, then the highest card wins.\n");
	printf("If multiple people tie for the highest card, this version looks at suit.\n");
	printf("--------------------------\n");
}