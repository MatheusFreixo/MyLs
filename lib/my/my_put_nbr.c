/*
** EPITECH PROJECT, 2022
** MY_PUT_NBR
** File description:
** ...
*/

#include "./../../include/my.h"

int my_put_nbr(int nb)
{
    int modulo;

    if (nb <= 9 && nb >= 0){
        my_putchar(nb + '0');
    }if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
        if (nb <= 9 && nb >= 0)
            my_put_nbr(nb);
    }if (nb > 9){
        modulo = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(modulo + '0');
    }
    return (0);
}
