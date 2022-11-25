/*
** EPITECH PROJECT, 2022
** IS BSQ FRIENDLY
** File description:
** is_alpha
*/

// checking if the input string is bsq friendly ('o' or '.')
int is_bsq_friendly(const char *str)
{
    int i;

    for (i = 0; str[i]; i++) {
        if (str[i] == 'o' || str[i] == '.')
            continue;
        return (0);
    }

    return (1);
}
