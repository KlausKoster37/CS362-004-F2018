/*******************************************************************
* Assignment 3: Unit Testing
* File: unittest2.c
* Function under test: getCost()
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
                    getCost()

Expected behavior: returns cost of card passed to it the function

Input:
    int cardNumber

Output:
    cost in integer form
************************************************************/

#define TESTFUNCTION "getCost()"

// global easy testing arrays
char* gameCardNames[treasure_map + 1];
int cardCosts[treasure_map + 1];

// modified assert from cardtests due to the before/after not being necessary.
void asserttrue(int value, char* test);

int main(int argc, char* argv[])
{
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

    // setup costs
    cardCosts[0] = 0;
    cardCosts[1] = 2;
    cardCosts[2] = 5;
    cardCosts[3] = 8;
    cardCosts[4] = 0;
    cardCosts[5] = 3;
    cardCosts[6] = 6;
    cardCosts[7] = 6;
    cardCosts[8] = 5;
    cardCosts[9] = 4;
    cardCosts[10] = 4;
    cardCosts[11] = 5;
    cardCosts[12] = 4;
    cardCosts[13] = 4;
    cardCosts[14] = 3;
    cardCosts[15] = 4;
    cardCosts[16] = 3;
    cardCosts[17] = 5;
    cardCosts[18] = 3;
    cardCosts[19] = 5;
    cardCosts[20] = 3;
    cardCosts[21] = 4;
    cardCosts[22] = 2;
    cardCosts[23] = 5;
    cardCosts[24] = 4;
    cardCosts[25] = 4;
    cardCosts[26] = 4;

    // test all costs
    int i;
    for (i = 0; i < treasure_map + 1; i++)
    {
        // note that we can use i instead of the card name because the order is the exact same as the enum
        asserttrue(getCost(i) == cardCosts[i], gameCardNames[i]);
    }

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