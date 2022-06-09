#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{


    int age = 21;

    printf("Address of age is <%p>\n", &age);

    int *ip;
    ip = &age;

    printf("Value at address pointed to by *ip is <%i>\n", *ip);

    char name[20];
    char *p;

    //p = &name[0];
    p = name;

    printf("Address of name is <%p>\n", &name);

    //populate the "string" (char array)
    name[0]  = 'S';
    name[1]  = 'i';
    name[2]  = 'd';
    name[3]  = '\0';

    //PRINT THE STRING (ARRAY)
    for (p = name; *p != '\0'; p++ )
    {
        printf("%c", *p);
    }
    printf("\n");



    //Alternate method of popuating array
    char name2[20];
    char *p2;

    p2 = name2;
    *p2 = 'S';
    p2++;
    *p2++ = 'i';
    *p2++ = 'd';
    *p2++ = '\0';

    //PRINT THE STRING (ARRAY)
    for (p2 = name2; *p2 != '\0'; p2++ )
    {
        printf("%c", *p2);
    }
    printf("\n");

    char str[]="Hello Guru99!";
    char *p3;

    p3=str;
    printf("First character is:%c\n",*p3);
    p3=p3+1;
    printf("Next character is:%c\n",*p3);
    printf("Printing all the characters in a string\n");
    p3=str;  //reset the pointer
    for(int i=0;i<strlen(str);i++)
    {
        printf("%c",*p3);
        p3++;
    }
    printf("\n");
}