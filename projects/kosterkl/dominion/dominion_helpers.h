#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

// ******************************************** THIS LINE NEEDS EDITED ************************************************  ADD FUNCITON SIGNATURES HERE

// plays the smithy card given the current player, hand position, and game state
int playSmithy(int currentPlayer, int handPos, struct gameState *state);

// plays the adventurer card given the current player, a temp hand array, and the game state
int playAdventurer(int currentPlayer,  int temphand[], struct gameState *state);


#endif
