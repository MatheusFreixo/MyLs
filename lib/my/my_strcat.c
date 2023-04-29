/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** strcat
*/

#include <stddef.h>
#include "../../include/my.h"

char *my_strcat(char *dest, const char *src)
{
    size_t dest_len = my_strlen(dest);
    size_t src_len = my_strlen(src);
    size_t size = dest_len + src_len + 1;
    size_t i, j;
    char *str = malloc(sizeof(char) * size + 1);

    for (i = 0, j = 0; i < size; i++){
        if (i < dest_len)
            str[i] = dest[i];
        if (i == dest_len && dest[dest_len - 1] != '/')
            str[i] = '/';
        if (i > dest_len || (i >= dest_len && dest[dest_len - 1] == '/')){
            str[i] = src[j];
            j++;
        }
    }
    str[i] = '\0';
    return (str);
}
