# include <stdio.h>
# include <cs50.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

void GameInit(void);
void PrintBoard(int rnd, string guesses[]); //round ad guesses
void PrintEquals(int n);
void PrintWord(string word, string ans);
string sol;

int main(void)
{
    GameInit();
    string guesses[5];
    for (int i = 0; i < 6; i++)
    {
        guesses[i] = get_string("Guess %i: ", i + 1);
        PrintBoard(i, guesses);
    }
}


void GameInit(void)
{
    system("clear");
    sol = get_string("Solution: ");
    char sol_i[5];
    for (int i = 0; i < 5; i++)
    {
        sol_i[i] = toupper(sol[i]);
    }
    system("clear"); //get answer to game and clear screen
}

void PrintBoard(int rnd, string guesses[]) //round and guesses
{
    system("clear");
    for (int j = 0; j <= rnd; j++)
    {
        PrintEquals(36);
        printf("\n");
        PrintWord(guesses[j], sol);
    }
}

void PrintEquals(int n)
{
    for (int j = 1; j <= n; j++) //print certan num of =
    {
        printf("=");
    }
    printf("\n");
}

void PrintWord(string word, string ans)
{
    char done[5];
    for (int j = 0; j < 5; j++)
    {
        string anl;
        printf("    ");
        if (word[j] == ans[j])
        {
            anl = "O";
        }
        else if ((word[j] == ans[0] || word[j] == ans[1] || word[j] == ans[2] || word[j] == ans[3] || word[j] == ans[4]) && (word[j] != done[0] && word[j] != done[1] && word[j] != done[2] && word[j] != done[3] && word[j] != done[4]))
        {
            anl = "~";
            done[j] = word[j];
        }
        else
        {
            anl = "X";
            done[j] = word[j];
        }
        printf("%s ", anl); //print X, ~ or O
        printf("%c", word[j]);
    }
    printf("\n");
}