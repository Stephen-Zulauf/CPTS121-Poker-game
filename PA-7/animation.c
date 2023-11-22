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
			face = 'A';
			break;
		case 1:
			face = '2';
			break;
		case 2:
			face = '3';
			break;
		case 3:
			face = '4';
			break;
		case 4:
			face = '5';
			break;
		case 5:
			face = '6';
			break;
		case 6:
			face = '7';
			break;
		case 7:
			face = '8';
			break;
		case 8:
			face = '9';
			break;
		case 9:
			face = 'T';
			break;
		case 10:
			face = 'J';
			break;
		case 11:
			face = 'Q';
			break;
		case 12:
			face = 'K';
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