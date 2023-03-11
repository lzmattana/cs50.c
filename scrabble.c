#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    // loop to read word 1 by 1
    for (int n = 0; n < strlen(word); n++)
    {
        // condition search lower case if(word[a] > 65 && word[a] < 90)
        // use library <ctype.h>
        if (isupper(word[n]))
        {
            score += POINTS[word[n] - 'A'];
        }
        // condition search upper case if(word[a] > 97 && word[a] < 122)
        // use library <ctype.h>
        if (islower(word[n]))
        {
            score += POINTS[word[n] - 'a'];
        }
    }
    return score;
}