#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

/*
    c = (p + k) % 26
        * c = letter of cypher text
        * p = letter of plaintext
        * k = letter of key
        * %26 = remainder after dividing by 26
*/

string k; 
int counter; 
int getNextChar (void);
int alpha_map (char c);

int main (int argc, string argv[])
{
    //make sure only 1 argument
    if (argc != 2)
    {
        printf("Usage: ./vigenere <key>\n");
        return 1;
    }
    
    //make sure argument only contains a string
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return 1; 
        }
    }
    
    counter = 0;
    k = argv[1];
    
    // [X] iterate characters in string
    // [ ] only apply the cipher if it's a letter
    // [X] use mod to wrap
    // [X] two formulas for shift (uppercase/lowercase letters)
    
    string p = GetString();

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i])) // *upper case*
        {
            int a = p[i] - 65;                  
            int d = getNextChar();
            int c = 65 + d + a;                 
            /*
                When c is more than 90 have it wrap back to 65
                * a = actual inputted base 26 alphabet letter 
                * d = difference to travel moving forward
                * c = cipher value in ascii (shouldn't be higher than 90)
            */
            if (c > 90)
            {
                c = (c - 91) + 65;
            }
            
            // printf("upper || a: %d | d: %d | c: %d, < %c > \n",a,d,c,c);
            printf("%c",c);
        }
        else if (islower(p[i])) // *lower case*
        {
            int a = p[i] - 97;                      
            int d = getNextChar();
            int c = a + d + 97;
            /*
                When c is more than 122 have it wrap back to 97
                * a = actual inputted base 26 alphabet letter 
                * d = difference to travel moving forward
                * c = cipher value in ascii (shouldn't be higher than 122)
            */
            if (c > 122)
            {
                c = (c - 123) + 97;
            }

            // printf("lower || a: %d | d: %d | c: %d, < %c > \n",a,d,c,c);
            printf("%c",c);
        } 
        else
        {
            printf("%c",p[i]);
        }
    }

    printf("\n");

    return 0;
}

int getNextChar (void)
{
    char rawChar = k[counter % 3];
    int alphaIndex = alpha_map(rawChar);
    counter++;
    return alphaIndex;
}

int alpha_map (char c)
{
    // [X] map k to alphabetical index, case insensitive 
    int alpha_index;

    //uppercase letter
    if (isupper(c))
    {
        // minus 65
        alpha_index = c - 65;
    }
    //lowercase letter
    else if (islower(c))
    {
        // minus 97
        alpha_index = c - 97;
    } else
    {
        // space
        alpha_index = c; 
    }
    return alpha_index; 
}
