#include <cs50.h>
#include <stdio.h>

string checkCardNumber(long n);
string findPaymentSystem(int length, int firstDigit, int secondDigit);

int main(void)
{
    long n = get_long("Enter the card number: ");
    printf("%s", checkCardNumber(n));
}

string checkCardNumber(long n)
{
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
        return "INVALID\n";
    }

    return findPaymentSystem(length, digit, previousDigit);
}

string findPaymentSystem(int length, int firstDigit, int secondDigit)
{
    bool amex = length == 15 &&
                ((firstDigit == 3 && secondDigit == 4) || (firstDigit == 3 && secondDigit == 7));
    bool mastercard = length == 16 && firstDigit == 5 && secondDigit >= 1 && secondDigit <= 5;
    bool visa = (length == 13 && firstDigit == 4) || (length == 16 && firstDigit == 4);

    if (amex)
    {
        return "AMEX\n";
    }
    else if (mastercard)
    {
        return "MASTERCARD\n";
    }
    else if (visa)
    {
        return "VISA\n";
    }
    return "INVALID\n";
}
