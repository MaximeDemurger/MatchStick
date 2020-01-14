/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_str_isNum.c
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i++] != '\0');
    return i - 1;
}

int my_str_isNum(char const *str)
{
    int i = 0;
    int size = my_strlen(str) - 1;

    if (str == NULL)
        return 84;
    while (i < size) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}