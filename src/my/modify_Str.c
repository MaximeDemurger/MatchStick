/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** modify_str.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *modify_str(char *str)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\n') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}