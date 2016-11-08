#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

#include "card.h"

enum { FULL_DECK_SZ = 52 };

struct deck {
	struct card *cards;
	size_t length;
};


// Returns a newly-malloc()ed deck structure, which should be freed by calling
// deck_destroy()
struct deck *deck_create(void);

void deck_destroy(struct deck *d);

void deck_print(struct deck *d);

// Randomize all contents of the deck, THIS IS DESTRUCTIVE AND WILL MODIFY
// ANY REFERENCES TO CARDS OUTSIDE THE DECK.
void deck_shuffle(struct deck *d);

// Returns a newly-malloc()ed array of card pointers of length `amount`, which
// should be freed via free() by the caller.
struct card **deck_deal(struct deck *d, size_t amount);

#endif
