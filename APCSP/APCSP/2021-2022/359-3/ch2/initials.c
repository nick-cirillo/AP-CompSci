# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>

int main(void)
{
    string name;
    name = get_string("What is your full name? "); //get name

    int len = strlen(name); //get length of response
    char initials[len];

    for (int i = 0; i < len; i++) //iterate through response
    {
        int isalpha = isalpha(name[i]);
        if ((i == 0 && isalpha != 0) || (i > 0 && isalpha != 0 && name[i - 1] == ' ')) //if i is 0, check if letter, if i greater 0, check if letter and prev was space
        {
            initials[i] = toupper(name[i]); //add uppercase to array
        }
        else
        {
            initials[i] = '\0';
        }
    }

    for (int i = 0; i < len; i++)
    {
        printf("%c", initials[i]); //print array
    }
    printf("\n");
}