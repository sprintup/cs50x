#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main (void) {
    string s = GetString();
    
    if (s != NULL)
    {
        //print capitalized first letter
        printf("%c", toupper(s[0]));
            
        // loop through chars in string
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // print capitalized letters after blanks
            if (isblank(s[i]))
            {
                printf("%c", toupper(s[i + 1]));
            }
        }
        printf("\n");
    }
}