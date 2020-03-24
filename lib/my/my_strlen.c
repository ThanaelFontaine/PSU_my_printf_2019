/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** give array length
*/

int my_strlen(char const *str)
{
    int n = 0;

    while (str[n])
        n++;

    return (n);
}
