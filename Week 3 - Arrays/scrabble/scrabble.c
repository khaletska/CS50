#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int getIndex(char key);
int getValue(char key);
int countPoints(string word);

int SIZE = 26;
char KEYS[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int VALUES[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string p1 = get_string("Player1: ");
    string p2 = get_string("Player2: ");

    int score1 = countPoints(p1);
    int score2 = countPoints(p2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int getIndex(char key)
{
    char uppercase = toupper(key);
    for (int i = 0; i < SIZE; i++)
    {
        if (KEYS[i] == uppercase)
        {
            return i;
        }
    }
    return -1;
}

int getValue(char key)
{
    int index = getIndex(key);
    if (index == -1)
    {
        return 0;
    }
    else
    {
        return VALUES[index];
    }
}

int countPoints(string word)
{
    int n = 0;
    int points = 0;
    while (word[n] != 0)
    {
        points += getValue(word[n]);
        n++;
    }
    return points;
}
