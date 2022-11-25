/*
** EPITECH PROJECT, 2022
** IS THIS STR NUMBER ONLY
** File description:
** is_number
*/

// return 1 if it is number else 0
int is_number(const char *str)
{
    int i;

    for (i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        return (0);
    }

    return (1);
}
