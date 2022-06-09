# include <stdio.h>
# include <cs50.h>
# include <stdlib.h>

//Init functions
void drawDiamond (int size);
void printSpaces(int spaces);
void printHashtags(int size);

int main(void)
{
    //Ask for size and num of diamonds
    int size = 0;
    while (size % 2 == 0)
    {
        size = get_int("Please choose an odd integer. ");
        if (size % 2 == 0)
        {
            printf("Invalid integer.\n");
        }
    }
    int num = 0;
    while (num <= 0)
    {
        num = get_int("How many diamonds should be drawn? ");
    }

    for (int d = 0; d < num; d++)
    {
        drawDiamond(size);
    }
}

void drawDiamond(int size)
{
    //Init hash/spaces
    int hashtags = 1;
    int spaces = 0;
    for (int i = 0; i < size; i++)
    {
        //Upper half
        if (i < size / 2)
        {
            spaces = (size - hashtags) / 2;
            printSpaces(spaces);
            printHashtags(hashtags);
            hashtags += 2;
        }
        //Center line
        if (i == size / 2)
        {
            printHashtags(size);
            hashtags -= 2;
        }
        //Bottom half
        if (i > size / 2)
        {
            spaces = (size - hashtags) / 2;
            printSpaces(spaces);
            printHashtags(hashtags);
            hashtags -= 2;
        }

    }
}

void printSpaces(int size)
{
    for (int j = 0; j < size; j++)
            {
                printf(" ");
            }
}

void printHashtags(int size)
{
    for (int j = 0; j < size; j++)
            {
                printf("#");
            }
    printf("\n");
    //Newline to continue properly. Needs to occur after every hashtag
}