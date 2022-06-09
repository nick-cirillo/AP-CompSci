# include <stdio.h>
# include <cs50.h>
# include <stdlib.h>

int main(int argc, char *argv[])
{
    int maxTable = atoi(argv[1]);
    // generate times table
    for(int x = 1; x <= maxTable; x++)
    {
        for (int y = 1; y <= maxTable; y++)
        {
            printf("%i ", x * y);
        }
        printf("\n");
    }
}