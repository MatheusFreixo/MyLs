/*
** EPITECH PROJECT, 2022
** Task 03
** File description:
** split_string
*/

#include <stdio.h>
#include <stdlib.h>
#include "./../../include/my.h"

void auxiliar(char **arr, char const *str, int words, char c)
{
    int letters = my_strlen(str);
    arr[words] = malloc(sizeof(char) * letters + 1);
    letters = 0;
    words = 0;
    for (int index = 0; str[index] != '\0'; index++){
        if (str[index] == c){
            arr[words][letters] = '\0';
            letters = 0;
            words++;
        }else {
            arr[words][letters] = str[index];
            letters++;
        }
    }
    arr[words][letters] = '\0';
}

char **my_str_to_word_array(char const *str, char c)
{
    int count_word = 1;
    for (int index = 0; str[index] != '\0'; index++){
        if (str[index] == c)
            count_word++;
    }char **arr = malloc(sizeof(char*) * (count_word + 1));
    arr[count_word] = NULL;
    int letters = 0, words = 0;
    for (int index = 0; str[index] != '\0'; index++){
        if (str[index] == c){
            arr[words] = malloc(sizeof(char) * letters + 1);
            words++;
            letters = 0;
        }else
            letters++;
    }
    auxiliar(arr, str, words, c);
    return (arr);
}
