/*******************************************************************
* Assignment 4: Random testing
* File: randomtestadventurer.c
* Card in Test: adventurer
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
            ADVENTURER

Expected behavior: Draw cards until getting 2 additional treasure cards. Discard the other non-treasure drawn cards.

Input:
    int currentPlayer,
    int temphand[]
    struct gameState *state

Output:
    int (return 0)
************************************************************/

#define TESTCARD "Adventurer"
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
        int numPlayers = 2;     // I was going to randomize this too, but this would change testing, likely a nested for loop to compare each player
        int handPosition = 0;
        // no choices or bonus for smithy card
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int bonus = 0;
        char gameCardString[100];

        int seed = rand();

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
        after.playedSuccessfully = cardEffect(adventurer, choice1, choice2, choice3, &state, handPosition, &bonus);
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
        asserttrue((after.handCount - before.handCount) == 2, "Hand Count", before.handCount, after.handCount);
        
        if((after.handCount - before.handCount) == 2)
            timesCorrectHandCount++;

        // removed deck count as this could be any number of cards removed from the deck
        // possible bug in played card count in adventurer as well - this never calls discard card, thus playedcards doesn't get incremented.  Leaving test in as a good test!
        asserttrue((after.playedCardCount - before.playedCardCount) == 1, "Played Card Count", before.playedCardCount, after.playedCardCount);
        asserttrue((before.numActions - after.numActions) == 0, "Number of Actions Count", before.numActions, after.numActions);
        asserttrue(before.numBuys == after.numBuys, "Number of Buys Count", before.numBuys, after.numBuys);

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