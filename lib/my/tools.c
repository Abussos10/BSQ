/*
** EPITECH PROJECT, 2022
** SOME TOOLS
** File description:
** tools
*/

int abs(int value);

int get_int_len(int nb)
{
    int len = 1;

    if (nb < 0) {
        nb = abs(nb);
        len++;
    }
    for (; nb > 9; len++)
        nb /= 10;

    return (len);
}

int abs(int value)
{
    if (value < 0)
        return (value * -1);
    else
        return (value);
}
