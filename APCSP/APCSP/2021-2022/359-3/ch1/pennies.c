# include <stdio.h>
# include <cs50.h>

int daysInMonth = 0;
long long pennyCounter = 0;
long long totalPennies;
long double dollarsCents;

int main(void)
{
    while (daysInMonth < 28 || daysInMonth > 31)
    {
        daysInMonth = get_int("Days in month: ");
    }

    while (pennyCounter <= 0)
    {
        pennyCounter = get_long("Pennies on first day: ");
    }

    for (int i = 1; i <= daysInMonth; i++)
    {
        totalPennies += pennyCounter;
        pennyCounter *= 2;
    }

    dollarsCents = totalPennies / 100.00;

    printf("$%0.2Lf\n", dollarsCents);
}
