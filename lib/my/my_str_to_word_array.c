/*
** EPITECH PROJECT, 2019
** my str to word array
** File description:
** try 2
*/

#include <stdlib.h>

int my_strlen(char const *str);

int greatest(int a, int b);

int test_alphanum(char c)
{
    if ((c >= '0') && (c <= '9')) {
        return (1);
    } else {
        if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
            return (1);
        }
        return (0);
    }
}

int count_my_sub(char *str, int l)
{
    int c_substr;

    for (int i = 0; i < l; i += 1) {
        if (test_alphanum(str[i]) == 1 && test_alphanum(str[i + 1]) == 0) {
            c_substr += 1;
        }
    }
    return (c_substr);
}

char **my_str_to_word_array(char *str)
{
    char **str2;
    int len = my_strlen(str);
    int size_array = count_my_sub(str, len);
    int size_word = 0;
    int first_l;
    int j = 0;

    str2 = malloc(sizeof(char *) * size_array);
    for (int i = 0; str[i] != '\0'; i += 1) {
        for (; test_alphanum(str[i]) == 1; i += 1) {
            size_word += 1;
            first_l = i - size_word;
        }
        if (size_word != 0)
            str2[j] = malloc(sizeof(char *) * (size_word + 1));
        for (int letter = 0; first_l <= i; first_l += 1)
            str2[j][letter] = str[first_l];
        if (test_alphanum(i + 1) == 1)
            j += 1;
        size_word = 0;
    }
    return (str2);
}

int main(int argc, char **argv)
{
    char test[] = "tryhard you bastard";
    my_str_to_word_array(test);
}
