/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** ...
*/

#ifndef MY_LS_H_
    #define MY_LS_H_

    #include <dirent.h>
    #include <stdarg.h>

typedef struct my_ls {
    struct dirent *dr;
    DIR *dir;
    char **arg;
    int size;
    int count;
}   my_ls_t;

typedef struct flag {
    char character;
    int (*pt)(va_list *);
} flag_t;

int flag_management(my_ls_t ls);

void flag_a(my_ls_t ls);

void flag_d(my_ls_t ls);

int flag_l(my_ls_t ls);

void flag_o(my_ls_t ls);

int flag_recursive(my_ls_t ls);

void get_permissions(char *name);

void get_time(char *name);

void get_nlink(char *name);

void get_gr_usr(char *name, char flag);

void get_size(char *name);

int list_normal(my_ls_t ls);

int error_message(struct stat stats, char *name);

int error_message_r(struct stat stats, char *name);

int check_access_r(char *name);

int error_message_empty(struct stat stats, char *name);

void print_all_file_info(my_ls_t ls, int i);

void print_name_dir_file(my_ls_t ls, int i);

void print_total(my_ls_t ls, char *name);

void usage(void);

#endif
