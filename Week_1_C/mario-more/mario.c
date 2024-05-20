#include <cs50.h>
#include <stdio.h>

void printSymbols(char symbol, int n);

int main(void)
{
    int n;
    do
    {
        printf("Write a number between 1 and 8\n");
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    char space = ' ';
    char hashtag = '#';
    for (int i = 1; i <= n; i++)
    {
        printSymbols(space, n - i);
        printSymbols(hashtag, i);
        printSymbols(space, 2);
        printSymbols(hashtag, i);
        printf("\n");
    }
}

void printSymbols(char symbol, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", symbol);
    }
}
