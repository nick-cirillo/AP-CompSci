# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <crypt.h>

void AddOne(int i, int guessNo[]);
void Translate(int guessNo[], char guess[]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("USAGE: ./crack HASH\n");
        //return 1;
    }

    string hash = argv[1];

    //extract salt (last 2)
    //char salt[2];
    //strncpy(salt, hash, 2);

    char guess[5];
    int guessNo[5];
    for (int i = 0; i < 5; i++)
    {
        guess[i] = '\0';
    }

    while (guess[0] != 'Z' && guess[4] != 'Z')
    {
        AddOne(0, guessNo);
        printf("%s\n", guess);
        Translate(guessNo, guess);
        printf("%s\n", guess);
    }
    printf("here\n");
    return 1;
    string guessHash = crypt(guess, salt);
    if (strcmp(guessHash, hash)==0)
    {
        printf("The hash <%s> is really the word <%s>\n", hash, guess);
        return 0;
    }

}

void AddOne(int i, int guessNo[])
{
    guessNo[i]++;
    if (guessNo[i] > 52)
    {
        guessNo[i] = 1;
        AddOne(i + 1, guessNo);
    }
}

void Translate(int guessNo[], char guess[])
{
    int noTemps[5]; //create receiver for translation

    for (int j = 0; j < 5; j++)
    {
        if (guessNo[j] > 0 && guessNo[j] <= 26)
        {
            noTemps[j] = guessNo[j] + 96;
        }
        else if (guessNo[j] > 26 && guessNo[j] <= 52)
        {
            noTemps[j] = guessNo[j] + 38;
        }
        guess[j] = (char)noTemps[j];
    }


}