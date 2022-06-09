# include <stdio.h>
# include <cs50.h>

int main(void)
{
    //declarations
    float ctemp;
    float ftemp;

    ctemp = get_float("C: "); //get celcius
    ftemp = ((ctemp * 9.0) / 5.0) + 32.0; //convert celcius to fahrenheit
    printf("F: %.1f\n", ftemp); //print fahrenheit
}