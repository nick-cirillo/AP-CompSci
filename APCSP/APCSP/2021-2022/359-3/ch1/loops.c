#include <stdio.h>
#include <cs50.h>

void countdown(int max);

int main(void)
{
    int i;
    for (i=0; i<=4; i++)
    {
        printf("Hello #%i\n", i+1);
    }

    int total=0;
    int j=1;
    while (j<=100)
    {
        total = total + j;
        j++;
    }
    printf("1+2+3+...+99+100 = %i\n", total);

    countdown(10);
}

void countdown(int max)
{
    for (int i=max; i>0; i--)
    {
        printf("%i, ", i);
    }
    printf("Blast off!\n");
}