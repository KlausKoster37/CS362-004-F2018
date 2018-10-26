/*******************************************************************
* Assignment 3: Unit Testing
* File: cardtest1.c
* Card in Test: smithy
*
* Author: Klaus Koster (kosterkl)
* Due Date: 10/28/2018
* CS 362, Fall 2018
*******************************************************************/

// include files
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

/************************************************************
					SMITHY

Expected behavior: Draw (+) 3 cards from the user's deck

Input:
	int currentPlayer,
	int handPos,
	struct gameState *state

Output:
	int (return 0)
************************************************************/

#define TESTCARD "Smity"

struct compareGame
{
	int handCountBefore, handCountAfter = 0;
	int deckCountBefore, deckCountAfter = 0;
	int playedCardCountBefore, playedCardCountAfter = 0;
}


int main(int argc, char* argv[])
{
	// setup our variables/things necessary to start and play the game/card
    struct gameState state;
    struct compareGame testGame;
    int k[10] = {adventurer, council_room, cutpurse, embargo, gardens, minion, mine, village, smithy, tribute};
    int numPlayers = 2;
    int handPosition = 0;
    int seed = 1000;
    int choice1, choice2, choice3, bonus = 0;		// no choices or bonus for smithy card

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	fflush(stdout);


	// WHAT ARE WE GOING TO CHECK??
	// played card gets ++
	// played card gets added to played cards array.. look at this after getting most done.  Could be null w/ seg fault
	// hand count before and after
	// deck count before and after

	// initialize the game
	initializeGame(numPlayers, k, seed, &state);


	



	return 0;
}

