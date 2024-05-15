#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long("Enter the card number: ");
    int digit;
    int previousDigit;
    int length = 0;
    int checksum = 0;

    while (n > 0)
    {
        previousDigit = digit;
        digit = n % 10;
        length++;
        n /= 10;

        if (length % 2 == 0)
        {
            int doubledDigit = digit * 2;
            while (doubledDigit > 0)
            {
                checksum += doubledDigit % 10;
                doubledDigit /= 10;
            }
        }
        else
        {
            checksum += digit;
        }
    }

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        bool amex = length == 15 &&
                    ((digit == 3 && previousDigit == 4) || (digit == 3 && previousDigit == 7));
        bool mastercard = length == 16 && digit == 5 && previousDigit >= 1 && previousDigit <= 5;
        bool visa = (length == 13 && digit == 4) || (length == 16 && digit == 4);

        if (amex)
        {
            printf("AMEX\n");
        }
        else if (mastercard)
        {
            printf("MASTERCARD\n");
        }
        else if (visa)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
