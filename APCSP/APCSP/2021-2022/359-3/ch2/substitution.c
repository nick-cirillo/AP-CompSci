# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2 || strspn(argv[1], "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != strlen(argv[1]))
    {
        printf("USAGE: ./substitution KEY\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must be 26 different letters\n");
        return 1;
    }

    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = 0; j < strlen(key); j++)
        {
            if (i != j && key[i] == key[j])
            {
                printf("Key must be 26 different letters\n");
                return 1;
            }
        }
    }

    string plain = get_string("plaintext: ");
    printf("%lu\n", strlen(plain));
    char cipher[strlen(plain)];
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                cipher[i] = toupper(key[(int)plain[i] - 65]); //64 for acii and 1 for 0-index
            }
            else
            {
                cipher[i] = tolower(key[(int)plain[i] - 97]); //96 for acii and 1 for 0-index
            }
        }
        else
        {
            cipher[i] = plain[i];
        }

    }

    printf("ciphertext: %s\n", cipher);
    return 0;


}