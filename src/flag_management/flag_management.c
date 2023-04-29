/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** flags
*/

#include <stdio.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/my_ls.h"

int flag_management(my_ls_t ls)
{
    if (my_strcmp(ls.arg[1], "-a") == 0)
        flag_a(ls);

    if (my_strcmp(ls.arg[1], "-d") == 0)
        flag_d(ls);

    if (my_strcmp(ls.arg[1], "-l") == 0)
        if (flag_l(ls) == 84)
            return (84);

    if (my_strcmp(ls.arg[1], "-R") == 0)
        if (flag_recursive(ls) == 84)
            return (84);

    if (my_strcmp(ls.arg[1], "-o") == 0)
        flag_o(ls);
    return (0);
}
