/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_getnbr_modified
*/

int my_getnbr_modified(char c)
{
    int n = 0;
    if (c >= 'A' && c <= 'H'){
        n = n + c - 64;
        n = n * 10;
    }
    if (c >= '1' && c <= '8'){
        n = n + c - 47;
        n = n * 10;
    }
    n = n / 10;

    return (n);
}

int my_getnbr(char *str)
{
    int n = 0;
    for (int index = 0; str[index] != '\0'; index++){
        n = n + str[index] - 48;
        n = n * 10;
    }
    n = n / 10;
    if (str[0] == '-')
        return (-1 * n);

    return (n);
}
