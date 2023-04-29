/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** ...
*/

#include "./../../include/my.h"
#include <unistd.h>

int my_duoputstr(char *str, char *c)
{
    int len = my_strlen(str);
    int length = my_strlen(c);
    write(1, str, len);
    write(1, c, length);
    return (0);
}
