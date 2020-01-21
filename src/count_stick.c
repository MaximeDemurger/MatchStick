/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** count_stick.c
*/

#include <stddef.h>
#include <stdio.h>
#include "matchstick.h"

int check_stick(int maxStick, int size, game_t *game, char **tab)
{
    char *line = NULL;
    size_t size_line = 0;
    int chose = 0;

    game->stick_taken = 0;
    my_putstr("Matches: ");
    free(line);
    while (getline(&line, &size_line, stdin) > 0) {
        if (my_str_isnum(line) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            playing(game, size, maxStick, tab);
        }
        chose = my_atoi(modify_str(line));
        if (chose > maxStick || chose < 1) {
            my_printf("Error: you cannot remove more than %d matches per "
                      "turn\n", maxStick);
            playing(game, size, maxStick, tab);
        }
        printf("choose %d\n", chose);
        return chose;
    }
    return 0;
}