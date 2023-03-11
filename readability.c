#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // prompt user for string of text
    string text = get_string("Text: \n");
    int let = 0;
    int wor = 1;
    int sen = 0;

    // loop to read word 1 by 1
    for (int i = 0; i < strlen(text); i++)
    {
        // if ((text[i] > 65 && text[i] < 90) || (text[i] > 97 && text[i] < 122))
        // same as expression but using <ctype.h>
        if (isalpha(text[i]))
        {
            let++;
        }
        // search for spaces betwen words, inicialized to 1.
        else if (text[i] == ' ')
        {
            wor++;
        }
        // search for end of sentences (! , . , ?)
        else if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sen++;
        }
    }
    float L = (float)let / wor * 100;
    float S = (float)sen / wor * 100;
    // form <match.h> funcition round
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}