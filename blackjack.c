#define _XOPEN_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "card.h"
#include "deck.h"
#include "hand.h"

int main(int argc, char *argv[])
{
	bool silent = false;
	int num_of_cards = 5;

	int c;
	while(-1 < (c = getopt(argc, argv, "n:s"))) {
		switch(c) {
			case 's':
				silent = true;
				break;
			case 'n':
				//TODO: Add in error checking for strtol
				num_of_cards = strtol(optarg, NULL, 10);
				break;
			default:
				printf("Default option handler got '%c'\n", c);
		}
	}

	srand(time(NULL));

	struct deck *pile = deck_create();

	struct card **hand = deck_deal(pile, num_of_cards);

	hand_print(hand);

	// Do not print the score in silent mode
	if(!silent) {
		printf("%d\n", blackjack_score(hand));
	}

	struct card **newcard = deck_deal(pile, 1);
	hand = hand_add(hand, *newcard);
	hand_print(hand);
	free(hand);
	//puts("After hand free");
	free(newcard);
	deck_destroy(pile);
}
