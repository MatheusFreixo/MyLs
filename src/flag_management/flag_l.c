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

void pt_list(my_ls_t ls, char *name, int i)
{
    struct stat stats;
    char *str = NULL;
    while ((ls.dr = readdir(ls.dir)) != 0 && ls.arg != 0){
        if (*ls.dr->d_name != '.'){
            str = my_strcat(name, ls.dr->d_name);
            get_permissions(str);
            get_nlink(str);
            get_gr_usr(str, 'l');
            get_size(str);
            get_time(str);
            print_name_dir_file(ls, i);
            free(str);
        }
    }
}

int ls_dr(my_ls_t ls, int count, int count_dir)
{
    struct stat s;
    int ret = 0, rtr = 0;
    for (int i = count, j = 0; i < ls.size; i++, j++){
        stat(ls.arg[i], &s);
        rtr = error_message(s, ls.arg[i]);
        if (i != count && rtr != 84)
            my_putchar('\n');
        if (count_dir > 1 && rtr != 84 && S_ISDIR(s.st_mode))
            my_duoputstr(ls.arg[i], ":\n");
        if (S_ISREG(s.st_mode)){
            print_all_file_info(ls, i);
        } if (S_ISDIR(s.st_mode) && rtr != 84){
            print_total(ls, ls.arg[i]);
            ls.dir = opendir(ls.arg[i]);
            pt_list(ls, ls.arg[i], i);
        } if (rtr == 84)
            ret = 84;
    }
    return (ret);
}

int flag_l(my_ls_t ls)
{
    int count = 0;
    int count_dir = 0;
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
        print_total(ls, name);
        pt_list(ls, name, 0);
    } else {
        if (ls_dr(ls, count, count_dir) == 84)
            return (84);
    }
    return (0);
}
