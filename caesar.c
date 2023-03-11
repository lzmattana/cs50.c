#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // condition check user for ./c key
    // input in argv !=2 quit
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // condition check argv is digit if not quit
    for (int a = 0; a < strlen(argv[1]); a++)
    {
        if (!isdigit(argv[1][a]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // use the key 'K' in plaintext to cypher
    int k = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");

    for (int b = 0; b < strlen(plaintext); b++)
    {
        // calculus of cyphertext if upper
        if (isupper(plaintext[b]))
        {
            printf("%c", (plaintext[b] - 65 + k) % 26 + 65);
        }
        // calculus of cyphertext if lower
        else if (islower(plaintext[b]))
        {
            printf("%c", (plaintext[b] - 97 + k) % 26 + 97);
        }
        // if is anything else print as it is
        else
        {
            printf("%c", plaintext[b]);
        }
    }
    printf("\n");
}