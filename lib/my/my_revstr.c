/*
** EPITECH PROJECT, 2022
** REVSTR
** File description:
** my_revstr
*/

#include <stdlib.h>

int len(char const *str);
int my_putchar(char c);

char *my_revstr(char *str)
{
    int i, end = len(str) - 1;
    char *result = (char *) malloc((len(str) + 1) * sizeof(char));

    for (i = 0; end >= 0; end--, i++)
        result[i] = str[end];

    result[i + 1] = '\0';

    return (result);
}
