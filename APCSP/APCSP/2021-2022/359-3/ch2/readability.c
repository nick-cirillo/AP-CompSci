# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>
# include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void print_grade(int index);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (100.0 * (float)letters) / (float)words;
    float S = (100.0 * (float)sentences) / (float)words;
    int index = round(0.0588 * L - 0.296 * S  - 15.8);
    print_grade(index);
}

int count_letters(string text)
{
    int len = strlen(text);
    int letters = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int len = strlen(text);
    int words = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ' || i == len - 1)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int len = strlen(text);
    int sentences = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

void print_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}