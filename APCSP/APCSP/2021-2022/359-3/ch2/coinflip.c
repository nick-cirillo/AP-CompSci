# include <stdio.h>
# include <cs50.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int main(int argc, string argv[])
{

    int streakLim = 0;
    if (argc != 2 || strspn(argv[1], "0123456789") != strlen(argv[1])) //compares # of #s to strlen
    {
        printf("USAGE: ./coinflip STREAK\n");
        return 1;
    }
    else
    {
        streakLim = atoi(argv[1]);
    }

    int
        gameOver = 0, //is game active
        lastFlip = 2, //what was the last flip
        curFlip = 2, //heads - 0, tails - 1
        flips = 0, //flips been done
        streak = 0; //same flip in a row

    srand(time(0));

    while (streak < streakLim)
    {
        curFlip = rand() % 2;
        if (curFlip == lastFlip)
        {
            flips++;
            streak++;
        }
        else if (flips == 0)
        {
            flips++;
            streak++;
        }
        else
        {
            flips++;
            streak = 1;
        }
        //printf("last: %i\ncur: %i\nflips: %i\nstreak: %i\n---------\n", lastFlip, curFlip, flips, streak);
        lastFlip = curFlip;
    }
    printf("%i flips to reach streak limit of %i\n", flips, streakLim);
}