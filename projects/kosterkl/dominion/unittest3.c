/*******************************************************************
* Assignment 3: Unit Testing
* File: unittest1.c
* Function under test: supplyCount()
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
                supplyCount()

Expected behavior: returns number of a specific card remaining in the supply

Input:
    int card
    struct gameState *state

Output:
    integer value of the number of X cards remaining in the supply
************************************************************/

#define TESTFUNCTION "supplyCount()"

// global easy testing arrays
char* gameCardNames[treasure_map + 1];

// modified assert from cardtests due to the before/after not being necessary.
void asserttrue(int value, char* test, int arrayValue, int functionValue);

int main(int argc, char* argv[])
{
    // setup variables
    struct gameState state;
    int k[10] = { adventurer, council_room, cutpurse, embargo, gardens, minion, mine, village, smithy, tribute };
    int numPlayers = 2;
    int seed = 1000;

    printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
    fflush(stdout);

    // setup names
    gameCardNames[0] = "curse";
    gameCardNames[1] = "estate";
    gameCardNames[2] = "duchy";
    gameCardNames[3] = "province";
    gameCardNames[4] = "copper";
    gameCardNames[5] = "silver";
    gameCardNames[6] = "gold";
    gameCardNames[7] = "adventurer";
    gameCardNames[8] = "council_room";
    gameCardNames[9] = "feast";
    gameCardNames[10] = "gardens";
    gameCardNames[11] = "mine";
    gameCardNames[12] = "remodel";
    gameCardNames[13] = "smithy";
    gameCardNames[14] = "village";
    gameCardNames[15] = "baron";
    gameCardNames[16] = "great_hall";
    gameCardNames[17] = "minion";
    gameCardNames[18] = "steward";
    gameCardNames[19] = "tribute";
    gameCardNames[20] = "ambassador";
    gameCardNames[21] = "cutpurse";
    gameCardNames[22] = "embargo";
    gameCardNames[23] = "outpost";
    gameCardNames[24] = "salvager";
    gameCardNames[25] = "sea_hag";
    gameCardNames[26] = "treasure_map";

    // initialize the game
    initializeGame(numPlayers, k, seed, &state);

    // test all supply counts
    int i;
    for (i = 0; i < treasure_map + 1; i++)
    {
        state.supplyCount[i] = i + 7;
        asserttrue(supplyCount(i, &state) == (i + 7), gameCardNames[i], state.supplyCount[i], supplyCount(i, &state));
    }

    return 0;
}


void asserttrue(int value, char* test, int arrayValue, int functionValue)
{
    if (value)
    {
        printf("Test: %s successful!\n", test);
        printf("\tSupply Count Array: %d\tFunction: %d\n", arrayValue, functionValue);
        fflush(stdout);
    }
    else
    {
        printf("Test: %s failed!\n", test);
        printf("\tSupply Count Array: %d\tFunction: %d\n", arrayValue, functionValue);
        fflush(stdout);
    }
}