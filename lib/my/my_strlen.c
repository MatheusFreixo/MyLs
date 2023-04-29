/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** ...
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int index = 0;

    while (*str != '\0'){
        str = str + 1;
        index = index + 1;
    }
    return (index);
}
