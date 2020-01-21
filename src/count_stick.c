/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** count_stick.c
*/

#include <stddef.h>
#include <stdio.h>
#include "matchstick.h"

int check_all_stick(int maxStick, game_t *game, int size, char *line)
{
    if (my_str_isnum(line) == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        select_line(size, game);
    }
    game->stick_taken = my_atoi(modify_str(line));
    if (game->stick_taken > maxStick || game->stick_taken < 1) {
        my_printf("Error: you cannot remove more than %d matches per "
                  "turn\n", maxStick);
        select_line(size, game);
    }
    return 0;
}

int check_stick(int maxStick, int size, game_t *game)
{
    char *line = NULL;
    size_t size_line = 0;
    int get_line = 0;

    game->stick_taken = 0;
    my_putstr("Matches: ");
    while ((get_line = getline(&line, &size_line, stdin)) > 0) {
        if (get_line < 0)
            return 1;
        check_all_stick(maxStick, game, size, line);
        return 0;
    }
    return 1;
}