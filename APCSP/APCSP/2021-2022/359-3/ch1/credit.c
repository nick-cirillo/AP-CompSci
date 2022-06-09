#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

string getCardType(long num);
int getCardLen(long num);
int getCheckDigit(long num);

int main(void){

    long cc0, cc1, cc2, cc3;



    cc0 = get_long("Number: ");

    //4545 4545 4545 4545

    string t = getCardType(cc0);
   //printf("type = %s\n", t);

    int l = getCardLen(cc0);
    //printf("len  = %i\n", l);

    int cd = getCheckDigit(cc0);
    //printf("check = %i\n", cd);

    if((strcmp(t,"MASTERCARD") == 0) && (l == 16) && (cd == 0)) {
        printf("MASTERCARD\n");
    }
    else if((strcmp(t,"VISA") == 0) && ( (l == 13) || (l == 16) ) && (cd == 0)){
        printf("VISA\n");
    }
    else if((strcmp(t,"AMEX") == 0) && (l == 15) && (cd == 0)){
        printf("AMEX\n");
    }
    else {
        printf("INVALID\n");
    }




}

string getCardType(long num) {

    string type;

    while (num > 99) {
        num = num / 10;
    }

    if (num >= 40 && num <= 49) {
        type = "VISA";
    }
    else if (num >= 51 && num <= 55){
        type = "MASTERCARD";
    }
    else if(num == 34 || num == 37) {
        type = "AMEX";
    }
    else {
        type = "INVALID";
    }
    return type;

}

int getCardLen(long num){
    int len = 0;

    while(num >= 1){
        num = num / 10;
        len++;
    }
    return len;

}

int getCheckDigit(long num){
    long num2 = num;

    int d;
    int p;
    int ones;
    int tens;
    int sum;
    int total = 0;

    //process first set of alt digits

    num = num / 10;

    while(num >= 1){

        d = num % 10;   //get last digit
        d = d * 2;  //double
        ones = d % 10;

        if (d >= 10){
            ones++;
        }
        total = total + ones;
        num = num / 100;

    }

    while(num2 >= 1) {
        d = num2 % 10;
        total = total + d;
        num2 = num2 / 100;
    }

    return total % 10;

}










//Nick's shit broken code
/*# include <stdio.h>
# include <cs50.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

long num;
long numTemp;
int len; //gth
string type;
bool isValid;
int curDigit;
int a;
int b;
int sum;
int dig1;


void GetDigits(int digits[]);
void CardType(int digits[]);

int main(void)
{
    num = get_long("Number: ");

    if (num <= 0) //avoid issues with log and reject negatives
    {
        type = "INVALID";
    }
    else
    {
        len = floor(log10(labs(num))) + 1; //how many digits
        int digits[len]; //must be declared here
        //detect if valid length (13-16 digits)

        if (len < 13 || len > 16)
        {
            type = "INVALID";
        }
        else
        {
            GetDigits(digits);
            CardType(digits); //identify card type
        }
    }



printf("%s\n",type); //print card type
}

void GetDigits(int digits[])
{
    numTemp = num;
    for (int i = 0; i < len; i++)
    {
        curDigit = numTemp % 10; // get each digit
        numTemp = numTemp / 10; //move digits right
        digits[i] = curDigit; //put into array
        printf("%i, %i\n", digits[i], i);
    }
}

void CardType(int digits[])
{
    int aList[32];
    for (int i = 1; i <= len - 1; i += 2) //iterates through digits 2 at a time from 2nd-to-last. -1 because array is 0-indexed
    {
        int curProdA = digits[i] * 2;
        int lenProdA;
        if (curProdA > 0)
        {
            lenProdA = floor(log10(labs(curProdA))) + 1;
            int curDigProdA = curProdA % 10;
            printf("cdp %i\n", curDigProdA);
            if (curDigProdA > 0)
            {
                aList[i - 1] = curDigProdA;
            }
            curProdA /= 10;
            curDigProdA = curProdA % 10;
            printf("cdp %i\n", curDigProdA);
            if (curDigProdA > 0)
            {
                aList[i] = curDigProdA;
            }
            printf("%i\n%i\n", aList[i - 1], aList[i]);
        }



    }


    for (int i = 0; i <= 32; i++)
    {
        printf("aList[i]: %i\n", aList[i]);
        if (aList[i] > 0)
        {

            a += aList[i];
            //printf("a = %i\n", a);
        }
    }
























    printf("%i\n", a);

















    for (int j = 0; j <= len - 1; j += 2) //iterates 2 at a time from last digit (-1 bc 0-index)
    {
        b += digits[j];
    }
    printf("%i\n", b);

    sum = a + b;
    printf("%i\n", sum);
    //validity
    if (sum % 10 == 0)
    {
        isValid = true;
    }
    else
    {
        isValid = false;
    }
    printf("%d", isValid);
    if (isValid)
    {
        //finds first two digits
        dig1 = digits[len];
        printf("%i", dig1);
        //cardType
        if (dig1 == 4)
        {
            type = "VISA";
        }
        else if (dig1 == 3)
        {
            type = "AMEX";
        }
        else if (dig1 == 5)
        {
            type = "MASTERCARD";
        }
        else
        {
            type = "INVALID";
        }
    }

}*/