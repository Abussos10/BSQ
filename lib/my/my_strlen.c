/*
** EPITECH PROJECT, 2022
** my putstr
** File description:
** C POOL DAY 04
*/

int len(char const *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
        i++;

    return (i);
}
