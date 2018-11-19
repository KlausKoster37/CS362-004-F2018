/*******************************************************************
* Assignment 3: Unit Testing
* File: unittest1.c
* Function under test: isGameOver()
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
#include <time.h>

/************************************************************
                isGameOver()

Expected behavior: returns 1 if game is over, else returns 0
    Note: function checks if province count is zero and (or in terms of the game) if 3 supply piles are zero

Input:
    struct gameState *state

Output:
    int (return)
************************************************************/

#define TESTFUNCTION "isGameOver()"

// modified assert from cardtests due to the before/after not being necessary.
void asserttrue(int value, char* test);


int main(int argc, char* argv[])
{
    // setup variables
    struct gameState state;
    int k[10] = { adventurer, council_room, cutpurse, embargo, gardens, minion, mine, village, smithy, tribute };
    int numPlayers = 2;
    int seed = 1000;

    printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
    printf("----------------- NOTE: SOME TESTS FAIL DUE TO THE VERY BUGGY BASE DOMINION CODE ----------------\n");
    fflush(stdout);

    // initialize the game
    initializeGame(numPlayers, k, seed, &state);

    // set province count = 0.. check for game over, should be yes (1)
    state.supplyCount[province] = 0;
    asserttrue(isGameOver(&state), "Province Count 0 - End Game");
    
    // set province count to 1.. check for game over, should be no (0)
    state.supplyCount[province] = 1;
    asserttrue(isGameOver(&state) == 0 , "Province Count 1 - Game Not Over");

    // set first 3 cards to 0, rest to non-zero number.. check for game over, should be yes (1)
    state.supplyCount[province] = 1;
    int i;
    for (i = 0; i < treasure_map + 1; i++)
    {
        if (i < 3)
            state.supplyCount[i] = 0;
        else
            state.supplyCount[i] = 1;
    }
    asserttrue(isGameOver(&state), "First 3 cards set to 0 supply - End Game");

    // NOTE THAT THIS FAILS BECAUSE THERE IS A BUG IN THE BASE DOMINION CODE: isGameOver() only iterates from 0 to 25, not length of CARD ENUM
    // set last 3 cards to 0, rest to non-zero number.. check for game over, should be yes (1)
    state.supplyCount[province] = 1;
    for (i = 0; i < treasure_map + 1; i++)
    {   
        if (i > treasure_map - 3)
            state.supplyCount[i] = 0;
        else
            state.supplyCount[i] = 1;
        //printf("Card: %d\t Count: %d\n", i, state.supplyCount[i]);
    }
    asserttrue(isGameOver(&state), "Last 3 cards set to 0 supply - End Game");

    // NOTE THAT THIS FAILS BECAUSE THERE IS A BUG IN THE BASE DOMINION CODE: isGameOver() only iterates from 0 to 25, not length of CARD ENUM
    // set first, random, and last cards to 0, rest to non-zero number.. check for game over, should be yes (1)
    state.supplyCount[province] = 1;
    srand(time(0));
    int randPos = rand() % (treasure_map) + 1;
    for (i = 0; i < treasure_map + 1; i++)
    {
        if (i == randPos || i == 0 || i == treasure_map)
            state.supplyCount[i] = 0;
        else
            state.supplyCount[i] = 1;
        //printf("Card: %d\t Count: %d\n", i, state.supplyCount[i]);
    }
    asserttrue(isGameOver(&state), "First, Random, and Last cards set to 0 supply - End Game");

    // set all cards to 1 (> 0) check for game over, should be no (0)
    state.supplyCount[province] = 1;
    for (i = 0; i < treasure_map + 1; i++)
    {
        state.supplyCount[i] = 1;
    }
    asserttrue(isGameOver(&state) == 0, "All cards set to 1 - Game Not Over");

    return 0;
}

void asserttrue(int value, char* test)
{
    if (value)
    {
        printf("Test: %s successful!\n", test);
        fflush(stdout);
    }
    else
    {
        printf("Test: %s failed!\n", test);
        fflush(stdout);
    }
}