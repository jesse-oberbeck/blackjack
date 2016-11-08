
#include "deck.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct deck *deck_create(void)
{
	struct deck *d = malloc(sizeof(*d));
	if(!d) {
		return NULL;
	}

	d->cards = malloc(FULL_DECK_SZ * sizeof(*d->cards));
	if(!d->cards) {
		free(d);
		return NULL;
	}

	d->length = FULL_DECK_SZ;

	for(int s = 0; s < 4; ++s) {
		for(int rank = 2; rank < 15; ++rank) {
			size_t i = s*13 + (rank - 2);

			d->cards[i].suit = s;
			d->cards[i].rank = rank;
		}
	}

	deck_shuffle(d);

	return d;
}

void deck_destroy(struct deck *d)
{
	if(!d) {
		return;
	}

	free(d->cards);
	free(d);
}

void deck_print(struct deck *d)
{
	if(!d) {
		puts("(nil)");
		return;
	}

	char buf[CARD_BUF_SZ];
	for(size_t n=0; n < d->length; ++n) {
		card_format(buf, sizeof(buf), d->cards[n]);
		printf("%s\n", buf);
	}
}

void deck_shuffle(struct deck *d)
{
	if(!d) {
		return;
	}

	for(size_t curr_slot = 0; curr_slot < FULL_DECK_SZ; ++curr_slot) {
		size_t swap_slot = curr_slot + rand() % (FULL_DECK_SZ - curr_slot);

		struct card tmp = d->cards[curr_slot];
		d->cards[curr_slot] = d->cards[swap_slot];
		d->cards[swap_slot] = tmp;
	}
}

struct card **deck_deal(struct deck *d, size_t amount)
{
	if(!d) {
		return NULL;
	}

	if(amount > d->length) {
		return NULL;
	}

	struct card **pile;
	// 1 + amount to make the last element a NULL pointer
	// to indicate the end of the hand
	pile = calloc(1 + amount, sizeof(*pile));

	if(!pile) {
		return NULL;
	}

	for(size_t n = 0; n < amount; ++n) {
		pile[n] = &d->cards[d->length - n - 1];
	}
	d->length -= amount;

	return pile;
}
