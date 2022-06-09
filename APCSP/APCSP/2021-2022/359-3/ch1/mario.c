# include <stdio.h>
# include <cs50.h>

void printPyramid(int size);
void printSpaces(int spaces);
void printHashtags(int size);

int main(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    printPyramid(height);
}

void printPyramid(int size)
{
    int hashes;
    int spaces;
    int midspace = 2;
    for (int i = 1; i <= size; i++)
    {
        hashes = i;
        spaces = size - hashes;
        printSpaces(spaces);
        printHashtags(hashes);
        printSpaces(midspace);
        printHashtags(hashes);
        printf("\n");
    }
}

void printSpaces(int size)
{
    for (int j = 0; j < size; j++)
    {
        printf(" ");
    }
}

void printHashtags(int size)
{
    for (int j = 0; j < size; j++)
    {
        printf("#");
    }
}

