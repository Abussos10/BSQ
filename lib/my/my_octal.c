/*
** EPITECH PROJECT, 2022
** OCTAL CONVERTER
** File description:
** my_octal
*/
char *my_revstr(char *str);

char *convert_octal(unsigned int nb)
{
    int a = 0;
    char str[200];
    if (nb == 0)
        str[0] = '0';
    while (nb > 0){
        str[a] = (nb - ((nb / 8) * 8)) + '0';
        a++;
        nb = (nb / 8);
    }
    str[a + 1] = '\0';

    return (my_revstr(str));
}
