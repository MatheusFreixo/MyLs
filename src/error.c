/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** error
*/

#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "../include/my.h"
#include "../include/my_ls.h"

int check_access_r(char *name)
{
    bool find = false;
    struct stat stats;
    for (int i = 0; i < my_strlen(name); i++){
        if (name[i] == '/' && name[i + 1] != '\0'){
            find = true;

            break;
        }
    }
    if (find == true){
        stat(name, &stats);
        if (!(S_IRUSR & stats.st_mode) && S_ISDIR(stats.st_mode)){
            my_duoputstr("my_ls: cannot access '", name);
            my_putstr("': Permission denied");
            return (84);
        }
    }
    return (0);
}

int check_access(char *name)
{
    bool find = false;
    char **str = NULL;
    struct stat s;
    for (int i = 0; i < my_strlen(name); i++){
        if (name[i] == '/' && name[i + 1] != '\0'){
            find = true;
            break;
        }
    }

    if (find == true){
        str = my_str_to_word_array(name, '/');
        stat(str[0], &s);
        if (!(S_IRUSR & s.st_mode) && S_ISDIR(s.st_mode)){
            my_duoputstr("my_ls: cannot access '", name);
            my_putstr("': Permission denied\n");
            return (84);
        }
    }
    return (0);
}

int error_message(struct stat stats, char *name)
{
    DIR *dir = opendir(name);
    if (check_access(name) == 84)
        return (84);
    if (!(S_IRUSR & stats.st_mode) && S_ISDIR(stats.st_mode)){
        my_duoputstr("my_ls: cannot open directory '", name);
        my_putstr("': Permission denied\n");
        return (84);
    }
    if (!(S_ISDIR(stats.st_mode) || S_ISREG(stats.st_mode)) ||
    (!dir && !S_ISREG(stats.st_mode))){
        my_duoputstr("my_ls: cannot access '", name);
        my_putstr("': No such file or directory\n");
        return (84);
    }
    return (0);
}

int error_message_r(struct stat stats, char *name)
{
    DIR *dir = opendir(name);
    if (check_access(name) == 84)
        return (84);
    if (!(S_IRUSR & stats.st_mode) && S_ISDIR(stats.st_mode)){
        my_duoputstr("my_ls: cannot open directory '", name);
        my_putstr("': Permission denied");
        return (84);
    }
    if (!(S_ISDIR(stats.st_mode) || S_ISREG(stats.st_mode)) ||
    (!dir && !S_ISREG(stats.st_mode))){
        my_duoputstr("my_ls: cannot access '", name);
        my_putstr("': No such file or directory");
        return (84);
    }
    return (0);
}

int error_message_empty(struct stat stats, char *name)
{
    DIR *dir = opendir(name);
    if (check_access_r(name) == 84)
        return (84);
    if (!(S_IRUSR & stats.st_mode) && S_ISDIR(stats.st_mode)){
        my_duoputstr("my_ls: cannot open directory '", name);
        my_putstr("': Permission denied");
        return (84);
    }
    return (0);
}
