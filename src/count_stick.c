/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** count_stick.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "matchstick.h"

int check_stick(int stick_taken)
{
    char *line = NULL;
    size_t size_line = 0;
    int chose = 0;

    my_putstr("Matches: ");
    while (getline(&line, &size_line, stdin) > 0) {
        if (my_str_isnum(line) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            freeing_recursive(line, stick_taken);
        }
        if (!(chose = my_atoi(modify_str(line))))
            return -1;
        if (chose > stick_taken || chose < 1) {
            my_printf("Error: you cannot remove more than %d matches per "
                      "turn\n", stick_taken);
            freeing_recursive(line, stick_taken);
        } else {
            free(line);
            return chose;
        }
    }
    return 0;
}