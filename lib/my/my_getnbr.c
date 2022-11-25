/*
** EPITECH PROJECT, 2022
** GET NUMBER
** File description:
** my_getnbr
*/

int my_getnbr(const char *str)
{
    int i, nb = 0;

    for (i = 0; str[i]; i++)
        nb = nb * 10 + str[i] - '0';

    return (nb);
}
