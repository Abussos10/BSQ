/*
** EPITECH PROJECT, 2022
** MY H
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

int my_putstr(char const *str);

int is_number(const char *str);

int my_putchar(char c);

int my_put_nbr(int nb);

int len(char const *str);

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

char *convert_octal(unsigned int nb);

int my_getnbr(const char *str);

int my_compute_square_root(int nb);

int is_bsq_friendly(const char *str);

int get_int_len(int nb);

#endif /* !MY_H_ */
