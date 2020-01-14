/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int str_length = 0;

    if (str == NULL)
        return 84;
    str_length = my_strlen(str);
    if (!(write(1, str, str_length)))
        return 84;
    return 0;
}

