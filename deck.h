#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum Suit - Enumeration of card suits.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum Suit
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} suit_t;

/**
 * struct Card - Playing card
 *
 * @face_value: Face value of the card (e.g., "Ace" to "King").
 * @suit: Suit of the card.
 */
typedef struct Card
{
	const char *face_value;
	const suit_t suit;
} card_t;

/**
 * struct DeckNode - Node in a deck of cards
 *
 * @card: Pointer to the card of the node.
 * @prev: Pointer to the previous node in the deck.
 * @next: Pointer to the next node in the deck.
 */
typedef struct DeckNode
{
	const card_t *card;
	struct DeckNode *prev;
	struct DeckNode *next;
} deck_node_t;

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the head of the deck.
 *
 * Description: This function sorts a deck of cards in ascending order.
 * It uses a specific sorting algorithm; replace it
 * with your actual sorting logic as needed.
 */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
