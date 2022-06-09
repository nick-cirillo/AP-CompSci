#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Enter password
    string pw;
    pw = get_string("Enter password: ");

    int hasUpper = 0;
    int hasLower = 0;
    int hasSymbol = 0;
    int hasDigit = 0;
    int score = 0;

    //loop thru the password (upper, lower, digit, symbol, LENGTH)
    for (int i = 0; i < strlen(pw); i++)
    {
        if (isupper(pw[i]) != 0)
        {
            hasUpper = 1;
        }
        else if (islower(pw[i]) != 0)
        {
            hasLower = 1;
        }
        else if(pw[i] >= 48 && pw[i] <= 57)
        {
            hasDigit = 1;
        }
        //    ((33-47) or (58-64) or (91-96))
        else if((pw[i] >= 33 && pw[i] <= 47) || (pw[i] >= 58 && pw[i] <= 64) || (pw[i] >= 91 && pw[i] <= 96))
        {
            hasSymbol = 1;
        }

    }

    //calc score
    int base;

    //add 1 to base to ensure base is at least 2
    base = 1 + hasUpper + hasLower + hasDigit + hasSymbol;

    //print result
    //score = base ^ length
    score = pow(base, strlen(pw));
    printf("Score = %i\n", score);


}