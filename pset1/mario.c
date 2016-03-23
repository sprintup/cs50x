#include <stdio.h>
#include <cs50.h>

int main (void) {
    //get valid height from user
    int n;
    do 
    {
        printf("height: ");
        n = GetInt();
    }
    while (n < 0 || n > 23);
    
    /*
    create steps
        - repeat for inputted height if input is between 1 and 23 inclusive
    */
    for (int l = 1; l <= n; l++)
    {
        /*
        spaces 
            - should print (n - 1) spaces
        */
        int spaces = n - l; 
        for (int x = 0; x < spaces; x ++)
        {
            printf(" ");
        }
        
        /*
        hashes
            - should always print (l + 1) hashes
        */
        int hashes = l + 1;
        for (int y = 0; y < hashes; y++)
        {
            printf("#");
        }

        //print new line
        printf("\n");
    }
}