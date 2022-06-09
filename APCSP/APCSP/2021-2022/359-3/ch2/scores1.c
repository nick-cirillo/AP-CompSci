# include <stdio.h>
# include <cs50.h>

void chart(int scores[], int len);

int main(void)
{
    int len = 0;
    while (len <= 0)
    {
        len = get_int("How many numbers? "); //get array length
    }

    int scores[len];

    for (int i = 0; i < len; i++)
    {
        scores[i] = get_int("Enter score #%i: ", i + 1); //get each score
    }

    int tot = 0;
    for (int i = 0; i < len; i++)
    {
        tot += scores[i];
    }

    float avg = (float)tot / len;
    printf("Average: %f\n", avg);

    chart(scores, len);
}

void chart(int scores[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%i:", scores[i]);
        for (int j = 0; j < scores[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}