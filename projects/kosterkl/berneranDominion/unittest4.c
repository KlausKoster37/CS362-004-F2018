/*******************************************************************
* Assignment 3: Unit Testing
* File: unittest1.c
* Function under test: kingdomCards()
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
                    kingdomCards()

Expected behavior: returns int array that matches a given array (passed to the function)

Input:
    9 integers

Output:
    integer array of those 9 values
************************************************************/

#define TESTFUNCTION "kingdomCards()"
#define TESTARRAYSIZE 10
// global easy testing arrays
char* gameCardNames[treasure_map + 1];

void asserttrue(int value, char* test, int before, int after);

int main(int argc, char* argv[])
{
    // setup variables
    int originalValues[TESTARRAYSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

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

    printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
    fflush(stdout);

    // call function to get return array with values
    int *testArray = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

    // test values against the original ones
    int i;
    for (i = 0; i < TESTARRAYSIZE; i++)
    {
        asserttrue(originalValues[i] == *(testArray + i), gameCardNames[i], originalValues[i], *(testArray + i));
    }

    return 0;
}

void asserttrue(int value, char* test, int before, int after)
{
    if (value)
    {
        printf("Test: %s successful!\n", test);
        printf("Original: %d\tNew: %d\n", before, after);
        fflush(stdout);
    }
    else
    {
        printf("Test: %s failed!\n", test);
        printf("Original: %d\tNew: %d\n", before, after);
        fflush(stdout);
    }
}