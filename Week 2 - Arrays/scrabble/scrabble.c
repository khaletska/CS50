#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int countPoints(string word);

const int VALUES[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    int score1 = countPoints(player1);
    int score2 = countPoints(player2);

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


int countPoints(string word)
{
    int wordLength = strlen(word);
    int points = 0;
    for (int i = 0; i < wordLength; i++)
    {
        if (!isalpha(word[i]))
        {
            continue;
        }
        else
        {
            points += VALUES[toupper(word[i]) - 65];
        }
    }
    return points;
}
