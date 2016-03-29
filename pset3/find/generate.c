/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: comment me
    /*
        check to see if user passed at least 1 or 2 arguments
    */
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: comment me
    /*
        translate the first argument passed to an int, as it's initially a string. 
    */
    int n = atoi(argv[1]);

    // TODO: comment me
    /*
        -if the user entered 2 arguments, meaning they wanted to set the seed variable, srand48 sets the high order 32-bits of Xi to the argument seedval. 
        -however, if the user only passed one argument the srand48() simply initializes, preparing for drand48()
    */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: comment me
    /*
        -for the number of times passed as the first agument, print a pseudo-random number using the linear contruential algorithm. 
    */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}