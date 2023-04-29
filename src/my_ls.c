/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** ...
*/

#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/my_ls.h"

int print_list(my_ls_t ls, char *name, int ret, int i)
{
    struct stat stats;
    stat(name, &stats);
    if (error_message(stats, name))
        return (84);
    while ((ls.dr = readdir(ls.dir)) != 0 && ls.arg != 0){
        if (*ls.dr->d_name != '.' && ls.dr->d_type == 4){
            my_duoputstr("\033[38;5;183;1m", ls.dr->d_name);
            my_putstr("\033[0m  ");
            continue;
        } if (*ls.dr->d_name != '.' && ls.dr->d_type != 4){
            my_duoputstr(ls.dr->d_name, "  ");
        }
    }
    my_putchar('\n');
    return (0);
}

int getfile_dir_pos(my_ls_t ls)
{
    int count = 0;
    for (int i = 1; i < ls.size; i++)
        if (ls.arg[i][0] != '-'){
            count = i;
            break;
        }
    return (count);
}

int list(my_ls_t ls)
{
    struct stat s;
    ls.count = getfile_dir_pos(ls);
    int count_dir = ls.size - ls.count;
    int ret = 0, rtr = 0;
    for (int i = ls.count, j = 0; i < ls.size; i++, j++){
        stat(ls.arg[i], &s);
        rtr = error_message(s, ls.arg[i]);
        if (i != ls.count && rtr != 84)
            my_putstr("\n");
        ls.dir = opendir(ls.arg[i]);
        if (count_dir > 1 && rtr != 84 && S_ISDIR(s.st_mode))
            my_duoputstr(ls.arg[i], ":\n");
        if (S_ISREG(s.st_mode))
            my_duoputstr(ls.arg[i], "\n");
        if (S_ISDIR(s.st_mode) && rtr != 84 && s.st_size != 0)
            rtr = print_list(ls, ls.arg[i], ret, i);
        if (rtr == 84)
            ret = 84;
    } return (ret);
}

int list_normal(my_ls_t ls)
{
    int ret = 0;
    char *name = ".";
    struct stat stats;

    if (ls.size == 1){
        ls.dir = opendir(name);
        print_list(ls, name, 0, 10000);
    } else {
        ret = list(ls);
    }

    return (ret);
}

int main (int argc, char **argv)
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0){
        usage();
        return (1);
    }
    my_ls_t ls;
    ls.arg = argv;
    ls.size = argc;
    if (argc == 1 || argv[1][0] != '-') {
        if (list_normal(ls) == 84)
            return (84);
        return (0);
    }
    if (argv[1][0] == '-'){
        if (my_strcmp(argv[1], "-l") != 0 && my_strcmp(argv[1], "-R") != 0 &&
        my_strcmp(argv[1], "-a") != 0 && my_strcmp(argv[1], "-o") != 0 &&
        my_strcmp(argv[1], "-d") != 0){
            usage();
            exit(1);
        }
        if (flag_management(ls) == 84)
            return (84);
        return (0);
    }
    return (0);
}
