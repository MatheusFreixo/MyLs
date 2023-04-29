/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** get information of the file/folder
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

void print_name_dir_file(my_ls_t ls, int i)
{
    if (ls.dr->d_type == 4){
        my_duoputstr("\033[38;5;183;1m", ls.dr->d_name);
        my_putstr("\033[0m");
    } else {
        my_putstr(ls.dr->d_name);
    }
    my_putchar('\n');
}

void print_all_file_info(my_ls_t ls, int i)
{
    get_permissions(ls.arg[i]);
    get_nlink(ls.arg[i]);
    get_gr_usr(ls.arg[i], 'l');
    get_size(ls.arg[i]);
    get_time(ls.arg[i]);
    my_duoputstr(ls.arg[i], "\n");

}

void print_total(my_ls_t ls,char *name)
{
    struct stat stats;
    char *str = NULL;
    int total = 0;
    DIR *dir = opendir(name);
    while ((ls.dr = readdir(dir)) != 0){
        str = my_strcat(name, ls.dr->d_name);
        stat(str, &stats);
        total = stats.st_blocks + total;
    }
    closedir(dir);
    my_putstr("total ");
    my_put_nbr(total / 2);
    my_putchar('\n');
}
