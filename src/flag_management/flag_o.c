/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** ...
*/

#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include "../../include/my.h"
#include "../../include/my_ls.h"

void display_name_dr_file(my_ls_t ls)
{
    if (ls.dr->d_type == 4){
        my_duoputstr("\033[38;5;183;1m", ls.dr->d_name);
        my_duoputstr("\033[0m", "\n");
    } else {
        my_duoputstr(ls.dr->d_name, "\n");
    }
}

void pt_ls(my_ls_t ls, char *name)
{
    struct group *gp;
    struct passwd *pd;
    struct stat stats;
    char *str = NULL;
    while ((ls.dr = readdir(ls.dir)) != 0 && ls.arg != 0){
        if (*ls.dr->d_name != '.'){
            str = my_strcat(name, ls.dr->d_name);
            get_permissions(str);
            get_nlink(str);
            get_gr_usr(str, 'o');
            get_size(str);
            get_time(str);
            display_name_dr_file(ls);
        }
    }
}

void ls_dir(my_ls_t ls, int count, int count_dir)
{
    struct stat stats;
    for (int i = count, j = 0; i < ls.size; i++, j++){
        stat(ls.arg[i], &stats);
        ls.dir = opendir(ls.arg[i]);
        if (count_dir > 1){
            my_duoputstr(ls.arg[i], ":\n");
        }
        if (S_ISREG(stats.st_mode)){
            get_permissions(ls.arg[i]);
            get_nlink(ls.arg[i]);
            get_gr_usr(ls.arg[i], 'l');
            get_size(ls.arg[i]);
            get_time(ls.arg[i]);
            my_duoputstr(ls.arg[i], "\n");
        } if (S_ISDIR(stats.st_mode)){
            my_putstr("total 56\n");
            pt_ls(ls, ls.arg[i]);
        } if (i != ls.size - 1)
            my_putchar('\n');
    }
}

void flag_o(my_ls_t ls)
{
    int count = 0, count_dir = 0;
    char *name = ".";

    for (int i = 1; i < ls.size; i++){
        if (ls.arg[i][0] != '-'){
            count = i;
            break;
        }
    }
    count_dir = ls.size - count;
    if (count_dir == 2 && count == 0){
        ls.dir = opendir(name);
        my_putstr("total 56\n");
        pt_ls(ls, name);
    } else {
        ls_dir(ls, count, count_dir);
    }
}
