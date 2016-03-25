#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
 - isalpha('Z') will tell you if it's a letter; boolean; if true, shift by key
 - a formula for the shift:
    - c = (p + k) % 26
        * c = ciphertext letter
        * p = plaintext letter
        * k = key
        * %26 = remainder after dividing by 26
    - applies to the alphabetical index of a letter, not its ASCII value
        - but you start with ASCII values
        - and you'll need to print ASCII value from the index
- preserve case with isupper() and islower()
    - have two formulas
- strlen() takes in a string as input and outputs length of string
*/
int main (int argc, string argv[])
{
    // error if user returns 0 or more than 1 arguments to the command line
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }

    // get int from command line    
    int k = atoi(argv[1]);
    
    //get string from user
    string p = GetString();
    
    char output[strlen(p)];
    
    //iterate characters in string
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {
            //shift char and add to new array
            int c = ((p[i]-65) + k) % 26;
            // printf("p[i]: %c, %d\n",p[i], p[i]);
            // printf("c: %d, = %c\n",c+65, c+65);
            output[i] = c+65;
        }
        else if (islower(p[i]))
        {
            //shift char and add to new array
            int c = ((p[i]-97) + k) % 26;
            // printf("p[i]: %c, %d\n",p[i], p[i]);
            // printf("c: %d, = %c\n",c+65, c+65);
            output[i] = c+97;
        } else
        {
            output[i] = p[i];
        }
    }
    
    //print shifted text
    printf("%s\n", output);
    
    return 0;
}