/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** ...
*/

#include "./../../include/my.h"
#include <unistd.h>

int my_putstr(char *str)
{
    int len = my_strlen(str);
    write(1, str, len);
    return (0);
}
