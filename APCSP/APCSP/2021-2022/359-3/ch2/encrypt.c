# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("USAGE: ./encrypt WORD\n");
    }

    string word = argv[1];
    string hash = crypt(word, "ba");

    printf("The word %s was hashed as %s\n", word, hash);
}