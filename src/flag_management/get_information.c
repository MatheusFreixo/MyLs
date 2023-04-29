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

void get_permissions(char *name)
{
    struct stat stats;
    stat(name, &stats);
    my_putchar((S_ISDIR(stats.st_mode) ? 'd' : '-'));
    my_putchar((S_IRUSR & stats.st_mode ? 'r' : '-'));
    my_putchar((S_IWUSR & stats.st_mode ? 'w' : '-'));
    my_putchar((S_IXUSR & stats.st_mode ? 'x' : '-'));
    my_putchar((S_IRGRP & stats.st_mode ? 'r' : '-'));
    my_putchar((S_IWGRP & stats.st_mode ? 'w' : '-'));
    my_putchar((S_IXGRP & stats.st_mode ? 'x' : '-'));
    my_putchar((S_IROTH & stats.st_mode ? 'r' : '-'));
    my_putchar((S_IWOTH & stats.st_mode ? 'w' : '-'));
    if (S_ISVTX & stats.st_mode)
        my_putchar('T');
    else
        my_putchar((S_IXOTH & stats.st_mode ? 'x' : '-'));
    my_putstr(". ");
}

void get_time(char *name)
{
    struct stat stats;
    stat(name, &stats);
    my_putchar(' ');
    char *str = ctime(&stats.st_mtime);
    for (int i = 0; str[i] != '\0'; i++){
        if (i == 0 || i == 1 || i == 2 || i == 3 || (i == 7 && str[i] != ' '))
            continue;
        if (i == 16)
            break;
        my_putchar(str[i]);
    }
    my_putchar(' ');
}

void get_nlink(char *name)
{
    struct stat stats;
    stat(name, &stats);
    my_put_nbr(stats.st_nlink);
    my_putchar(' ');
}

void get_gr_usr(char *name, char flag)
{
    struct stat stats;
    stat(name, &stats);
    my_duoputstr(getpwuid(stats.st_uid)->pw_name, " ");

    if (flag == 'l')
        my_duoputstr(getgrgid(stats.st_gid)->gr_name, " ");
}

void get_size(char *name)
{
    struct stat stats;
    stat(name, &stats);
    my_put_nbr(stats.st_size);
}
