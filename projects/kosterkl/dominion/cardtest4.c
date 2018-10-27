/*******************************************************************
* Assignment 3: Unit Testing
* File: cardtest4.c
* Card in Test: village
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
#include <string.h>

/************************************************************
                VILLAGE

Expected behavior: Draw (+) 1 card from user's deck, +2 actions

Input:
    int currentPlayer,
    int handPos,
    struct gameState *state

Output:
    int (return 0)
************************************************************/

#define TESTCARD "Village"


struct compareGame
{
    int handCount;
    int deckCount;
    int playedCardCount;
    int playedSuccessfully;
    int numActions;
    int numBuys;

    // this represents ALL game cards (both victory and regular kingdom cards)
    // So, iterating over the entire things is checking all the cards in the game for state changes
    int gameCards[treasure_map + 1];
    char* gameCardNames[treasure_map + 1];
};

void asserttrue(int value, char* test, int before, int after);


int main(int argc, char* argv[])
{
    // setup our variables/things necessary to start and play the game/card
    struct gameState state;
    struct compareGame before;
    struct compareGame after;
    before.gameCardNames[0] = "curse";
    before.gameCardNames[1] = "estate";
    before.gameCardNames[2] = "duchy";
    before.gameCardNames[3] = "province";
    before.gameCardNames[4] = "copper";
    before.gameCardNames[5] = "silver";
    before.gameCardNames[6] = "gold";
    before.gameCardNames[7] = "adventurer";
    before.gameCardNames[8] = "council_room";
    before.gameCardNames[9] = "feast";
    before.gameCardNames[10] = "gardens";
    before.gameCardNames[11] = "mine";
    before.gameCardNames[12] = "remodel";
    before.gameCardNames[13] = "smithy";
    before.gameCardNames[14] = "village";
    before.gameCardNames[15] = "baron";
    before.gameCardNames[16] = "great_hall";
    before.gameCardNames[17] = "minion";
    before.gameCardNames[18] = "steward";
    before.gameCardNames[19] = "tribute";
    before.gameCardNames[20] = "ambassador";
    before.gameCardNames[21] = "cutpurse";
    before.gameCardNames[22] = "embargo";
    before.gameCardNames[23] = "outpost";
    before.gameCardNames[24] = "salvager";
    before.gameCardNames[25] = "sea_hag";
    before.gameCardNames[26] = "treasure_map";
    int k[10] = { adventurer, council_room, cutpurse, embargo, gardens, minion, mine, village, smithy, tribute };
    int numPlayers = 2;
    int handPosition = 0;
    int seed = 1000;
    // no choices or bonus for smithy card
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    char gameCardString[100];

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    fflush(stdout);

    // initialize the game
    initializeGame(numPlayers, k, seed, &state);

    // get initial state of the game before playing smithy
    before.handCount = numHandCards(&state);
    before.deckCount = state.deckCount[0];		// player 0's (1st player) deck count
    before.playedCardCount = state.playedCardCount;
    before.numActions = state.numActions;
    before.playedSuccessfully = 0;
    before.numBuys = state.numBuys;

    int i = 0;
    for (i = 0; i < treasure_map + 1; i++)
    {
        before.gameCards[i] = state.supplyCount[i];
    }

    // play smithy card
    after.playedSuccessfully = cardEffect(village, choice1, choice2, choice3, &state, handPosition, &bonus);
    assertTest(before.playedSuccessfully == after.playedSuccessfully, "Card played", before.playedSuccessfully, after.playedSuccessfully);

    // update test struct after playing
    after.handCount = numHandCards(&state);
    after.deckCount = state.deckCount[0];
    after.playedCardCount = state.playedCardCount;
    after.numActions = state.numActions;
    after.numBuys = state.numBuys;

    for (i = 0; i < treasure_map + 1; i++)
    {
        after.gameCards[i] = state.supplyCount[i];
    }

    // begin assertions and printing results
    assertTest((after.handCount - before.handCount) == 0, "Hand Count", before.handCount, after.handCount);
    assertTest((before.deckCount - after.deckCount) == 1, "Deck Count", before.deckCount, after.deckCount);
    assertTest((after.playedCardCount - before.playedCardCount) == 1, "Played Card Count", before.playedCardCount, after.playedCardCount);
    assertTest((after.numActions - before.numActions) == 2, "Number of Actions Count", before.numActions, after.numActions);
    assertTest(before.numBuys == after.numBuys, "Number of Buys Count", before.numBuys, after.numBuys);

    for (i = 0; i < treasure_map + 1; i++)
    {
        memset(gameCardString, '\0', 100 * sizeof(char));
        strcpy(gameCardString, "Game Card Count for: ");
        strcat(gameCardString, before.gameCardNames[i]);
        assertTest(before.gameCards[i] == after.gameCards[i], gameCardString, before.gameCards[i], after.gameCards[i]);
    }

    return 0;
}

void asserttrue(int value, char* test, int before, int after)
{
    if (value)
    {
        printf("Test: %s successful!\n", test);
        printf("Before: %d\tAfter: %d\n", before, after);
        fflush(stdout);
    }
    else
    {
        printf("Test: %s failed!\n", test);
        printf("Before: %d\tAfter: %d\n", before, after);
        fflush(stdout);
    }
}