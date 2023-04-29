/*
** EPITECH PROJECT, 2022
** MY_PUTCHAR
** File description:
** ...
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
