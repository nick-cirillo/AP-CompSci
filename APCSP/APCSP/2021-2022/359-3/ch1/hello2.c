#include <stdio.h>
#include <cs50.h>

int main(void) {

    //Declare variables
    int age = 0;
    float wage;
    int hours;
    string fName;
    float totalPay;

    fName = get_string("What's your name?\n");

    while (age <= 0 || age > 105) {
    age = get_int("How old are you?\n");
    }

    if (age < 21) {
        printf("Milk for you\n");
    }
    else {
        printf("Wine for you\n");
    }

    if (age < 18) {
        printf("Can't vote\n");
    }
    else if (age < 65) {
        printf("Go to work and vote at night\n");
    }
    else {
        printf("Let's golf and vote after lunch\n");
    }

    if (age > 18) {
        wage = get_float("How much do you earn per hour?\n");
        hours = get_int("How many hours did you work this week?\n");
        totalPay = wage * hours;
        printf("Hello, %s. You worked %i hours at $%.2f an hour.\n", fName, hours, wage);
        printf("You earned $%.2f this week.\n", totalPay);
    }

}