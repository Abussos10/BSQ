/*
** EPITECH PROJECT, 2022
** CPOOL DAY 5
** File description:
** square root
*/

int my_compute_square_root(int nb)
{
    int i;

    for (i = 0; i * i != nb; i++) {
        if (i > nb) {
            i = 0;
            break;
        }
    }

    return (i);
}
