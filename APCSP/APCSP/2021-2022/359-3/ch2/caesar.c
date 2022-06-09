# include <stdio.h>
# include <cs50.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

string convertText(string text, int offset);

int main(int argc, string argv[])
{
    if (argc != 2 || strspn(argv[1], "0123456789") != strlen(argv[1])) //compares # of #s to strlen
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        key %= 26; //in case of big keys like 235
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: %s\n", convertText(plaintext, key));
        return 0;
    }
}

string convertText(string text, int offset)
{
    int textLen = strlen(text);
    string nText = text; //converted string
    for (int i = 0; i < textLen; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            int upperBound;
            if (isupper(c))
            {
                upperBound = 90;
            }
            else
            {
                upperBound = 122;
            }

            int dec = c;
            dec += offset;
            if (dec > upperBound)
            {
                dec -= 26; //bring key in range of decimal codes
            }

            nText[i] = (char)dec;
        }
        else
        {
            nText[i] = c; //ignores char if not letter
        }

    }

    return nText;
}