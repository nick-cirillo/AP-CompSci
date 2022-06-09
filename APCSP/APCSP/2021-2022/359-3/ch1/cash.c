# include <stdio.h>
# include <cs50.h>
# include <math.h>

//Declarig some variables
float owed = -1;
int cents;
int coins;

int main(void)
{
    while (owed <= 0)
    {
        owed = get_float("Change owed: ");
    }

    cents = round(owed * 100);
    //rounding^^

    //while cents remain, decrement cents by the
    //greatest coin value possible
    while (cents > 0)
    {
        if (cents / 25 >= 1) //quarters
        {
            coins++;
            cents -= 25;
        }
        else if (cents / 10 >= 1) //dimes
        {
            coins++;
            cents -= 10;
        }
        else if (cents / 5 >= 1) //nickels
        {
            coins++;
            cents -= 5;
        }
        else if (cents / 1 >= 1) //pennies
        {
            coins++;
            cents -= 1;
        }
    }
    printf("%i\n", coins);
}