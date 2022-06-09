# include <stdio.h>
# include <cs50.h>
# include <stdlib.h>
# include <time.h>

int main(void)
{

    int totdays = 0;

    for (int i = 0; i < 1000; i++)
    {
        int money = 1000;
        int days = 0;
        int gameOver = 0;
        while (gameOver == 0)
        {
            while (money < 1100 && money > 0)
            {
                time_t t;
                srand((unsigned) time(&t));
                int win = rand() % 1;
                if (win == 1)
                {
                    money += 100;
                }
                else
                {
                    money -= 100;
                }
            }


            if (money >= 1100)
            {
                days++;
                money = 1000;
            }
            else
            {
                gameOver = 1;
                totdays += days;
                printf("Experiment %i: %i days survived\n", i, days);
            }
        }

    }
    printf("Avg Days Survived: %i\n", totdays / 1000);
}