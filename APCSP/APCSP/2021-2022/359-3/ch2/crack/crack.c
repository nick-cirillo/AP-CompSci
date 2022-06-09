#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("USAGE: ./crack HASH\n");
        return 1;
    }

    string hash = argv[1];

    //extract salt from hash (1st 2 chars)
    char salt[2];
    strncpy(salt, hash, 2);

    //initialize the guess
    char guess[5];
    guess[0] = '\0';
    guess[1] = '\0';
    guess[2] = '\0';
    guess[3] = '\0';
    guess[4] = '\0';

    int col = 0;

    while (col < 5)
    {
        if (guess[col] == '\0')
        {
            guess[col] = 'a';
        }
        else if (guess[col] == 'z')
        {
            guess[col] = 'A';
        }
        else if (guess[col] == 'Z')
        {
            guess[col] = 'a';
            col++;
            continue;
        }
        else
        {
            guess[col]++;
        }
        printf("%s\n", guess);
        col = 0;

        string guessHash = crypt(guess, salt);
        if (strcmp(guessHash, hash) == 0)
        {
            printf("%s\n", guess);
            return 0;
        }


    }






}