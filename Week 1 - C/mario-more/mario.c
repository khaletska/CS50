#include <cs50.h>
#include <stdio.h>

void printHashtag(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void printSpace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

int main(void)
{
    int n;
    do
    {
        printf("Write a number between 1 and 8\n");
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        printSpace(n - i);
        printHashtag(i);
        printSpace(2);
        printHashtag(i);
        printf("\n");
    }
}
