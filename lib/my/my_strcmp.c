/*
** EPITECH PROJECT, 2022
** STRCMP
** File description:
** C POOL DAY 06
*/

#include <stdio.h>
int len(char const *str);

int my_strcmp(char *s1, char *s2)
{
    int i;
    int count = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[i])
            count++;
    }

    if (len(s1) - 1 != count)
        return (1);

    return (0);
}
