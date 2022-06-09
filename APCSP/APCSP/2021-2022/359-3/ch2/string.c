# include <stdio.h>
# include <cs50.h>
# include <string.h>

int main(void)
{
    string name = "";
    name = get_string("What's your name? ");

    for (int i = 0; name[i] != '\0'; i++)
    {
        printf("%c\n", name[i]);
    }

    int len = 0;
    int len2 = strlen(name);
    for (int i = 0; name[i] != '\0'; i++)
    {
        len++;
    }
    printf("%s has %i letters\n", name, len);

    for (int i = 0; i < len2; i++)
    {
        printf("%c\n", name[i]);
    }
}