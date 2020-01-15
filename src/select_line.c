/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** select_line.c
*/

#include <stddef.h>
#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>

void freeing_recursive(char *line, int size)
{
    free(line);
    select_line(size);
}

long int select_line(int size)
{
    char *line = NULL;
    size_t size_line;
    long int chose = 0;

    my_putstr("Line: ");
    while (getline(&line, &size_line, stdin) > 0) {
        if (my_str_isnum(line) == 1) {
            my_printf("Error: invalid input (positive number expected)\n");
            freeing_recursive(line, size);
        }
        if (!(chose = my_atoi(modify_str(line))))
            return -1;
        if (chose > size || chose < 1) {
            my_putstr("Error: this line is out of range\n");
            freeing_recursive(line, size);
        } else {
            free(line);
            return chose;
        }
    }
    return 0;
}