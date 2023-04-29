/*
** EPITECH PROJECT, 2022
** MY.H
** File description:
** ...
*/
#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char *str);

int my_duoputstr(char *str, char *c);

char *my_strcat(char *dest, const char *src);

char **my_str_to_word_array(char const *str, char c);

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

int my_getnbr(char *str);

int my_getnbr_modified(char c);

int my_strcmp(char const *s1, char const *s2);

char *readfile(char *filepath);

char *read_player_map(char *filepath);

int writefile(char **arr, char *filepath);

int wr_atk_file(char *bf);

char *rd_atk_file(void);

char **change_map_file(char *filepath, int r, int c, char a);

int wr_new_map_file(char *filepath, int r, int c, char a);

#endif
