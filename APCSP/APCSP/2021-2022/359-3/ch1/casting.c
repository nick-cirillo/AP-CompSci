# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int a;
    a = 19/6;
    printf("a = %i\n", a);

    float b;
    b = 19/6;
    printf("b = %f\n", b);

    float c;
    c = (float)19/(float)6;
    printf("c = %f\n", c);

    float d = (float)19/6;
    printf("d = %f\n", d);

    float e, f, g;
    e = 10.2 * (1/2);
    e = 10.2 * ((float)1/2);
    f = 10.2 * 1.0 / 2;
    g = (10.2 * 1) / 2;
    printf("e = %f\n", e);
    printf("f = %f\n", f);
    printf("g = %f\n", g);
}