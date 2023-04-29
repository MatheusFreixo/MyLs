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

void prt_ls(my_ls_t ls, int i)
{
    if ((ls.dr = readdir(ls.dir)) != 0 && ls.arg != 0){
        if (ls.dr->d_type == 4){
            my_duoputstr("\033[38;5;183;1m", ls.arg[i]);
            my_putstr("\033[0m  ");
        } else {
            my_duoputstr(ls.dr->d_name, "  ");
        }
    }
}

void lst_dr(my_ls_t ls, int count, int count_dir)
{
    struct stat stats;
    for (int i = count, j = 0; i < ls.size; i++, j++){
        stat(ls.arg[i], &stats);
        ls.dir = opendir(ls.arg[i]);
        if (S_ISDIR(stats.st_mode)){
            prt_ls(ls, i);
        } else {
            my_duoputstr(ls.arg[i], "  ");
        }
    }
    my_putchar('\n');
}

void flag_d(my_ls_t ls)
{
    int count = 0, count_dir = 0;

    for (int i = 1; i < ls.size; i++){
        if (ls.arg[i][0] != '-'){
            count = i;
            break;
        }
    }
    count_dir = ls.size - count;
    if (count_dir == 2 && count == 0){
        ls.dir = opendir(".");
        if ((ls.dr = readdir(ls.dir)) != 0 && ls.arg != 0){
            my_duoputstr(ls.dr->d_name, "\n");
        }
    } else {
        lst_dr(ls, count, count_dir);
    }

}
