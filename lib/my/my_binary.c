/*
** EPITECH PROJECT, 2022
** OCTAL CONVERTER
** File description:
** my_octal
*/
char *my_revstr(char *str);

char *binary(unsigned int nb)
{
    char str[32];
    int a = 0;
    if (nb == 0)
        return ("0");
    while (nb > 1) {
        str[a] = (nb % 2) + '0';
        a++;
        nb = nb / 2;
    }
    if (nb != 0) {
        str[a] = '1';
        a++;
    }
    str[a] = '\0';
    return (my_revstr(str));
}
