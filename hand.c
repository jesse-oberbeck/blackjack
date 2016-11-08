
#include "hand.h"

#include <stdio.h>

void hand_print(struct card *hand[])
{
	if(!hand) {
		return;
	}

	char buf[CARD_BUF_SZ];

	while(*hand != NULL) {
		card_format(buf, sizeof(buf), **hand);
		puts(buf);
		++hand;
	}
}

int blackjack_score(struct card *const hand[])
{
	if(!hand) {
		return 0;
	}

	int score = 0;
	int num_aces = 0;

	while(*hand) {
		// Process number cards by their number
		if((*hand)->rank < 11) {
			score += (*hand)->rank;
		} else if((*hand)->rank == ACE) {
			score += 11;
			++num_aces;
		} else {
			score += 10;
		}

		++hand;
	}

	// If we busted and there are aces, turn their 11s into 1s
	while(num_aces-- && score > 21) {
		score -= 10;
	}

	return score;
}

int blackjack_cmp(struct card *a[], struct card *b[])
{
	return blackjack_score(a) - blackjack_score(b);
}


struct card **hand_add(struct card **hand, struct card *c)
{
	//printf("sizeof hand: %ld\n", sizeof(**hand));

	hand = realloc(hand, (sizeof(struct card) * 8));

	//printf("sizeof hand: %ld\n", sizeof(**hand));
	int i = 0;
	for(; hand[i + 1] != NULL; ++i);
	hand[i + 1] = c;
	hand[i + 2] = NULL;
	printf("i: %d\n", i);
	return(hand);
}


