# include <stdio.h>
# include <cs50.h>
# include <math.h>
# include <stdlib.h>

long long isbn;
long long isbnTemp;
int len;
int curDigit;
int checkSum;
int sum = 0;

int main(void)
{
    isbn = get_long_long("ISBN: "); //keep
    isbnTemp = isbn; //will be changed later

    len = floor(log10(llabs(isbn))) + 1;
    int digits[len]; //must declare here

    for (int i = 1; i <= len; i++)
    {
        curDigit = isbnTemp % 10; // get each digit
        digits[i] = curDigit; //put into array
        isbnTemp = isbnTemp / 10; //move digits right
    }

    checkSum = digits[1];
    //calculate sum
    for (int i = 1; i <= len; i++)
    {
        sum += digits[i] * (11 - i);
    }

    if ((sum - (checkSum * 10)) % 11 == checkSum && sum % 11 == 0)//sumchecks (redundant)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}