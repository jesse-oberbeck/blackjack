#ifndef CARD_H
#define CARD_H

#include <stdbool.h>
#include <stdlib.h>

enum suit_name {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum {
	JACK = 11,
	QUEEN,
	KING,
	ACE
};

enum { CARD_BUF_SZ = 18 };

extern const char *card_suits[];

struct card {
	int rank;
	enum suit_name suit;
};


bool card_format(char output[], size_t sz, struct card c);

#endif
