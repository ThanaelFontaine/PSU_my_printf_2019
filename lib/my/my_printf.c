/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/printffonct.h"
#include "../../include/my.h"
#include "my_printf2.c"
#include "my_printf3.c"

typedef struct struc_s
{
    char c;
    void (*function)(va_list);
} struc_t;

static const struc_t tableau[] =
{
    {'s', is_a_string},
    {'c', is_a_character},
    {'d', is_a_nbr},
    {'i', is_a_nbr2},
    {'p', is_a_pointer},
    {'x', is_hexa_base},
    {'X', is_Hexa_base},
    {'b', is_a_binary},
    {'o', is_a_octal},
    {'u', is_a_unsigned},
    {'\0', NULL}
};

void le_tableau(char c, va_list ap)
{
    int boule = 0;

    for (int g = 0; tableau[g].c; g += 1) {
        if (c == tableau[g].c) {
            tableau[g].function(ap);
            boule = 1;
        }
    }
    if (boule == 0) {
        my_putchar('%');
        my_putchar(c);
    }
}

int my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);

    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '%') {
            i += 1;
            le_tableau(str[i], ap);
        }
        else
            my_putchar(str[i]);
    }
    va_end(ap);
}