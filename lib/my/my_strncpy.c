/*
** EPITECH PROJECT, 2022
** Task 04
** File description:
** my_strcpy
*/

#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;
    for (index = 0; index < n && src[index] != '\0'; index++){
        dest[index] = src[index];
    }
    for (; index < n; index++){
        dest[index] = '\0';
    }
    return (dest);
}
