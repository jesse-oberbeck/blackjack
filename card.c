
#include "card.h"

#include <stdio.h>
#include <string.h>

const char *card_suits[] = {
	"Clubs",
	"Diamonds",
	"Hearts",
	"Spades"
};

const char *card_ranks[] = {
	"Jack",
	"Queen",
	"King",
	"Ace"
};


bool card_format(char output[], size_t sz, struct card c)
{
	// TODO: Does not check for valid cards
	if(sz < CARD_BUF_SZ) {
		return false;
	}

	// TODO: Magic number
	if(c.rank > 10) {
		// TODO: Magic number
		snprintf(output, sz, "%s of %s", card_ranks[c.rank - 11],
				card_suits[c.suit]);
	} else {
		snprintf(output, sz, "%d of %s", c.rank, card_suits[c.suit]);
	}

	return true;
}
