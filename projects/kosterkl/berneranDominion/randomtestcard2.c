/*******************************************************************
* Assignment 4: Random Testing
* File: randomcardtest2.c
* Card in Test: council room
*
* Author: Klaus Koster (kosterkl)
* Due Date: 11/14/2018
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
#include <time.h>

/************************************************************
            COUNCIL ROOM

Expected behavior: Draw 4 cards, +1 Buy, each other player draws a card
    Note: +3 cards (+4, discard 1)

Input:
    int currentPlayer,
    int handPos,
    struct gameState *state

Output:
    int (return 0)
************************************************************/

#define TESTCARD "Council Room"
#define TEST_ITERATIONS 2000


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
    time_t timeSeed;
    srand((unsigned) time(&timeSeed));
    int timesPlayedSuccessfully = 0;
    int timesCorrectHandCount = 0;
    int timesCorrectDeckCount = 0;
    int timesCorrectBuyCount = 0;

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    fflush(stdout);

    int i;
    for (i = 0; i < TEST_ITERATIONS; i++)
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
        int seed = rand();
        // no choices or bonus for council room card
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int bonus = 0;
        char gameCardString[100];

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
        after.playedSuccessfully = cardEffect(council_room, choice1, choice2, choice3, &state, handPosition, &bonus);
        asserttrue(before.playedSuccessfully == after.playedSuccessfully, "Card played", before.playedSuccessfully, after.playedSuccessfully);

        if(after.playedSuccessfully == 0)
            timesPlayedSuccessfully++;

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
        // note that bug 3 is caught via the played card count since we altered the trash flag, the state played card count doesn't increase
        asserttrue((after.handCount - before.handCount) == 3, "Hand Count", before.handCount, after.handCount);

        if((after.handCount - before.handCount) == 3)
            timesCorrectHandCount++;

        asserttrue((before.deckCount - after.deckCount) == 4, "Deck Count", before.deckCount, after.deckCount);

        if((before.deckCount - after.deckCount) == 4)
            timesCorrectDeckCount++;

        asserttrue((after.playedCardCount - before.playedCardCount) == 1, "Played Card Count", before.playedCardCount, after.playedCardCount);
        asserttrue((before.numActions - after.numActions) == 0, "Number of Actions Count", before.numActions, after.numActions);
        asserttrue((after.numBuys - before.numBuys) == 1, "Number of Buys Count", before.numBuys, after.numBuys);

        if((after.numBuys - before.numBuys) == 1)
            timesCorrectBuyCount++;

        for (i = 0; i < treasure_map + 1; i++)
        {
            memset(gameCardString, '\0', 100 * sizeof(char));
            strcpy(gameCardString, "Game Card Count for: ");
            strcat(gameCardString, before.gameCardNames[i]);
            asserttrue(before.gameCards[i] == after.gameCards[i], gameCardString, before.gameCards[i], after.gameCards[i]);
        }
    }

    printf("Number of iterations: %d\t Played Successfully: %d\n", TEST_ITERATIONS, timesPlayedSuccessfully);
    fflush(stdout);

    printf("Number of iterations: %d\t Number of Iterations with Correct Hand Count: %d\n", TEST_ITERATIONS, timesCorrectHandCount);
    fflush(stdout);

    printf("Number of iterations: %d\t Number of Iterations with Correct Deck Count: %d\n", TEST_ITERATIONS, timesCorrectDeckCount);
    fflush(stdout);

    printf("Number of iterations: %d\t Number of Iterations with Correct Buy Count: %d\n", TEST_ITERATIONS, timesCorrectBuyCount);
    fflush(stdout);

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