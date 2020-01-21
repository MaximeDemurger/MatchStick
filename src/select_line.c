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

int select_line(int size, int maxStick, game_t *game, char **tab)
{
    char *line = NULL;
    size_t size_line = 0;
    int chose = 0;

    game->line = 0;
    my_putstr("Line: ");
    free(line);
    while (getline(&line, &size_line, stdin) > 0) {
        if (my_str_isnum(line) == 1) {
            my_printf("Error: invalid input (positive number expected)\n");
            playing(game, size, maxStick, tab);
        }
        chose = my_atoi(modify_str(line));
        if (chose > size || chose < 1) {
            my_putstr("Error: this line is out of range\n");
            playing(game, size, maxStick, tab);
        }
        printf("choose line %d\n", chose);
        return chose;
    }
    return 0;
}