
#ifndef HAND_H
 #define HAND_H

#include "card.h"

void hand_print(struct card *hand[]);

struct card **hand_add(struct card **hand, struct card *c);

int blackjack_score(struct card *const hand[]);

int blackjack_cmp(struct card *a[], struct card *b[]);

#endif
