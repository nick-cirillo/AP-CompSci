# include <stdio.h>
# include <cs50.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int ChoosePsRoom(int curRoom, int upBound, int lowBound);
int ChoosePcRoom(int curRoom, int upBound, int lowBound, int i, int rise);

int main(int argc, string argv[])
{
    if (argc != 2 || strspn(argv[1], "0123456789") != strlen(argv[1])) //compares # of #s to strlen
    {
        printf("USAGE: ./princess TRIALS\n");
        return 0;
    }
    int trials = atoi(argv[1]);
    int totalFound = 0;
    srand(time(0));
    for (int vanillabean = 1; vanillabean <= trials; vanillabean++)
    {
        int
            psRoom = 0, //princess
            pcRoom = 0, //prince
            days = 30,
            upBound = 17,
            lowBound = 1,
            gameOver = 0,
            rise = 1; //is prince rising or falling through room #s

        //srand(time(0));

        psRoom = (rand() % upBound) + 1;
        pcRoom = 2;
        for (int i = 1; i <= days; i++)
        {
            if (gameOver == 0)
            {
                //printf("ps: %i, || pc: %i\n", psRoom, pcRoom);
                if (psRoom == pcRoom)
                {
                    gameOver = 1;
                    totalFound++;
                    if (trials <= 10000)
                    {
                        printf("iteration: %i | day found: %i\n", vanillabean, i);
                    }
                    else if (vanillabean == 1)
                    {
                        printf("too many trials to print each individual result\n");
                    }
                    //printf("Prince found Princess on Day %i\n", i);
                }
                psRoom = ChoosePsRoom(psRoom, upBound, lowBound);
                pcRoom = ChoosePcRoom(pcRoom, upBound, lowBound, i, rise);
                if (pcRoom == upBound - 1)
                {
                    rise = 0;
                }
            }
        }
    if (gameOver == 0)
    {
        printf("did not find\n");
    }
    //sleep(1);
    }
    printf("Times where Prince found Princess: %i/%i\n", totalFound, trials);


}

int ChoosePsRoom(int curRoom, int upBound, int lowBound)
{
    int choice = rand() % 2; //up or down
    //printf("choice: %i\n", choice);
    if (choice == 1)
    {
        curRoom++;
    }
    else
    {
        curRoom--;
    }
    if (curRoom == upBound + 1) //ensure in bounds
    {
        curRoom = upBound - 1;
    }
    else if (curRoom == lowBound - 1)
    {
        curRoom = lowBound + 1;
    }
    return curRoom;
}

int ChoosePcRoom(int curRoom, int upBound, int lowBound, int i, int rise)
{
    //printf("b: %i,  %i ||| ", curRoom, rise);
    if (i == 15)
    {
        //nothing
    }
    else if (curRoom == upBound - 1)
    {
        curRoom--;
    }
    else if (rise == 1)
    {
        curRoom++;
    }
    else if (rise == 0)
    {
        curRoom--;
    }
    //printf("a: %i\n", curRoom);
    return curRoom;
}