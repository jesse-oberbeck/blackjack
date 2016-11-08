CPPFLAGS+=-Wall -Wextra -Wpedantic
CPPFLAGS+=-Wwrite-strings -Wstack-usage=1024 -Wfloat-equal
CPPFLAGS+=-Waggregate-return -Winline

CFLAGS+=-std=c11

BIN=blackjack
OBJS=blackjack.o card.o deck.o hand.o

.PHONY: clean debug profile

$(BIN): $(OBJS)

debug: CFLAGS+=-g
debug: $(BIN)

# Profiling requires flags for both compiler and linker
profile: CFLAGS+=-pg
profile: LDFLAGS+=-pg
profile: $(BIN)

clean:
	$(RM) $(OBJS) $(BIN)
