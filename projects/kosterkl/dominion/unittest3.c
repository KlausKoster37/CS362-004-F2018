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