/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** flag_R
*/

#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "../../include/my.h"
#include "../../include/my_ls.h"

int normal_list(my_ls_t ls, char *name)
{
    struct dirent *dr;
    struct stat stats;
    stat(name, &stats);
    DIR *dir = opendir(name);
    if (stats.st_size == 0){
        my_duoputstr(name, ":");
        return (1);
    }
    my_duoputstr(name, ":\n");
    while ((dr = readdir(dir)) != NULL) {
        if (*dr->d_name == '.')
            continue;
        if (dr->d_type == 4) {
            my_duoputstr("\033[38;5;183;1m", dr->d_name);
            my_putstr("\033[0m  ");
        } else
            my_duoputstr(dr->d_name, "  ");
    }
    closedir(dir);
    return (0);
}

int empty_folder(char *name, char *str, my_ls_t ls, int i)
{
    struct stat stats;
    char *dot = ".";

    my_putstr("\n");
    stat(str, &stats);

    if (error_message_empty(stats, str) == 84){
        return (84);
    }

    my_putstr("\n");
    my_duoputstr(str, ":");

    return (1);
}

int pt_lst(my_ls_t ls, char *name, int i)
{
    struct dirent *dr;
    struct stat stats;
    char *str = NULL;
    int ret = normal_list(ls, name), rtr = 0;
    DIR *dir = opendir(name);
    while ((dr = readdir(dir)) != NULL) {
        str = my_strcat(name, dr->d_name);
        stat(str, &stats);
        if (dr->d_type == 4 && stats.st_size == 0 && *dr->d_name != '.')
            rtr = empty_folder(name, str, ls, i);
        if (dr->d_type == 4 && stats.st_size != 0 && *dr->d_name != '.'){
            my_putstr("\n\n");
            pt_lst(ls, str, i);
            free(str);
        } if (rtr == 84)
            ret = 84;
    } if (name[0] != '.' && rtr == 1)
        ret = rtr;
    closedir(dir);
    return (ret);
}

int lst_dir(my_ls_t ls)
{
    struct stat stats;
    char *str;
    int ret = 0, rtr = 0, empty = 0;
    for (int i = ls.count, j = 0; i < ls.size; i++, j++){
        stat(ls.arg[i], &stats);
        rtr = error_message_r(stats, ls.arg[i]);
        ls.dir = opendir(ls.arg[i]);
        if (i != ls.count && rtr != 84)
            my_putstr("\n");
        if (S_ISREG(stats.st_mode))
            my_putstr(ls.arg[i]);
        if (S_ISDIR(stats.st_mode) && rtr != 84){
            str = ls.arg[i];
            empty = pt_lst(ls, str, i);
        } if (rtr != 84 || (i == ls.size - 1 && empty != 1))
            my_putchar('\n');
        if (rtr == 84 || empty == 84)
            ret = 84;
    }
    return (ret);
}

int flag_recursive(my_ls_t ls)
{
    int count_dir = 0;
    ls.count = 0;
    char *name = ".";
    for (int i = 1; i < ls.size; i++)
        if (ls.arg[i][0] != '-'){
            ls.count = i;
            break;
        }
    count_dir = ls.size - ls.count;
    if (count_dir == 2 && ls.count == 0){
        ls.dir = opendir(name);
        if (pt_lst(ls, name, -1) == 84){
            my_putchar('\n');
            return (84);
        } my_putchar('\n');
    } else {
        if (lst_dir(ls) == 84)
            return (84);
    }
    return (0);
}
