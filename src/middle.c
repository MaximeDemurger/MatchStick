/*
** EPITECH PROJECT, 2019
** test_pyramid
** File description:
** middle.c
*/

#include <stddef.h>
#include <stdlib.h>

char defineChar(int i, int col_size, int first_line, char const *last_one)
{
    if ((first_line == 0 && i == col_size / 2) || (first_line > 0 &&
    last_one[i + 1] == '|') || last_one[i] == '|' || last_one[i - 1] == '|')
        return '|';
    else
        return ' ';
}

char *middle(int col_size, char const *last_one)
{
    char *str = malloc(sizeof(char) * (col_size));
    int i = 0;
    static int first_line = 0;

    if (str == NULL)
        return NULL;
    while (i < col_size) {
        if (i == 0 || i == col_size - 1)
            str[i] = '*';
        else
            str[i] = defineChar(i, col_size, first_line, last_one);
        i++;
    }
    str[i] = '\0';
    first_line++;
    return str;
}