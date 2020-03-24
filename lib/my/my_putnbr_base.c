/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** my put nbr for any base
*/

#include "../../include/my.h"

static int displaynbr_base(const int nbr, const int len, const char *base)
{
    int i = 0;

    if (nbr < 0)
    {
        my_putchar('-');

        i = nbr % len * (-1);
        displaynbr_base(nbr / len * -1, len, base);
        my_putchar(base[i]);
    }

    if (nbr > 0)
    {
        i = nbr % len;

        displaynbr_base(nbr / len, len, base);
        my_putchar(base[i]);
    }

    return 0;
}

int my_putnbr_base(int nbr, const char *base)
{
    if (nbr == 0)
    {
        my_putchar('0');
        return 0;
    }

    const int len = my_strlen(base);

    return displaynbr_base(nbr, len, base);
}