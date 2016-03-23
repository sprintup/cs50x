#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) {
    //get input
    float n;
    do 
    {
        printf("O hai! How much change is owed?\n");
        n = GetFloat();
        // printf("n: %f",n);
    }
    while (n < 0.0);
    
    int dollars = floorf(n);
    float centsFloat = n - (float)dollars;
    // printf("You mean: %d dollars and %.2f cents? \n", dollars, centsFloat);
    
    //calculate total cents
    float centsFloat1 = centsFloat * 100.0;
    float centsFloat2 = roundf(centsFloat1);
    int centsInt = (int)centsFloat2;
    int dollarCentsInt = (dollars * 100);
    int totalCents = centsInt + dollarCentsInt;
    // printf("or %d centsInt and dollarCentsInt: %d \n", centsInt, dollarCentsInt);
    // printf("for a totalCents: %d\n", totalCents);
    
    //take quarters out of totalCents
    int quarters = totalCents / 25; 
    int remainder = totalCents % 25;
    // printf("meaning you'll get %d quarters and have %d cents remaining\n", quarters, remainder);
    
    //take dimes out of remainder
    int dimes = remainder / 10;
    remainder = remainder % 10;
    // printf("or %d quarters and %d dimes with %d cents remaining\n", quarters, dimes, remainder);
    
    //take nickels out of remainder
    int nickels = remainder / 5; 
    remainder = remainder % 5; 
    // printf("perhaps %d quarters, %d dimes, %d nickels with %d remaining\n", quarters, dimes, nickels, remainder);
    
    //take pennies out of remainder
    int pennies = remainder / 1;
    remainder = remainder % 1;
    // printf("no you actually mean you'll have %d quarters, %d dimes, %d nickels, %d pennies with %d remaining\n", quarters, dimes, nickels, pennies, remainder);
    int totalCoins = quarters + dimes + nickels + pennies;
    // printf("or just to be clear you'll have %d coins\n", totalCoins);
    printf("%d\n",totalCoins);
}