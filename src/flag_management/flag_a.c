/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** ...
*/

#include <dirent.h>
#include <sys/stat.h>
#include "../../include/my.h"
#include "../../include/my_ls.h"

void print_ls(my_ls_t ls)
{
    while ((ls.dr = readdir(ls.dir)) != 0 && ls.arg != 0){
        if (ls.dr->d_type == 4){
            my_duoputstr("\033[38;5;183;1m", ls.dr->d_name);
            my_putstr("\033[0m  ");
        } else {
            my_duoputstr(ls.dr->d_name, "  ");
        }
    }
}

void list_dr(my_ls_t ls, int count, int count_dir)
{
    struct stat stats;
    for (int i = count, j = 0; i < ls.size; i++, j++){
        stat(ls.arg[i], &stats);
        ls.dir = opendir(ls.arg[i]);
        if (count_dir > 1){
            my_duoputstr(ls.arg[i], ":");
            my_putchar('\n');
        } if (S_ISREG(stats.st_mode))
            my_putstr(ls.arg[i]);
        if (S_ISDIR(stats.st_mode)){
            print_ls(ls);
        }
        if (i != ls.size - 1)
            my_putchar('\n');
        my_putchar('\n');
    }
}

void flag_a(my_ls_t ls)
{
    int count = 0, count_dir;
    for (int i = 1; i < ls.size; i++){
        if (ls.arg[i][0] != '-'){
            count = i;
            break;
        }
    }
    count_dir = ls.size - count;
    if (count_dir == 2 && count == 0){
        ls.dir = opendir(".");
        print_ls(ls);
        my_putchar('\n');
    } else {
        list_dr(ls, count, count_dir);
    }
}
