# include <stdio.h>
# include <stdlib.h>
# include <cs50.h>
# include <unistd.h>
# include <time.h>

char *randChar1;
char *randChar2;

void ChooseLetters(int i, int j);

void InitializeVars();

int main(void)
{
    InitializeVars();
    int measures = 0;
    int choice = 0;
    int choicetemp = -1;
    srand(time(0));
    ChooseLetters(rand() % 21, 1);
    ChooseLetters(rand() % 20, 2);
    //choose measures for nothing and seeds rng
    printf("Today, we are playing %solly on the %sore.\n", randChar1, randChar2);
    sleep(2);
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
        printf("Okay, I'm gonna give you %i measures for nothing. Here we go.\n", measures);
        sleep(2);
    }
    for (int i = 1; i <= measures; i++)
    {
        if (i == measures)
        {
            printf("%i-e-and-a ready go.\n", i);
        }
        else
        {
            choice = rand() % 13;
            if (choicetemp == choice && choice != 0)
            {
                choice++;
            }
            if (choice >= 0 && choice <= 4)
            {
                printf("%i-e-and-a,\n", i);
            }
            if (choice == 5)
            {
                printf("Ready-viola-cello-bass,\n");
            }
            if (choice == 6)
            {
                printf("%i-e-and-a here we go,\n", i);
            }
            if (choice == 7)
            {
                printf("Bows on strings,\n");
            }
            if (choice == 8)
            {
                printf("Gag me,\n");
            }
            if (choice == 9)
            {
                printf("No slurping,\n");
            }
            if (choice == 10)
            {
                printf(" -e-and-a, -e-and-a,\n");
            }
            if (choice == 11)
            {
                printf("Breath on %i,\n", rand() % 4);
            }
            if (choice == 12)
            {
                printf("Get ready to SAY it\n");
            }
            if (choice > 12)
            {
                printf("TRAIN STATION.\n");
                sleep(2);
                printf("Let's try that again. %i measures for nothing. Here we go.\n", measures);
                sleep(3);
                i = 0;
            }
            //printf("%i\n",choice);
            choicetemp = choice;
        }
        sleep(1);

    }
}

void ChooseLetters(int i, int j)
{
    if (j == 1)
    {
        if (i == 0)
        {
            randChar1 = "B";
        }
        if (i == 1)
        {
            randChar1 = "C";
        }
        if (i == 2)
        {
            randChar1 = "D";
        }
        if (i == 3)
        {
            randChar1 = "F";
        }
        if (i == 4)
        {
            randChar1 = "G";
        }
        if (i == 5)
        {
            randChar1 = "H";
        }
        if (i == 6)
        {
            randChar1 = "J";
        }
        if (i == 7)
        {
            randChar1 = "K";
        }
        if (i == 8)
        {
            randChar1 = "L";
        }
        if (i == 9)
        {
            randChar1 = "M";
        }
        if (i == 10)
        {
            randChar1 = "N";
        }
        if (i == 11)
        {
            randChar1 = "P";
        }
        if (i == 12)
        {
            randChar1 = "Qu";
        }
        if (i == 13)
        {
            randChar1 = "R";
        }
        if (i == 14)
        {
            randChar1 = "S";
        }
        if (i == 15)
        {
            randChar1 = "T";
        }
        if (i == 16)
        {
            randChar1 = "V";
        }
        if (i == 17)
        {
            randChar1 = "W";
        }
        if (i == 18)
        {
            randChar1 = "X";
        }
        if (i == 19)
        {
            randChar1 = "Y";
        }
        if (i == 20)
        {
            randChar1 = "Z";
        }

    }

    if (j == 2)
    {
        if (i == 0)
        {
            randChar2 = "B";
        }
        if (i == 1)
        {
            randChar2 = "C";
        }
        if (i == 2)
        {
            randChar2 = "D";
        }
        if (i == 3)
        {
            randChar2 = "F";
        }
        if (i == 4)
        {
            randChar2 = "G";
        }
        if (i == 5)
        {
            randChar2 = "J";
        }
        if (i == 6)
        {
            randChar2 = "K";
        }
        if (i == 7)
        {
            randChar2 = "L";
        }
        if (i == 8)
        {
            randChar2 = "M";
        }
        if (i == 9)
        {
            randChar2 = "N";
        }
        if (i == 10)
        {
            randChar2 = "P";
        }
        if (i == 11)
        {
            randChar2 = "Qu";
        }
        if (i == 12)
        {
            randChar2 = "R";
        }
        if (i == 13)
        {
            randChar2 = "S";
        }
        if (i == 14)
        {
            randChar2 = "T";
        }
        if (i == 15)
        {
            randChar2 = "V";
        }
        if (i == 16)
        {
            randChar2 = "W";
        }
        if (i == 17)
        {
            randChar2 = "X";
        }
        if (i == 18)
        {
            randChar2 = "Y";
        }
        if (i == 19)
        {
            randChar2 = "Z";
        }

    }
}