# import <stdio.h>
# import <cs50.h>
# import <unistd.h>

int main(void)
{
    int measures = 0;
    //choose measures for nothing
    while (measures <= 0)
    {
        measures = get_int("How many measures for nothing? ");
    }
    if (measures == 1)
    {
        printf("Alright, train station.\n");
        sleep(2);
        printf("...\n");
        sleep(2);
        printf("Okay, I'm gonna give you 1 measure for nothing. Here we go.\n");
        sleep(2);
    }
    else if (measures > 1)
    {
        printf("Alright, train station.\n");
        sleep(2);
        printf("...\n");
        sleep(2);
        printf("Okay, I'm gonna give you %i measures for nothing. Here we go.\n",measures);
        sleep(2);
    }
    for (int i = 1; i <= measures; i++)
    {
        if (i == measures)
        {
            printf("%i-e-and-a ready go.\n",i);
        }
        else
        {
            printf("%i-e-and-a,\n",i);
        }
        sleep(1);

    }
}