/*
** EPITECH PROJECT, 2022
** PUT STR
** File description:
** my_putstr
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);

    return (i);
}
