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

void asserttrue(int value, char* test, int before, int after);


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