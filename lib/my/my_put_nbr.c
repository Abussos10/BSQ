/*
** EPITECH PROJECT, 2022
** PUT NBR
** File description:
** my_put_nbr
*/

int my_putchar(char c);
int get_int_len(int nb);
int abs(int value);

int my_put_nbr(int nb)
{
    int tmp = nb;
    if (tmp < 0) {
        my_putchar('-');
        tmp = abs(tmp);
    }

    if (tmp < 10) {
        my_putchar(tmp + '0');
        return (0);
    } else {
        my_put_nbr(tmp / 10);
    }
    my_putchar((tmp % 10) + '0');

    return (0);
}
